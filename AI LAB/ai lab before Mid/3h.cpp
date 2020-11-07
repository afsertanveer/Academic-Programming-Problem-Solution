#include<vector>
#include<stdio.h>
#include<queue>
#include<set>

using namespace std;

int visit[100];
int parent[100];
int dist[100];
int visitedSeq[100];
vector<int>g[100];
int node=6;
vector<int>sp;
void bfs(int source)
{
        queue<int>q;
        q.push(source);
        visit[source]=1;
        parent[source]=source;
        while(!q.empty())
        {
           int a=q.front();
           q.pop();

           for(int i=0;i<g[a].size();i++)
           {
               int y=g[a][i];
               if(visit[y]==0)
               {

                   q.push(y);
                   visit[y]=1;
                   dist[y]=dist[a]+1;
                   parent[y]=a;
               }
           }

        }



}

void path(int source,int dest)
{
    int d=dest,a,s=source;
    sp.push_back(d);
    for(int i=0;i<node;i++)
    {

        a=parent[d];
        sp.push_back(a);
        d=parent[d];
        if(d==s)
        break;

    }

}



int main()
{
    int i,j,val,num_ad_node,source,dest;
    for(i=1;i<=node;i++)
    {
     printf("How many adjacent nodes %d has: ",i);
     scanf("%d",&num_ad_node);
     for(j=0;j<num_ad_node;j++)
     {
         printf("value %d: ",j+1);
         scanf("%d",&val);
         g[i].push_back(val);
         printf("\n");
     }

    }
    for(i=1;i<=node;i++)
    {
        printf("%d-> ",i);
        for(j=0;j<g[i].size();j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");

    }
    scanf("%d",&source);
    scanf("%d",&dest);
    bfs(source);

    printf("Distance :%d",dist[dest]);

    path(source,dest);
    printf("\n");
    for(i=sp.size()-1;i>=1;i--)
    {
        printf("%d -> ",sp[i]);
    }
    printf("%d",sp[0]);
    return 0;

}
