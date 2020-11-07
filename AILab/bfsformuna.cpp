




















































































































#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{

    int i, j,n,e, p1, p2,a[100][100],p[100]={0},visited[50]={0},dis[100]={0},s,d,u;
    queue<int> q;
    printf("Total Nodes: ");
    scanf("%d",&n);
    printf("Total edges: ");
    scanf("%d",&e);


    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            a[i][j]=0;
        }
    }
    for(i=0; i<e; i++)
    {
        printf("Edge %d : ",i+1);
        scanf("%d%d",&p1,&p2);
        a[p1][p2]=1;
        a[p2][p1]=1;
    }

    printf("Source: ");
    scanf("%d",&s);
    printf("Destination: ");
    scanf("%d",&d);


    p[s]=-1;
    visited[s]=1;
    dis[s]=1;
    q.push(s);

    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(i=1; i<=n; i++){

            if(a[u][i]==1 && visited[i]==0)
            {

                    q.push(i);
                    p[i]=u;
                    dis[i]=dis[u]+1;
                    visited[i]=1;

            }

        }
    }

printf("\n\n%d",d);
while(1)
{
    j=p[d];
    if(j!=-1)
    {
        printf("->%d",j);
        d=j;
    }
    else break;

}

return 0;
}
