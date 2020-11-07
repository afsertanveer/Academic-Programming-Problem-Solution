#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
    int a[50][50],i,j,n,e,v1,v2,s,d, count=0,c[100]={0},w=0,g=1,b=2,;
    queue<int> q;
    printf("total nodes: ");
    scanf("%d",&n);
    printf("total edges: ");
    scanf("%d",&e);
        for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            a[i][j]=0;

        }
    }
    for(i=1;i<=e;i++)
    {
        printf("Enter EDGE %d : ",i);
        scanf("%d%d",&v1,&v2);
        a[v1][v2]=1;
        a[v2][v1]=1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("Source: ");
    scanf("%d",&s);
    printf("Destination: ");
    scanf("%d",&d);
    if(a[s][d]==1)
    {
        printf("Path length: 1");
        printf("\nPath:%d -> %d",s,d);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {

                q.push(a[i][j])

            if(a[i][j]==1){

                q.push(a[i][j])
            }
        }
    }


}
