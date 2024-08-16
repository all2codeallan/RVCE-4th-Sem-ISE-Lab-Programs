#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "sort.h"

void main(){
    printf("Enter the number of elements\n");
    int size;
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++){
        printf("Enter element %d : \t",i+1);
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,size-1);
    int i=0;
    for(i=0;i<size-1;i++){
        if(arr[i] == arr[i+2]){
            printf("Array is not Unique\n");
            break;
        }
    }
    if(i == size-1){
        printf("Array is Unique\n");
    }
}