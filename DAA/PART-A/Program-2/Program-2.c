#include<stdio.h>    /*Testing needed*/
#include<stdlib.h>

int V,E,t[50],l=0;    

void driver(int[][2]);
void dfs(int, int[], int[][2]);

int main() {
    int i,j;
    printf("Topological sorting for DIRECTED ACYCLIC GRAPH using DFS method\n");
    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    printf("Enter the number of edges: ");
    scanf("%d",&E);
    int a[E][2];
    printf("Enter %d pair of edges - \n",E);
    for(i=0;i<E;i++) {
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(i=0; i<E-1; i++) {
        for(j=i+1;j<E;j++) {
            if((a[i][0] == a[j][0])&&(a[i][1]==a[j][1]) ) {
                printf("WRONG INPUT! Cannot enter repeated edges, try again. . .\n");
                exit(0);
            }
            if((0>a[i][0] || a[i][0]>=V) || (0>a[i][1] || a[i][1]>=V) || (0>a[E-1][0] || a[E-1][0]>=V) || (0>a[E-1][1] || a[E-1][1]>=V)) {
                printf("WRONG INPUT! Edges having invalid vertex reference . . .\n");
                exit(0);
            }
            /*if(a[i][0]==a[j][1]) {
                printf("WRONG INPUT! Graph should not contain any cycle . . .\n");
                exit(0);
            }*/
        }
    }
    printf("Vertices: ");
    for(i=0;i<V;i++)
        printf("%d  ",i);
    printf("\nEdges:\n");
    for(i=0;i<E;i++)
        printf("%d -> %d\n",a[i][0],a[i][1]);
    printf("The topological order is:\n");
    driver(a);
    return 0;
}

void driver(int a[E][2]) {    
    int i,j,k,flag=-1,visit[50];
    for(i=0;i<V;i++)
        visit[i]=0;
    for(k=0;k<V;k++) {
        for(i=0;i<V;i++) {
            flag=0;
            for(j=0;j<E;j++) {
                if(a[j][1]==i) {
                    flag=1;
                }
            }
            if(flag==0 && visit[i]==0) {
                dfs(i,visit,a);
                t[l++]=i;
            }
        }
    }
    if(flag==-1) {
        printf("Given graph doesn't have any vertex with in-degree 0\n");
        return;
    }
    else {
        for(i=V-1;i>=0;i--)
        printf("%d  ",t[i]);
    }
}

void dfs(int i, int visit[V], int a[E][2]) {
    int j;
    visit[i]=1;
    for(j=0;j<E;j++) {
        if(a[j][0]==i && visit[a[j][1]]==0) {
            dfs(a[j][1], visit, a);
                t[l++]=a[j][1];
            }
       
    }
}
