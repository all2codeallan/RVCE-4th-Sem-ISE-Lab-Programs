#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>                                                

#define MAX 50
#define INF 1000000

int a[MAX][2], n=0, z;

void dij(int ,int, int[], int[][3], int);
void add(int w, int v);
int delete();
void heapify();
void display();

int main()
{
    int V[MAX], E[MAX][3], s, v, e, i, j;
    printf("Input the details of the graph - \n");
    printf("Enter the number of vertices: ");
    scanf("%d",&v); 
    printf("Vertices: ");
    for(i=0;i<v;i++) 
        printf("%d  ",i);
    printf("\nEnter the number of edges: ");
    scanf("%d",&e);
    if(e>(v*(v+1)/2))
    {
        printf("\nEdges crosses maximum number. Exiting . . .\n");
        exit(0);
    }
    printf("\nEnter %d edges in the format (vertex1 vertex2 weight): \n",e);
    for(i=0;i<e;i++)
    {
        scanf("%d %d %d",&E[i][0],&E[i][1],&E[i][2]);
    }
     printf("\nEdges:\n");
    for(i=0;i<e;i++)
        printf("%d <-> %d : %d\n",E[i][0],E[i][1],E[i][2]);
    for(i=0; i<e-1; i++) {
        for(j=i+1;j<e;j++) {
            if((E[i][0] == E[j][0])&&(E[i][1]==E[j][1]) || (E[i][1] == E[j][0])&&(E[i][0]==E[j][1]) ) {
                printf("WRONG INPUT! Cannot enter repeated edges, try again. . .\n");
                exit(0);
            }
            if((0>E[i][0] || E[i][0]>=v) || (0>E[i][1] || E[i][1]>=v) || (0>E[e-1][0] || E[e-1][0]>=v) || (0>E[e-1][1] || E[e-1][1]>=v)) {
                printf("WRONG INPUT! Edges having invalid vertex reference . . .\n");
                exit(0);
            }
        }
        if(E[i][2]<0 || E[e-1][2]<0)
        {
            printf("%d Cannot enter negative weight\n",i);
            exit(0);
        }
    }
    printf("Enter the starting vertex between 0 to %d both inclusive: ",v-1);
    scanf("%d",&s);
    if(s>=v)
    {
        printf("Invalid starting vertex\n");
    }
    dij(v,e,V,E,s);
    return 0;
}

void dij(int v, int e, int V[MAX], int E[MAX][3], int s)
{
    int i,j,d[MAX],u,adj;
    for(i=0;i<v;i++)
        d[i]=INF;
    add(0,s);
    d[s]=0;
    while(n>0)
    {
        u=delete();
        for(i=0;i<e;i++)
        {
            if(E[i][0]==u) 
            {
                adj=E[i][1];
                if(d[adj] > d[u]+E[i][2])
                {
                    d[adj] = d[u]+E[i][2];
                    add(d[adj],adj);
                }
            }
            if(E[i][1]==u)
            {
                adj=E[i][0];
                if(d[adj] > d[u]+E[i][2])
                {
                    d[adj] = d[u]+E[i][2];
                    add(d[adj],adj);
                }
            }
        }
    }
    printf("Source vertex: %d\nVertices\t\t\tDistances from source\n",s);
    for(i=0;i<v;i++)
    {
        printf("%d\t\t\t\t%d\n",i,d[i]);
    }
}

void display()
{
    int i;
    if(n<1)
    {
        printf("Heap is empty\n");
        return;
    }
    printf("The heap is:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d  %d\n",a[i][0],a[i][1]);
    }
    printf("\n");
}

void add(int w, int v)
{
    n++;
    a[n][0]=w;
    a[n][1]=v;
    heapify();
}

int delete()
{
    int r = a[1][1];
    a[1][0]=a[n][0];
    a[1][1]=a[n][1];
    n--;
    heapify();
    return r;
}

void heapify()
{
    int v,u,j,k,i,flag;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k][0];
        u=a[k][1];
        flag=0;
        while(!flag && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(a[j][0]<a[j+1][0])
                {
                    j=j+1;
                }
            }
            if(v>=a[j][0])
                flag=1;
            else
            {
                a[k][0]=a[j][0];
                a[k][1]=a[j][1];
                k=j;
            }
        }
        a[k][0]=v;
        a[k][1]=u;
    }
}

