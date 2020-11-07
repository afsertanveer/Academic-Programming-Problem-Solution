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
        printf("Blade Found : %c\n",c);
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

       while(1){

        if(a[x+1][y]=='A' || a[x+1][y]=='B' || a[x+1][y]=='C')
         {
            x=x+1;
            ob.push(a[x][y]);
            a[x][y]='X';
            printf("%d %d \n",x,y);
         }
      else if(a[x-1][y]=='A' || a[x-1][y]=='B' || a[x-1][y]=='C')
         {
             x=x-1;
            ob.push(a[x][y]);
            a[x][y]='X';
        }

       else if(a[x][y+1]=='A' || a[x][y+1]=='B' || a[x][y+1]=='C')
         {
             y=y+1;
             ob.push(a[x][y]);
             a[x][y]='X';

         }

       else if(a[x][y-1]=='A' || a[x][y-1]=='B' || a[x][y-1]=='C')
         {
             y=y-1;
             ob.push(a[x][y]);
             a[x][y]='X';
         }

      else if(a[x+1][y]=='.' )
        {
            ++x;
            a[x][y]='X';
        }
      else if(a[x-1][y]=='.'  )
        {
            --x;
            a[x][y]='X';
        }
      else  if(a[x][y+1]=='.' )
        {
            ++y;
            a[x][y]='X';
        }
      else  if(a[x][y-1]=='.' )
        {
            --y;
            a[x][y]='X';
        }
       else if(a[x+1][y]=='M')
        {
            x=x+1;
            if(ob.pop()=='A')
            {
                printf("Enemey M is killed by A\n");
            }
            else
            {
                printf("You are killed by enemey M\nGame over\n");
                break;

            }
            a[x][y]='X';
        }

       else if(a[x-1][y]=='M')
        {
            x=x-1;
            if(ob.pop()=='A')
            {
                printf("Enemey M is killed by A\n");
            }
            else
            {
                printf("You are killed by enemey M\nGame over\n");
                break;

            }
            a[x][y]='X';
        }
        else if(a[x][y+1]=='M')
        {
            y=y+1;
            if(ob.pop()=='A')
            {
                printf("Enemey M is killed by A\n");
            }
            else
            {
                printf("You are killed by enemey M\nGame over\n");
                break;

            }
            a[x][y]='X';
        }
        else if(a[x][y-1]=='M')
        {
            y=y-1;
            if(ob.pop()=='A')
            {
                printf("Enemey M is killed by A\n");
            }
            else
            {
                printf("You are killed by enemey M\nGame over\n");
                break;

            }
            a[x][y]='X';
        }
         else if(a[x+1][y]=='N')
        {
            x=x+1;
            if(ob.pop()=='B')
            {
                printf("Enemey N is killed by B\n");
            }
            else
            {
                printf("You are killed by enemey N\nGame over\n");
                break;

            }
            a[x][y]='X';
        }

       else if(a[x-1][y]=='N')
        {
            x=x-1;
            if(ob.pop()=='B')
            {
                printf("Enemey N is killed by B\n");
            }
            else
            {
                printf("You are killed by enemey N\nGame over\n");
                break;

            }
            a[x][y]='X';
        }
        else if(a[x][y+1]=='N')
        {
            y=y+1;
            if(ob.pop()=='B')
            {
                printf("Enemey N is killed by B\n");
            }
            else
            {
                printf("You are killed by enemey N\nGame over\n");
                break;

            }
            a[x][y]='X';
        }
        else if(a[x][y-1]=='N')
        {
            y=y-1;
            if(ob.pop()=='B')
            {
                printf("Enemey N is killed by B\n");
            }
            else
            {
                printf("You are killed by enemey N\nGame over\n");
                break;

            }
            a[x][y]='X';
        }
          else if(a[x+1][y]=='O')
        {
            x=x+1;
            if(ob.pop()=='C')
            {
                printf("Enemey O is killed by C\n");
            }
            else
            {
                printf("You are killed by enemey O\nGame over\n");
                break;

            }
            a[x][y]='X';
        }

       else if(a[x-1][y]=='O')
        {
            x=x-1;
            if(ob.pop()=='C')
            {
                printf("Enemey O is killed by C\n");
            }
            else
            {
                printf("You are killed by enemey O\nGame over\n");
                break;

            }
            a[x][y]='X';
        }
        else if(a[x][y+1]=='O')
        {
            y=y+1;
            if(ob.pop()=='C')
            {
                printf("Enemey O is killed by C\n");
            }
            else
            {
                printf("You are killed by enemey O\nGame over\n");
                break;

            }
            a[x][y]='X';
        }
        else if(a[x][y-1]=='O')
        {
            y=y-1;
            if(ob.pop()=='C')
            {
                printf("Enemey O is killed by C\n");
            }
            else
            {
                printf("You are killed by enemey O\nGame over\n");
                break;

            }
            a[x][y]='X';
        }

       else if(a[x+1][y]=='E' || a[x-1][y]=='E' || a[x][y+1]=='E' || a[x][y-1]=='E')
        {
            printf("Game is completed\n");
            break;


        }

    }
}

