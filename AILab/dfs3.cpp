#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
  int a[50][50],n,c[50],flag=0,d,white=0,gray=1,black=2;
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
int main(){

    int i, j,e, e1, e2,s;


    scanf("%d",&n);
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

    for(i=1;i<=e;i++){
        scanf("%d",&e1);
        scanf("%d",&e2);

        a[e1][e2] = 1;
        a[e2][e1] = 1;
    }
    scanf("%d%d",&s,&d);
        c[s]=gray;
    dfs(s);
if(flag==1)printf("Yes there is a connection between the source and destination");

else    printf("No,Disconnected graph");

return 0;
}
