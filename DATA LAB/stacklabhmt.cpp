#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int head;
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
    int a,b;
        printf("\nMENU\n");
        printf("1)Enqueue\n");
        printf("2)Dequeue\n");
        printf("3)empty\n");
        printf("4)full\n");
        printf("5)exit\n");
        printf("............\n");
    while(1)
    {
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            printf("enter a value to insert\n");
            scanf("%d",&b);
            if(ob.isfull()==false)ob.push(b);
            else printf("stack is full\n");
            break;
            case 2:
            while(ob.isempty()==false)
            {
                ob1.push(ob.pop());
                printf("value second stack top %d\n",ob1.top());
            }
            b=ob1.pop();
            printf(" %d dequeued\n",b);
            while(ob1.isempty()==false)
            {
                    ob.push(ob1.pop());
            }
            break;
            case 3:
            if(ob.isempty()==false)printf("not empty\n");
            else printf("empty\n");
            break;
            case 4:
            if(ob.isfull()==false)printf("not full\n");
            else printf("full\n");
            break;
            case 5:
            exit(0);
             break;
             case 6:
             b=ob.top();
             printf("top is : %d\n",b);
             break;
            default:
            printf("wrong choice\n");
        }
    }

}

