
#include<stdio.h>
#include<algorithm>
#include<queue>
int destination,n,white=0,gray=1,black=2,color[50],a[100][100]={0};
using namespace std;
int dfs(int s)
{
    if(s==destination)return 1;
    for(int i=1;i<=n;i++)
    {
        if(a[s][i]==1&&color[i]==gray)
        {
            color[i]=gray;
            dfs(i);
        }
    }
  color[s]=black;
}

int main()
{

    int i, j,nodes,edges,e1, e2,source;
    queue<int> q;
    scanf("%d%d",&nodes,&edges);

    for(i=0; i<edges; i++)
    {
        scanf("%d%d",&e1,&e2);
        a[e1][e2]=1;
        a[e2][e1]=1;
    }
    for(i=0;i<=n;i++)
    {
        color[i]=white;
    }

    scanf("%d%d",&source,&destination);
    color[source]=0;


   if(dfs(source)==1)printf("\nfound!");
   else printf("\nnot found");






return 0;
}
