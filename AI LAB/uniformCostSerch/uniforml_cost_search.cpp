#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
struct Nodes
{
    int node;
    int cost;
    bool operator<(const Nodes &o) const
    {
        return cost > o.cost;
    }
};
vector<Nodes> g[10];
int visit[100];
int parent[100];
int dist[100];
int visitedSeq[100];
vector<int>sp;

void ucs(int source,int tot_node)
{
        priority_queue<int, vector<int>, greater<int> >q;
        queue<int>x;
        int i,j;
        x.push(source);
        visit[source]=1;
        parent[source]=source;
        for(i=1;i<=tot_node;i++)
        {
            for(j=0;j<g[i].size();j++)
            {
                if(source==g[i][j].node)
                {
                    q.push(g[i][j].cost);  //graph theke khuje node ber kore corresponding cost push korlam
                }
            }
        }
        while(!x.empty())
        {
           int a=x.front();
           x.pop();

           for(int i=0;i<g[a].size();i++)
           {
               int y=g[a][i].node;
               int lat_cost=dist[a]+g[a][i].cost;
               if(lat_cost<dist[y])
               {

                   x.push(y);
                   visit[y]=1;
                   dist[y]=lat_cost;
                   parent[y]=a;
               }
               else
               {
                   x.push(y);
                   visit[y]=1;
                   dist[y]=lat_cost;
                   parent[y]=a;


               }
           }

        }



}
void path(int source,int dest)
{
    int d=dest,a,s=source;

    sp.push_back(d);
    if(s==d)return;
    else
    {

        a=parent[d];
        path(s,a);
    }

}


int main()
{

    Nodes connectedNode;
    int source,dest;
    int num,i,j,tot_node;
    printf("How many nodes : ");
    scanf("%d",&tot_node);
    for(i=1;i<=tot_node;i++)
    {
        printf("%d has number of nodes: ",i);
        scanf("%d",&num);
        for(j=0;j<num;j++)
        {
            printf("%d node: ",j+1);
            scanf("%d",&connectedNode.node);
            printf("%d cost: ",j+1);
            scanf("%d",&connectedNode.cost);
            g[i].push_back(connectedNode);
        }

    }


    for(i=1;i<=tot_node;i++)
    {
        printf("%d -> : ",i);
        for(j=0;j<g[i].size();j++)
        {
            printf("Node: %d Cost: %d\t",g[i][j].node,g[i][j].cost);

        }
        printf("\n");

    }
    printf("Source: ");
    scanf("%d",&source);
    printf("Destination: ");
    scanf("%d",&dest);

    ucs(source,tot_node);
    printf("Lowest Cost: %d",dist[dest]);

      path(source,dest);
    printf("\n");
    for(i=sp.size()-1;i>=0;i--)
    {   if(i==0)
        {
            printf("%d",sp[i]);
        }
        else
        {
            printf("%d -> ",sp[i]);

        }
    }


}

