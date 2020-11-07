#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    vector <int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    //a.clear();

    printf("%d",a.size());

   /* if(a.empty())printf("Empty");
    else
    for(int i=a.begin();i<a.end();i++)
    {
        printf("%d\t",a[i]);

    }*/
}
