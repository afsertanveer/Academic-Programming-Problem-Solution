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
        int value;
        value=s[head-1];
        head--;
        return value;
    }
    void push(int e)
    {
        s[head]=e;
        head++;
    }
    int evaluate(int f,int s,char a)
    {
        int c;
        if(a=='+')c=f+s;
        else if(a=='-')c=f-s;
        else if(a=='*')c=f*s;
        else if(a=='/')c=f/s;
        return c;
    }
};
int main()
{
    stack ob;
    char a[100];
    int i,b,first,second;
    printf("Enter a postfix\n");
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
            second=ob.pop();
            first=ob.pop();
            ob.push(ob.evaluate(first,second,a[i]));
        }
    }
    printf("result:%d \n",ob.pop());
}
