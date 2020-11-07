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
    int i,check;
    char ch[100];
    while(1){
    gets(ch);
    for()
    for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='(' || ch[i]=='{' || ch[i]=='[')
           {
               ob.push(ch[i]);
           }
        else
        {
            if(ch[i]==')' && ob.pop()=='(' || ch[i]=='}' && ob.pop()=='{' || ch[i]==']' && ob.pop()=='[')
              {
                  check=0;
              }
              else if( ch[i]==')' && ob.pop()!='(' || ch[i]=='}' && ob.pop()!='{' || ch[i]==']' && ob.pop()!='['  )
              {
                  printf("Closing bracket overflow\n");
                  check=2;
                  break;

              }
              else if( ch[i]=='(' && ob.pop()!=')' || ch[i]=='{' && ob.pop()!='}' || ch[i]=='[' && ob.pop()!=']'  )
              {

                  printf("opening bracket overflow\n");
                  check=3;
                  break;

              }
             else
              {
                  printf("Unmatched\n");
            }
        }
    }

    if(check==0)printf("Balanced\n");
}
}
