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
        if(a[i]<a[i+1])
        {
            if(i==n-1)
            {
                break;
            }
            i++;
        }
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
