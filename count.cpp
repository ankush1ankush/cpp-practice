#include<bits/stdc++.h>
using namespace std;

void count(int a[],int n,int x,int &ans,int i)
{
   if(i==n)
   {
    return;
   }
   if(a[i]==x)
   {
    ans++;
   }
   count(a,n,x,ans,i+1);
}
int count2(int a[],int n,int x,int i)
{
   if(i==n)
   {
    return 0;
   }
   if(a[i]==x)
   {
    int present =count2(a,n,x,i+1);
    return 1+present;
   }
   else{
    return count2(a,n,x,i+1);
   }
}
int main()
{
    int ans=0;
    int a[]={1,2,4,5,4,3,4,5};
    cout<<count2(a,8,4,0);
    
}