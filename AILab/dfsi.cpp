
#include<stdio.h>
#include<algorithm>
#include<queue>
int d,n,c[50]={0},a[100][100]={0};
using namespace std;
int dfs(int s)
{
    if(s==d)return 1;
    for(int i=1;i<=n;i++)
    {
        if(a[s][i]==1&&c[i]==0)
        {
            c[i]=1;
            dfs(i);
              c[s]=2;
        }
    }

}

int main()
{

    int i, j,e, p1, p2,s,u;
    queue<int> q;
    printf("Total Nodes: ");
    scanf("%d",&n);
    printf("Total edges: ");
    scanf("%d",&e);

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
    c[s]=1;


   if(dfs(s)==1)printf("\nfound!");
   else printf("\nnot found");






return 0;
}
