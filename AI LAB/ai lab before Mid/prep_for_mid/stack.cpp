#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
    stack<int>a;
    a.push(10);
    a.push(20);
        printf("%d ",a.top());
        a.pop();
        printf("%d ",a.top());
        a.pop();

}
