#include<stdio.h>
#include<string.h>
struct stack
{
    int head;
    char a[100];
    stack()
    {
        head=0;
    }
    char push(char value)
    {
        a[head]=value;
        head++;
        return a[head];
    }
    char pop()
    {
        return a[--head];
    }
    char top()
    {
        return a[head-1];
    }
    bool isempty()
    {
        if(head==0)return true;
        else return false;

    }


};
int main()
{
    stack ob,ob1,ob2;
    int i;
    char ch[100],a,b,c[100];
    gets(ch);
    for(i=0;ch[i]!='\0';i++)
    {
        ob.push(ch[i]);
        c[i]=ch[i];

    }
    c[i]='\0';
    while(ob.isempty()==false)
    {
        ob1.push(ob.pop());
    }
    puts(c);
}

