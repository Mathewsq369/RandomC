#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
enum STATUS { UP, DOWN };
enum SIDE { RIGHT, LEFT, CONTINUE};
void sketchPattern (int flr[][SIZE], size_t size, char inst[]);
void draw(int flr[][SIZE], size_t size);
void forward(int flr[][SIZE], size_t size, size_t index, enum SIDE side);
void right(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);
void left(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);
void up(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);
void down(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);
//void diagUp(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);
//void diagDown(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn);

int main(void)
{
    char instructions[SIZE + 1] = {'6'};
    int floor[SIZE][SIZE] = {0};

    draw(floor, SIZE);
}

void sketchPattern(int flr[][SIZE], size_t size, char inst[])
{
    static enum STATUS pen = UP;
    enum SIDE side = CONTINUE;
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

    if (side == RIGHT)
    {

        if (how % 4 == 0)
        {
            //do this
        }
        else if (how % 3 == 0)
        {
            //do this
        }
        else if (how % 2 == 0)
        {
            //do this
        }
        else
        {
            //do this
        }
    }
    else if (side == LEFT)
    {
        if (how % 4 == 0)
        {
            //do this
        }
        else if (how % 3 == 0)
        {
            //do this
        }
        else if (how % 2 == 0)
        {
            //do this
        }
        else
        {
            //do this
        }
    }
    else
    {
        //
    }
}

void right(int flr[][SIZE], size_t size, size_t index, size_t progressRow, size_t progressColumn)
{
    //do something
}