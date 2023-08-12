#include<bits\stdc++.h>
using namespace std;
int getlast(int a[],int n,int x,int i)
{
    if(i==-1)
    {
        return -3;
    }
    if(a[i]==x)
    {
        return i;
    }
    int present=getlast(a,n,x,i-1);
    return present;
}
int getlast2(int a[],int n,int x)
{
    if(n==0)
    {
        return -1;
    }
    if(a[n-1]==x)
    {
        return n-1;
    }
    int present=getlast2(a,n-1,x);
    return present;
}
int getlast3(int a[],int n,int x,int i)
{
    if(i==n)
    {
        return -1;
    }
    int present=getlast3(a,n,x,i+1);
    if(present==-1)
    {
        if(a[i]==x)
        {
             return i;
        }
        else{
         return -1;
        }
    }
    
    return present;
     
 
    
}

int main()
{
    int a[]={1,2,2,4,5};
    cout<<getlast3(a,5,6,0);
}