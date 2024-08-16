#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int horspool(char[], char[]);

int main()
{
    char t[50],p[30];
    int a,i;
    printf("Enter the text in which search is to be performed - \n");
    gets(t);
    printf("Enter the pattern to be searched - \n");
    gets(p);
    a=horspool(t,p);
    if(a==-1)
        printf("Pattern not found in given text\n");
    else
    {
        printf("Pattern found at position %d in the text\n\n",a);
        for(i=0;i<a-1;i++)
        {
            printf(" ");
        }
        printf("|");
        for(i=0;i<strlen(p);i++)
        {
            printf(" ");
        }
        printf("|\n");
        puts(t);
        //printf("\n");
    }
    return 0;
}

int horspool(char t[50], char p[30])
{
    //printf("Function\n");
    int m,n,i,k,j,s[30][2],l;
    m=strlen(p);
    n=strlen(t);
    k=0;
    for(i=0;i<m-1;i++)
    {
        for(j=0;j<k;j++)
        {
            if(p[i]==s[j][0])
            {
                s[j][1]=m-1-i;
                break;
            }
        }
        if(j==k)
        {
            s[k][0]=p[i];
            s[k][1]=m-1-i;
            k++;
        }
    }
    printf("Shift table\n");
    for(l=0;l<k;l++)
    {
        printf("%c - %d\n",s[l][0],s[l][1]);
    }
    i=m-1;
    printf("Searching\n");
    while(i<=n-1)
    {
        //printf("i=%d\n",i);
        j=0;
        while(j<=m-1 && p[m-1-j]==t[i-j])
        {
            j++;
            //printf("j=%d\t",j);
        }
        //printf("\n");
        if(j==m)
        {
            return i-m+1;
        }
        else
        {
            for(l=0;l<k;l++)
            {
                if(t[i]==s[l][0])
                {
                    i+=s[l][1];
                    break;
                }
            }
            if(l==k)
            {
                i+=m;
            }
        }
    }
    return -1;
}