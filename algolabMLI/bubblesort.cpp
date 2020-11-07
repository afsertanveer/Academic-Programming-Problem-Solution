#include<stdio.h>
void swap(int a[],int n,int i)
{
    int temp;
    for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
}
void bubblesort(int a[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        swap(a,n,i);
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
    bubblesort(a,n);
    output(a,n);
}
