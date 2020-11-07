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
        if(ch[i]>='A' && ch[i]<= 'Z' || ch[i]>='a' && ch[i]<='z')
        {
            ob.push(ch[i]);
        }
        else if(ch[i]>=48 && ch[i]<=57)
        {
            printf("%c",ob.pop());
        }

    }
     printf("\n");
}

}
