#include<bits/stdc++.h>
using namespace std;
bool ispresent(int a[],int n,int key) // traversing the array from starting
{
    if(n==0)
    {
        return false;
    }
    if(a[0]==key)
    {
        return true;
    }
    bool present=ispresent(a+1,n-1,key);
    return present;
}
bool ispresent2(int a[],int n,int key) // traversing the array from end
{   
    if(n==0)
    {
        return false;
    }
    if(a[n-1]==key)
    {
        return true;
    }
    bool present=ispresent2(a,n-1,key);
    return present;
}
bool ispresent3(int a[],int n,int x) // transverse the array from start to end first and then look for the element
{
    if(n==0)
    {
       return false;
    }
    bool present=ispresent3(a+1,n-1,x);
    if(present)
    {
        return true;
    }
    if(a[0]==x)
    {
        return true;
    }
    else{

       return false;
    }
}
int getindex(int a[],int n,int key,int i){

  if(i==n)
   {
    return -1;
   } 
  if(a[i]==key)
  {
    return i;
  }
  int present=getindex(a,n,key,i+1);
  return present;

}
int main()
{
    int a[]={2,4,4,2,5,6};
    cout<<getindex(a,6,8,0);
}