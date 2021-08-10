#include<stdio.h>
#include<stdlib.h>



void count_sort(){
    
    
    int arr[] = {3, 3, 6, 2, 7, 2, 7, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max=-32768;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    int c[max+1];
    for(int i=0;i<=max;i++){
        c[i]=0;
    }

    for(int i=0;i<n;i++){
        c[arr[i]]+=1;
    }
    int i=0;
    int j=0;
    while(i<=max+1){
        if(c[i]){
            arr[j++]=c[i];
            c[i]-=1;
        }
        else{
            i+=1;
        }
    }


    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        printf("\n");
    }

}

void main()
{
    
    count_sort();
}