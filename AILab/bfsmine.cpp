#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
  int adjacncyMatrix[50][50],colour[50]={0},prev[50]={0},d[50]={0},n,i, j, totalNode, totalEdge, p1, p2;
      queue<int> q;
  void bfs(int s)
  {

          q.push(s);
    while(!q.empty())
    {
        n=q.front();
        q.pop();
        for(int i=1;i<=totalNode;i++)
        {
            if(adjacncyMatrix[n][i]==1&&colour[i]==0)
            {
                q.push(i);
                prev[i]=n;
                d[i]=d[n]+1;
                colour[i]=1;
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


    scanf("%d",&totalNode);
    scanf("%d",&totalEdge);

    for(i=0;i<=totalNode;i++){
        for(j=0;j<=totalNode;j++){
            adjacncyMatrix[i][j] = 0;
        }
    }

    for(i=1;i<=totalEdge;i++){
        scanf("%d",&p1);
        scanf("%d",&p2);

        adjacncyMatrix[p1][p2] = 1;
        adjacncyMatrix[p2][p1] = 1;
    }
    int source,destination;
    scanf("%d %d",&source,&destination);
    colour[source]=1;
    prev[source]=-1;
    d[source]=1;

    bfs(source);

   printf("%d",destination);
    print(destination);


    return 0;
}
