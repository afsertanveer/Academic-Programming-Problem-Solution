#include<stdio.h>
int main()
{
    int a[100],n,temp,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++ )
    {

        for(j=i;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
     //   i++;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

