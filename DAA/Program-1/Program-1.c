#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int N;

int MergeSort(int[], int);
int Merge(int[], int, int[], int, int[]);

int main()
{
    int n,i,ch,a[N],x;
    printf("Enter choice: 1.Correctness 2.Complexity - ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            printf("Enter the size of array: ");
            scanf("%d",&n);
            N=n;
            printf("Enter %d array elements -\n",n);
            for(i=0;i<n;i++)
                scanf("%d",&a[i]);
            x = MergeSort(a,n);
            printf("Sorted array is:\n");
            for(i=0;i<n;i++)
                printf("%d ",a[i]);
            //printf("\n%d\n",x);
            break;
        }
        case 2:
        {
            int arr[32000],size,i,j,t1,t2,t3;
            float ln;
            printf("Enter size of array for complexity calculation of array of its next 5 multiples: ");
            scanf("%d",&size);
            printf("Size\tAscending\tcnlog(n)\tDescending\tcnlog(n)\tRandom\tcnlog(n)\n");
            for(i=1;i<=5;i++,size*=2)
            {
                N=size;
                ln=2*size*log(size)/log(2);
                //printf("Entered\n");
                for(j=0;j<size;j++)
                    arr[j]=j;
                t1=MergeSort(arr,size);
                //printf("t1=%d\n",t1);
                for(j=0;j<size;j++)
                    arr[j]=size - j;
                t2=MergeSort(arr,size);
                for(j=0;j<size;j++)
                    arr[j]=rand()%32000;
                t3=MergeSort(arr,size);
                printf("%d\t%d\t\t%.0f\t\t%d\t\t%.0f\t\t%d\t%.0f\n",size,t1,ln,t2,ln,t3,ln);
               
            }
            printf("(Considering c as 2 here)\n");
            break;
        }
        default:
        {
            exit(0);
        }
    }
}

int MergeSort(int a[N], int n)
{
    if(n<=1)
        return 0;
    //printf(" n=%d ",n);
    int b[N],c[N],i,c1=0,c2=0,c3=0,count=0;
    for(i=0;i<n/2;i++,count++)
        {
            b[i]=a[i];
            //printf("a[%d] = %d\n",i,a[i]);
        }
    for(i=n/2;i<n;i++,count++)
        {
            c[i-(n/2)]=a[i];
            //printf("a[%d] = %d\n",i,a[i]);
        }
    /*for(i=0;i<n/2;i++)
        printf("a[%d] = %d, b[%d] = %d",i,a[i],i,b[i]);*/
    c1 = MergeSort(b,n/2);
    //printf("\nSlave1 returned\n");
    c2 = MergeSort(c,(n-(n/2)));
    c3 = Merge(b,n/2,c,(n-(n/2)),a);
    return count+c3+c1+c2;
   
}

int Merge(int b[N],int p,int c[N],int q,int a[N])
{
    //printf(" p+q=%d ",p+q);
    int i=0, j=0, k=0, count=0;
    while(i<p && j<q)
    {
        if(b[i]<=c[j])
            a[k++]=b[i++];
        else
            a[k++]=c[j++];
        count++;
    }
    if(i==p)
    {
        while(j<q)
        {
            a[k++]=c[j++];
            count++;
        }
    }
    else
    {
        while(i<p)
        {
            a[k++]=b[i++];
            count++;
        }
    }
    return count;
}