#include<stdio.h>
#include<vector>

using namespace std;


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


int main(){
    int num_node,child,child_val,source,dest;
    printf("Numbers of node: ");
    scanf("%d",&num_node);
    vector<int>a[100];
    for(int i=1;i<=num_node;i++){
        printf("%d has adjacent num of nodes ",i);
        scanf("%d",&child);
        for(int j=0;j<child;j++){
            printf("value number %d: ",j+1);
            scanf("%d",&child_val);
            a[i].push_back(child_val);
        }
    }
    for(int i=1;i<=num_node;i++){

        printf("%d -> ",i);
        for(int j=0;j<a[i].size();j++){

            printf("%d ",a[i][j]);
        }
        printf("\n");
    }


    scanf("%d%d",&source,&dest);



return 0;
}
