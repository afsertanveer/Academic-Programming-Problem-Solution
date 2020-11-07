#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;
  int adjacncyMatrix[50][50];
int main(){


    stack<int> q;
    q.push(5);
    q.push(7);
    q.push(9);
    q.push(10);
    q.pop();
    q.push(6);
    int i=0;
    while(!q.empty()){
    i++;
    printf("NO. %d : %d\n",i,q.top());
    q.pop();
    }
    return 0;
}

