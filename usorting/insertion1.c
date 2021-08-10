#include <stdlib.h>
#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        printf("\n");
    }
}
void insertion_sort(int arr[],int n)
{   
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }j++;
        arr[j] = temp;
    }
    
}



void main()
{
    int arr[] = {43, 34, 66, 32, 87, 23, 76, 23, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    display(arr,n);
}