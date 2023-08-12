#include<bits/stdc++.h>
using namespace std;

void allIndex(int a[],int n,int x,int i)
{
    if(i==n)
    {
        return;
    }
    if(a[i]==x)
    {
        cout<<i<<" ";
    }
    allIndex(a,n,x,i+1);
}

int main()
{
    int a[]={1,2,3,3,43,3};
    allIndex(a,6,4,0);
}