#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    vector<int>vec[100];
    int a,val,i,nodes,j,num,adj;
    printf("how many nodes graph has: ");
    scanf("%d",&nodes);
    for(i=1;i<=nodes;i++)
    {
        printf("%d has number of adjacent nodes: ",i);
        scanf("%d",&adj);
        for(j=0;j<adj;j++)
        {
            printf("value %d: ",j+1);
            scanf("%d",&a);
            vec[i].push_back(a);
        }
    }
    for(i=1;i<=nodes;i++)
    {
        printf("%d-> ",i);
        for(j=0;j<vec[i].size();j++)
        {
            printf("%d ",vec[i][j]);
        }
        printf("\n");
    }
}
