#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 100

int quickSort(int[], int, int);
int *partition(int[], int, int);
void swap(int*, int*);

int main(){
    int n, i, ch, x;
    printf("Enter choice: 1.Correctness 2.Complexity -\n");
    scanf("%d", &ch);
    switch(ch){
        case 1:{
            printf("Enter the size of the array: ");
            scanf("%d", &n);
            int a[n];
            printf("Enter the %d array elements: \n", n);
            for(i=0; i<n; i++)
                scanf("%d", &a[i]);
            x = quickSort(a, 0, n-1);
            printf("Sorted array is: \n");
            for(i=0; i<n; i++)
                printf("%d ", a[i]);
            break;
        }
        case 2:{
            int arr[32000], size, i, j, t1, t2, t3;
            float ln;
            printf("Enter the initial size of the array for complexity calculation of its next 5 multiples: ");
            scanf("%d", &size);
            printf("Size\tAscending\tn*n\tDescending\tn*n\tRandom\t3nlog(n)\n");
            for(i=1; i<=5; i++, size*=2){
                ln = 3*size*log(size)/log(2);
                for(j=0; j<size; j++)
                    arr[j] = j;
                t1 = quickSort(arr, 0, size-1);
                for(j=0; j<size; j++)
                    arr[j] = size - j;
                t2 = quickSort(arr, 0, size-1);
                for(j=0; j<size; j++)
                    arr[j] = rand()%32000;
                t3 = quickSort(arr, 0, size-1);
                printf("%d\t%d\t\t%d\t\t%d\t\t%d\t%d\t%.0f\n", size, t1, size*size, t2, size*size, t3, ln);
            }
            break;
        }
        default:
            exit(0);
    }
    return 0;
}

int quickSort(int a[N], int l, int r){
    if(r<=l || r<0 || l<0)
        return 0;
    int s, c1=0, c2=0, count=0, *c;
    c = partition(a, l, r);
    s = c[0];
    count = c[1];
    c1 = quickSort(a, l, s-1);
    c2 = quickSort(a, l+1, r);
    return count+c1+c2;
}

int *partition(int a[N], int l, int r){
    int i, j, k=0, count=0, pivot;
    int *c = (int *)malloc(sizeof(int)*2);
    pivot = a[l];
    i = l+1;
    j = r;
    do{
        while(a[i]<pivot){
            if((i+1)>r)
                break;
            i++;
            count++;
        }
        while(a[j] > pivot){
            j--;
            count++;
        }
        swap(&a[i], &a[j]);
    }while(i<j && i<=r);
    swap(&a[i], &a[j]);
    swap(&a[l], &a[j]);
    c[0] = j;
    c[1] = count;
    return c;
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}