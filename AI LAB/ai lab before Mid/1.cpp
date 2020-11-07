#include<stdio.h>
#include<vector>
using namespace std;
int main(){
    int num_node;
    printf("Numbers of node");
    scanf("%d",&num_node);
    vector<int>a;
    a.push_back(num_node);
    a.push_back(30);
    a.push_back(50);
    a.push_back(60);
    for(int i=0;i<a.size();i++)
    {
        printf("%d\n",a[i]);
    }

return 0;
}
