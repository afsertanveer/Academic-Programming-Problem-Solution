#include<stdio.h>
#include<stdlib.h>
#define size 5
struct queue
{
    int head,tail;
    int q[size];
    queue()
    {
        head=0;
        tail=0;
    }
    int deq()
    {
        int temp=q[head++];
        head=head%size;
        return temp;
    }
    int enq(int v)
    {
        q[tail++]=v;
        tail=tail%size;
    }
    bool isempty()
    {
        if(head==tail)return true;
        else return false;
    }
    bool isfull()
    {
        if((tail+1)%size==head)return true;
        else return false;
    }
};
int main()
{

}
