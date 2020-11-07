#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    queue<int> a;
    a.push(104);
    a.push(103);
    a.push(102);
    a.push(101);
        while(!a.empty())
        {
            printf("%d \n",a.front());
            a.pop();
        }

}
