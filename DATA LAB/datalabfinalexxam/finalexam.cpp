#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int head,tail;
    int q[1000];
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

};
int main()
{
    queue q1,q2,q3;
    int i,a,b,n,max,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        q1.enq(a);
    }
    while(count<=n)
    {
        if(q1.isempty()==false)
        {

        }
    }
}
