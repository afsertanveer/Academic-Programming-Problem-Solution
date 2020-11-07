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

            if(a[i][j]!='X' && a[i][j]!='-')
            {
                if(a[i][j]=='S')
            {
                x=i;
                y=j;
            }
            }
        }
    }

    //printf("%d %d \n",x,y);
     while(1)
     {
         if(a[x-c][y]=='.' || a[x+c][y]=='.')
         {
             c++;
         }
         if(a[x][y-b]=='.' || a[x][y+b]=='.')
         {
             b++;
         }
         if(a[x-c][y]=='A' || a[x+c][y]=='A')
         {
             ob.push('A');
             c++;
         }

         if(a[x][y+b]=='A' || a[x][y+b]=='A' )
         {
             ob.push('A');
             b++;
         }
         if(a[x-c][y]=='B' || a[x+c][y]=='B' )
         {
             ob.push('B');
             c++;
         }

         if(a[x][y-b]=='B' || a[x][y+b]=='B' )
         {
             ob.push('B');
             b++;
         }
        if(a[x-c][y]=='C' || a[x+c][y]=='C' )
         {
             ob.push('C');
             c++;
         }

         if(a[x][y-b]=='C' || a[x][y+b]=='C' )
         {
             ob.push('C');
             b++;
         }
        if(a[x-c][y]=='M' || a[x+c][y]=='M')
         {
             if(ob.pop()=='A')
             {
                 printf("Enemy M is killed by A\n");
                 c++;
             }
             else
             {
                 printf("You are killed by enemey M\nGame Over...\n");
                 break;
             }
         }

         if(a[x][y-b]=='M' || a[x][y+b]=='M' )
         {
             if(ob.pop()=='A')
             {
                 printf("Enemy M is killed by A\n");
                 b++;
             }
             else
             {
                 printf("You are killed by enemey M\nGame Over...\n");
                 break;
             }
         }
        if(a[x-c][y]=='N' || a[x+c][y]=='N')
         {
             if(ob.pop()=='B')
             {
                 printf("Enemy N is killed by B\n");
                 c++;
             }
             else
             {
                 printf("You are killed by enemey N\nGame Over...\n");
                 break;
             }
         }

         if(a[x][y-b]=='N' || a[x][y+b]=='N' )
         {
             if(ob.pop()=='B')
             {
                 printf("Enemy N is killed by B\n");
                 b++;
             }
             else
             {
                 printf("You are killed by enemey N\nGame Over...\n");
                 break;
             }
         }
        if(a[x-c][y]=='O' || a[x+c][y]=='O')
         {
             if(ob.pop()=='C')
             {
                 printf("Enemy O is killed by C\n");
                 c++;
             }
             else
             {
                 printf("You are killed by enemey O\nGame Over...\n");
                 break;
             }
         }

         if(a[x][y-b]=='O' || a[x][y+b]=='O' )
         {
             if(ob.pop()=='C')
             {
                 printf("Enemy O is killed by C\n");
                 b++;
             }
             else
             {
                 printf("You are killed by enemey C\nGame Over...\n");
                 break;
             }
         }
         if(a[x-c][y]=='E' || a[x+c][y]=='E' || a[x][y-b]=='E' || a[x][y+b]=='E')
         {
             printf("Game is successfully completed\n");
             break;
         }
     }

}

