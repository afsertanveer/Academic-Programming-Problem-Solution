#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
  int a[50][50],n,c[50],flag=0,d,white=0,gray=1,black=2,prev[100]={0},u,dis[100]={0};
  queue<int> q;
  void dfs(int s)
  {
      int i;
          if(s==d)
          flag=1;

      else
      {
          for(i=0;i<=n;i++)
          {
              if(a[s][i]==1&& c[i]==white)
              {
                  c[i]=gray;
                  dfs(i);
              }
          }
          c[i]=black;
      }
  }

    void bfs(int s)
  {
        int i;
          q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=1;i<=n;i++)
        {
            if(a[u][i]==1&& c[i]==white)
            {
                q.push(i);
                prev[i]=u;
                dis[i]=dis[u]+1;
                c[i]=gray;
            }
        }
    }


  }

  void print(int d)
  {
      int j;
      j=d;
      if(j==-1)
        return;
      else {
        j=prev[d];
        if(prev[d]==-1)
            return;

        printf("->%d",j);
        d=j;
        print(j);
      }
  }
int main(){

    int i, j,e, e1, e2,s,choice;


    printf("Inputs for graph:\n\n\n");
    printf("Total Nodes: ");
    scanf("%d",&n);
    printf("\n\nTotal Edges: ");
    scanf("%d",&e);

    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            a[i][j] = 0;
        }
    }
    for(i=0;i<=n;i++)
    {
        c[i]=white;
    }
    printf("\n\n");
    for(i=1;i<=e;i++){
            printf("Edge no %d : ",i);
        scanf("%d",&e1);
        scanf("%d",&e2);

        a[e1][e2] = 1;
        a[e2][e1] = 1;
    }

   while(1){
    printf("\n\n");
    printf("\n1.BFS\n\n\n");
    printf("2.DFS\n\n\n");
    printf("3.Exit\n\n\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    if(choice==1){
    for(i=0;i<n;i++)
    {
        c[i]=white;
        prev[i]=0;
    }
    printf("Source: ");
    scanf("%d",&s);
    printf("Destination: ");
    scanf("%d",&d);
    c[s]=1;
    prev[s]=-1;
    dis[s]=1;

    bfs(s);
    printf("\n\nPath : ");
   printf("%d",d);
    print(d);
    }
    else if(choice==2){
    for(i=0;i<n;i++)
    {
        c[i]=white;
    }
    printf("\n\nSource: ");
    scanf("%d",&s);
    printf("\n\nDestination: ");
    scanf("%d",&d);
        c[s]=gray;
    dfs(s);
if(flag==1)printf("\n\nYes there is a connection between the source and destination");

else    printf("\n\nNo,Disconnected graph");
    }

    else break;
   }
return 0;
}
