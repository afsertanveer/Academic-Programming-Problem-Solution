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
    stack ob;
    int a,b;
    printf("\nMENU\n");
    printf("i|push\n");
    printf("ii|pop\n");
    printf("iii|top\n");
    printf("iv|number of elements\n");
    printf("v|empty or not\n");
    printf("vi|full or not\n");
    printf("vii|exit\n");
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
            if(ob.isempty()==false)ob.pop();
            else printf("stack is empty\n");
            break;
            case 3:
            printf("top element of stack : %d\n",ob.top());
            break;
            case 4:
            printf("number of element is stack is : %d\n",ob.noele());
            break;
            case 5:
            if(ob.isempty()==false)printf("not empty\n");
            else printf("empty\n");
            break;
            case 6:
            if(ob.isfull()==false)printf("not full\n");
            else printf("full\n");
            break;
            case 7:
            exit(0);
             break;
            default:
            printf("wrong choice\n");
        }
    }

}
