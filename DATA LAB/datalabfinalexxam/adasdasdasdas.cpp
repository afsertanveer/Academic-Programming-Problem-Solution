#include<string.h>
#include<stdio.h>
struct stack
{
    int head;
    char a[100];
    stack()
    {
        head=0;
    }
    char push(char c)
    {
        a[head]=c;
        head++;
        return c;
    }
    char pop()
    {
        return a[--head];
    }
    bool isempty()
    {
        if(head==0)return true;
        else return false;
    }
};
int main()
{
    char a[100][100],ch;
    stack ob;
    int i,n,m,k,j,l,x,y;
    freopen("in.txt","r",stdin);
    scanf("%d",&m);
    scanf("%d",&n);
    printf("%d %d\n",m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%c",&a[i][j]);
        }

    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c",a[i][j]);
        }
    }
    printf("\n");


}

