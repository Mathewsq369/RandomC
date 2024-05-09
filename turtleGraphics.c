#include <stdio.h>
#define SIZE 50
enum STATUS { UP, DOWN};
int pattern(int flr[][],char inst[],size_t size);
int draw(int flr[][],size_t size);

int main(void)
{
    char instructions[SIZE ++ 1] = {'0'};
    int floor[SIZE][SIZE] = {0};

    pattern(floor,instructions,SIZE);
    draw(floor,SIZE);
}

int pattern(int flr[][],char inst[],size_t size)
{
    size_t track = 0;
    size_t limit = 0;
    size_t count = 0;
    enum STATUS pen = UP;
    
    while (count < size)
    {
        if (inst[count] == '1')
        {
            pen = UP;
        }
        else if (inst[count] == '2')
        {
            pen = DOWN;
        }

        if (inst[count] == '3')
        {
            index = right;
        }
        else if (inst[count] == '4')
        {
            index = left;
        }
        else if (inst[count] == '5,10')
        {
            index = forward 10;
        }
        else if(inst[count] == '6')
        {
            index = print;
        }
        else if (inst[count] == '9')
        {
            index = terminate;
        }
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < limit; j++)
            {
            }
        }
        count++;
    }
}

int draw(int flr[][],size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (flr[i][j] == 0)
            {
                printf(" ");
            }
            else if (flr[i][j] == 1)
            {
                printf("*");
            }
        }
        puts("");
    }
}