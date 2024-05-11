#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
enum STATUS { UP, DOWN };
enum SIDE { RIGHT, LEFT, CONTINUE};
void sketchPattern(int flr[][SIZE], size_t size, char inst[]);
void draw(int flr[][SIZE], size_t size);
void forward(int flr[][SIZE], size_t size, size_t index, enum SIDE side);
enum STATUS penStatus(int num, enum STATUS status);

int main(void)
{
    char instructions[SIZE + 1] = {'0'};
    int floor[SIZE][SIZE] = {0};

    draw(floor, SIZE);
}

void sketchPattern(int flr[][SIZE], size_t size, char inst[])
{
    enum STATUS pen = UP;
    enum SIDE side = CONTINUE;
    for (size_t i = 0; i < size; i++)
    {
        if (inst[i] == '1')
        {
            pen = penStatus(1, pen);
        }
        else if (inst[i] == '2')
        {
            pen = penStatus(2, pen);
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
                forward(flr,size,i + 2,side);
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

enum STATUS penStatus(int num, enum STATUS status)
{
    if (num == 1)
    {
        status = UP;
    }
    else if (num == 2)
    {
        status = DOWN;
    }
    return status;
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
    
}