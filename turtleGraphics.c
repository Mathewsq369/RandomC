#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
enum STATUS { UP, DOWN };
enum SIDE { RIGHT, LEFT };
void sketchPattern(int flr[][SIZE], size_t size, char inst[]);
void draw(int flr[][SIZE], size_t size);
void forward(int flr[][SIZE], size_t size, size_t index, enum SIDE side);
size_t right(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);
size_t left(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);
size_t up(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);
size_t down(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);
//size_t diagUp(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);
//size_t diagDown(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);

int main(void)
{
    char instructions[SIZE + 1] = {'6'};
    int floor[SIZE][SIZE] = {0};

    draw(floor, SIZE);
}

void sketchPattern(int flr[][SIZE], size_t size, char inst[])
{
    static enum STATUS pen = UP;
    enum SIDE side = RIGHT;
    for (size_t i = 0; i < size; i++)
    {
        if (inst[i] == '1')
        {
            pen = UP;
        }
        else if (inst[i] == '2')
        {
            pen = DOWN;
        }
        else if(inst[i] == '3')
        {
            side = RIGHT;
        }
        else if (inst[i] == '4')
        {
            side = LEFT;
        }
        else if (inst[i] == '5')
        {
            if (inst[i + 1] == ',')
            {
                forward(flr,size,inst[i + 2] - '0',side);
            }

        }
        else if (inst[i] == '6')
        {
            draw(flr,size);
        }
        else if(inst[i] == '9')
        {
            //end of data;
        }
    }
}

void draw(int flr[][SIZE],size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            printf("%d",flr[i][j]);
            //if (flr[i][j] == 0)
            //{
                //printf(" ");
            //}
            //else if (flr[i][j] == 1)
            //{
                //printf("*");
            //}
        }
        puts("");
    }
}

void forward(int flr[][SIZE], size_t size, size_t index, enum SIDE side)
{
    // use while loops for the assignment
    static size_t progressRow = 0;
    static size_t progressColumn = 0;
    static int how = 1;
    static int how_l = 1;

    if (side == RIGHT)
    {

        if (how % 4 == 0)
        {
            progressColumn = up(flr,size,index,progressRow,progressColumn);
        }
        else if (how % 3 == 0)
        {
            progressRow = left(flr,size,index,progressRow,progressColumn);
        }
        else if (how % 2 == 0)
        {
            progressColumn = down(flr,size,index,progressRow,progressColumn);
        }
        else
        {
            progressRow = right(flr,size,index,progressRow,progressColumn);
        }
        how++;
    }
    else if (side == LEFT)
    {
        if (how_l % 4 == 0)
        {
            progressColumn = up(flr,size,index,progressRow,progressColumn);
        }
        else if (how_l % 3 == 0)
        {
            progressRow = right(flr,size,index,progressRow,progressColumn);
        }
        else if (how_l % 2 == 0)
        {
            progressColumn = down(flr,size,index,progressRow,progressColumn);
        }
        else
        {
            progressRow = left(flr,size,index,progressRow,progressColumn);
        }
        how_l++;
    }
}

size_t right(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn)
{
    while (index > 0 && progressRow != SIZE - 1)
    {
        flr[progressRow][progressColumn] = 1;
        progressRow++;
        index--;
    }
    return progressRow;
}

size_t left(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn)
{
    while (index > 0 && progressRow >= 0)
    {
        flr[progressRow][progressColumn] = 1;
        progressRow--;
        index--;
    }
    return progressRow;
}

size_t up(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn)
{
    while (index > 0 && progressColumn >= 0)
    {
        flr[progressRow][progressColumn] = 1;
        progressColumn--;
        index--;
    }
    return progressColumn;
}

size_t down(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn)
{
    while (index > 0 && progressColumn != SIZE - 1)
    {
        flr[progressRow][progressColumn] = 1;
        progressColumn++;
        index--;
    }
    return progressColumn;
}