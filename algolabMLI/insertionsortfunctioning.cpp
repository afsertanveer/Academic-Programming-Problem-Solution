#include<stdio.h>
void insertion(int a[],int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        k=a[i];
        j=i-1;
        while(j>=0 && a[j]>k)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
    }
}
void input(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void output(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int a[100],n;
    scanf("%d",&n);
    input(a,n);
    insertion(a,n);
    output(a,n);
}
