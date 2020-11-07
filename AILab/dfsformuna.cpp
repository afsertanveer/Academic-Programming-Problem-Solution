#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{

    int i, j,n,e, p1, p2,a[100][100]={0},c[100],p[100],s,d,flag=0,u;
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
    for(i=0; i<=n; i++)
    {
        c[i]=1;
        p[i]=0;

    }

    p[s]=1;
    c[s]=2;
    q.push(s);

    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(i=0; i<=n; i++)
            if(a[u][i]==1)
            {

                if(c[i]==1)
                {
                    q.push(i);
                    c[i]=2;

                }
                if(c[i] ==2)
                {
                    q.push(i);
                    c[i]=3;

                }
            }
    }


if(c[d]!=3) printf("NO");
else printf("Yes");





return 0;
}
