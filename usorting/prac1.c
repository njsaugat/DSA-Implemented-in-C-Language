#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition()
{
    int arr[] = {43, 34, 66, 32, 87, 23, 76, 23, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0;
    int h = n - 1;


    int i = l;
    int j = h;
    int pivot = arr[l];
    while (i < j)
    {
        while (pivot >= arr[i])
        {
            i++;
        }
        while (pivot < arr[j])
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[l]);
    return j;
}


void main(){
    partition();
}