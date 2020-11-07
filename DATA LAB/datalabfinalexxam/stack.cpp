#include<stdio.h>
#include<string.h>
struct stack
{
    int head;
    int a[100];
    stack()
    {
        head=0;
    }
    int push(int value)
    {
        a[head]=value;
        head++;
        return a[head];
    }
    int pop()
    {
        return a[--head];
    }
    int top()
    {
        return a[head-1];
    }


    int operate(int a,int b,char c)
    {
        int r;
        if(c=='+')
        {
            r=a+b;
        }
        if(c=='-')
        {
            r=a-b;
        }
        if(c=='*')
        {
            r=a*b;
        }
        if(c=='/')
       {
        r=a/b;
       }
       return r;
    }
};
int main()
{
    stack ob;
    int a,b,c,d,e,i;
    char ch[100];
    while(1){
    gets(ch);
    for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]!='+' && ch[i]!='-' && ch[i]!='*' && ch[i]!='/')
        {
            a=ch[i]-48;
            ob.push(a);
        }
        else
        {
            c=ob.pop();
            d=ob.pop();
            ob.push(ob.operate(d,c,ch[i]));
        }

    }
     printf("Result %d\n",ob.pop());
}

}
