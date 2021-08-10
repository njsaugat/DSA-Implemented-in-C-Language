#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int l,int mid, int h)
{
    int b[100];// always make this array large enough
    // int mid = (l + h) / 2;
    int i = l;
    int k = l;
    int j = mid + 1;
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            b[k++] = arr[i++];
        }
        else //dont write the other condition;that will throw an error
        {
            b[k++] = arr[j++];
        }
    }
    for (; i <= mid; i++)
    {
        b[k++] = arr[i];
    }
    for (; j <= h; j++)
    {
        b[k++] = arr[j];
    }

    for (int i = 0; i <= h; i++)
    {
        arr[i] = b[i];
    }
}

void merge_sort(int arr[], int l, int h)
{   int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        printf("\n");
    }
}

void main()
{
    int arr[] = {43, 34, 66, 32, 7, 23, 76, 23, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0;
    int h = n - 1;
    merge_sort(arr, 0, 8);
    display(arr, n);
}