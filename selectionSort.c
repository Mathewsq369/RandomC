#include <stdio.h>

#define SIZE 10
void sort(int a[], int size);
void printArray(int a[],int size);

int main()
{
    int arr[SIZE] = {9,0,8,1,7,2,6,3,5,4};

    printf("This program takes 10 integers and sorts them using selection sort\n");

    sort(arr,SIZE);
    printArray(arr,SIZE);
    return 0;
}

void sort(int a[], int size)
{
    int hold = 0, smallest = 0, swap = 0;

    for (size_t i = 0; i < size; i++)
    {
        swap = 0;
        hold = 0;
        smallest = i;
        for (size_t j = i; j < size; j++)
        {
            if (a[smallest] > a[j])
            {
                smallest = j;
                swap++;
            }
        }
        if(swap > 0)
        {
            hold = a[i];
            a[i] = a[smallest];
            a[smallest] = hold;
        }
    }
}

void printArray(int a[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%3d",a[i]);
    }
    puts("");
}