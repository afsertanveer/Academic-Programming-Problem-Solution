#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack
{
    int head;
    int s[SIZE];
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
    bool isempty()
    {
        if(head==0)return true;
        else return false;
    }
    bool isfull()
    {
        if(head==SIZE)return true;
        else return false;
    }
    int top()
    {
        return s[head-1];
    }
    int noele()
    {
        return head;
    }

};
int main()
{
    stack ob,ob1;
    int a,max,i,c;
    while(ob.isfull()==false)
    {
        scanf("%d",&a);
        ob.push(a);
    }
    max=ob.top();
    while(ob.isempty()==false)
    {
        if(ob.pop()>max)
        {
            max=ob.pop();
        }
    }
    printf("%d is the maximum value in the stack\n",max);
}
