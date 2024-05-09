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
}

void printArray(int a[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%3d",a[i]);
    }
    puts("");
}