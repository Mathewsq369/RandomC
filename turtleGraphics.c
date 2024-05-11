#include <stdio.h>
#define SIZE 50
//static enum STATUS { UP, DOWN};
//static enum SIDE { RIGHT, LEFT, CONTINUE};
void sketchPattern(int flr[][SIZE], size_t size, char inst[]);
void draw(int flr[][SIZE], size_t size);

int main(void)
{
    char instructions[SIZE + 1] = {'0'};
    int floor[SIZE][SIZE] = {0};

    draw(floor, SIZE);
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