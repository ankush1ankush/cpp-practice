#include<bits/stdc++.h>
using namespace std;
int store(int a[],int n,int x,int j,int i,int ans[])//with array
{
  if(i==n)
  {
    return 0 ;
  }
  if(a[i]==x)
  {
    ans[j]=i;
    return 1+ store(a,n,x,j+1,i+1,ans);
  }
  else{
    return store(a,n,x,j,i+1,ans);
  }

}
int main()
{
    int a[]={1,6,3,6,5,6,7};
    int ans[10];
    int count= store(a,7,6,0,0,ans);
    for(int i=0;i<count;i++)
    {
        cout<<ans[i]<<" ";
    }

}