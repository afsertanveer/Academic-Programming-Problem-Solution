#include<vector>
#include<stdio.h>
#include<queue>
using namespace std;

int visit[100];
int dist[100];
vector<int>g[100];
vector<int>path;
queue<int>sp;
int parent[100];
int node=6;
int c=0;
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

           for(int i=0;i<g[a].size();i++)  {
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
/*
int pathfinder(int a,int d )
{
    c++;
    if(c>node)return -1;
    printf("\n%d\n",a);
    sp.push(a);
    int f = sp.front();
    int r=d;
    if(f==r)return 1;

    else if(g[f+1].size()==0)
    {
        sp.pop();
        return -1;
    }

    else
    {
        for(int i=0;i<g[f+1].size();i++)
        {
            printf("\nLoop er value: %d\n",g[f+1][i]);
            return pathfinder(g[f+1][i],d);

        }
    }

    return -1;
}
void shortestpath(int source,int dest)
{
        printf("sdadsad");
        sp.push(source);
        int d=dest;
        int f=sp.front();

            if(!sp.empty())
            {

                if(g[f].size()==0)
                {
                    sp.pop();
                }
                else
                {
                    for(int i=0;i<g[f].size();i++)
                    {

                        int res=pathfinder(g[f][i],d);
                        if(res==1)break;
                    }
                }

            }
}
*/
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
  /*  shortestpath(source,dest);
    while(!sp.empty())
    {
        int x=sp.front();
        path.push_back(x);
        printf("%d",x);
        sp.pop();
    }*/
    for(i=1;i<=node;i++)
    {
        printf("\nParent:%d",parent[i]);
    }
    return 0;

}

