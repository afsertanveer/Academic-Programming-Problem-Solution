#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int head;
    char a[100];
    stack()
    {
        head=0;
    }
    void push(char c)
    {
        a[head]=c;
        head++;
        printf("%c\n",c);
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
    int i,n,m,k,c=1,b=1,j,l,x,y;
    freopen("in.txt","r",stdin);
    scanf("%d",&m);
    scanf("%d",&n);
    printf("%d %d\n",m,n);
    for(i=0;i<=m;i++)
    {
        gets(a[i]);
    }
    for(i=1;i<=m;i++)
    {
        puts(a[i]);
    }
    printf("\n");
    for(i=1;i<=m;i++)
    {
        for(j=0;a[i][j]!='\0';j++)
        {

                if(a[i][j]=='S')
            {
                x=i;
                y=j;
            }

        }
    }
}
