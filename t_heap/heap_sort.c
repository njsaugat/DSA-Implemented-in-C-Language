#include <stdio.h>
#include <stdlib.h>
// int n=5;//arr size
void heap_insert(int arr[], int key, int n)
{
    int i = n;
    while (i > 1 && arr[i / 2] < key)
    { // 1 nai ho 1st element; tyaha pugexi nth to do
        arr[i] = arr[i / 2];
        i = i / 2;
    }
    arr[i] = key;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int heap_delete(int arr[], int size)
{
    int i = 1;
    int j = 1;
    int x = arr[i];
    arr[i] = arr[size - 1];
    i = i * 2;
    while (i < size - 1)
    {
        if (arr[i + 1] > arr[i])
        {
            i++;
        }
        if (arr[i] > arr[j])
        {
            swap(&arr[i], &arr[j]);
        }
        j = i;
        i = i * 2;
    }
    arr[size - 1] = x; //copying to last position
    return x;
}

void display(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        printf("%d", arr[i]);
        printf("\n");
    }
}

void heap_sort(int arr[], int size)
{
    for (int i = 1; i <= size; i++)
    {
        heap_insert(arr, arr[i], i);
    }

    for (int i = size; i > 1; i--)
    { //euta matra baki rahyo vane ta sorted ho ni
        heap_delete(arr, i);
    }

    display(arr, size);
}

void main()
{
    int arr[] = {0, 15, 5, 10, 20, 30, 50, 60, 70, 54, 45, 543, 345, 56765, 76554, 567, 567567, 56, 756, 786767, 78};
    int size = (sizeof(arr) / sizeof(arr[0]));
    heap_sort(arr, size);
}