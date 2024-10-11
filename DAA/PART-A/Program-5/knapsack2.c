#include<stdio.h>
#include<stdlib.h>
// capacity is taken as m
int max(int a,int b){
    return (a>b?a:b);
}
void Knapsack(int n,int m, int w[20],int V[20][20],int p[20]){
    int i,j;
    for (i=0;i<=n;i++){
        for (j=0;j<=m;j++){
            if (i==0||j==0){
                V[i][j]=0;
            }
            else if (j < w[i]){
                V[i][j]=V[i-1][j];
            }
            else{
                V[i][j]=max(V[i-1][j], p[i]+V[i-1][j-w[i]]);
            }
            printf("%d\t",V[i][j]);
        }
        printf("\n");
    }
}
void ItemsOfOptimal(int n,int m,int w[20],int V[20][20]){
    int i,j;
    if (V[n][m]==0){
        printf("Not possible!");
        return;
    }
    printf("Optimal solution is :%d\n",V[n][m]);
    i=n;
    j=m;
    printf("Objects selected: ");
    while (i!=0 && j!=0){
        if (V[i][j]!=V[i-1][j]){
            printf("\n%d",i);
            j=j-w[i];
        }
        i=i-1;
    }
    printf("\n");
}

int main(){
    int m,n,i,j,p[20],w[20],v[20][20];
    printf("Enter no. of objects:");
    scanf("%d",&n);
    printf("Enter weight of %d objects:",n);
    for (i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("Enter Profits/values:");
    for (i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("Enter capacity:");
    scanf("%d",&m);
    Knapsack(n,m,w,v,p);
    ItemsOfOptimal(n,m,w,v);
}
