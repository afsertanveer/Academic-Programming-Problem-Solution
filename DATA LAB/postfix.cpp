#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int head;
    int s[100];
    stack()
    {
        head=0;
    }
    int pop()
    {
        return s[--head];
    }
    void push(int e)
    {
        s[head]=e;
        head++;
    }
    int operate(int f,int s,char a)
    {
        int c;
        if(a=='+')c=f+s;
        if(a=='-')c=f-s;
        if(a=='*')c=f*s;
        if(a=='/')c=f/s;
        return c;
    }
};
int main()
{
    int i,b,f,s;
    stack ob;
    char a[100];
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!='+'&& a[i]!='-'&& a[i]!='*'&& a[i]!='/')
        {
            b=a[i]-48;
            ob.push(b);
        }
        else
        {
            s=ob.pop();
            f=ob.pop();
            ob.push(ob.operate(f,s,a[i]));
        }
    }
    printf("\nResult: %d \n",ob.pop());
}
