#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000

int count;
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for(int j = low; j <= high -1; j++)
	{

		if(arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		count++;
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void quicksort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pi = partition(arr, low, high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}

int main()
{
	int arr[SIZE],X[SIZE],Y[SIZE],Z[SIZE];
	int n,i,j,c1,c2,c3;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("\nEnter the %d array elements:", n);
	for(i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	count = 0;
	quicksort(arr,0,n-1);
	printf("\nSorted array is ");
	for(i = 0; i < n;i++)
		printf("%d ", arr[i]);
	printf("\nThe basic operation executes %d times\n",count);
	printf("\nSIZE\tASC\tDESC\tRANDOM\n");
	for( i = 16; i < SIZE; i *= 2)
	{
		for( j = 0; j < i; j++)
		{
			X[j] = j;
			Y[j] = i-j-1;
			Z[j] = rand() % i;
		}
		count = 0;
		quicksort(X, 0, i-1);
		c1 = count;
		count = 0;
		quicksort(Y, 0, i-1);
		c2 = count;
		count = 0;
		quicksort(Z, 0, i-1);
		c3 = count;
		printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
	}
	return 0;
}