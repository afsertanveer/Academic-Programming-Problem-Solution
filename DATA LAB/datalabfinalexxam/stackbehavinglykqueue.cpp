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
    int a,b,i;
    while(1)
    {
        printf("\nMenu\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.TOp value of Queue\n");
        printf("4.Queue is full or not \n");
        printf("5.Queue is empty or not\n");
        printf("Enter the choice u want to do: ");
        scanf("%d",&b);
        switch(b)
        {
            case 1:
                    if(ob.isfull()==false)
                    {
                    printf("Enter tha value u want to enqueue: ");
                    scanf("%d",&a);
                    ob.push(a);
                    }
                    else
                    {
                        printf("Queue is full\n");
                    }
                    break;
            case 2:
                    if(ob.isempty()==false)
                    {
                        while(ob.isempty()==false)
                        {
                            ob1.push(ob.pop());
                        }
                        printf("%d data is dequeued\n",ob1.pop());
                        while(ob1.isempty()==false)
                        {
                            ob.push(ob1.pop());
                        }
                    }
                    else
                    {
                        printf("Queue is empty\n");
                    }
                    break;
            case 3:
                     printf("Top value of the queue is %d\n",ob.top());
                     break;
            case 4:
                     if(ob.isfull()==true)printf("Queueu is full\n");
                     else printf("Queue is not full\n");
                     break;
            case 5:
                     if(ob.isempty()==true)printf("Queue is empty\n");
                     else printf("Queue is not empty");
                     break;
            default:
                     printf("Wrong input\n");

        }

    }
}
