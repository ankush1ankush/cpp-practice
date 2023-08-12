#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int s, int e, int k)
{ 
  if(arr[0]<arr[e]){
  int mid=(s +  ((e-s)/2));
   if(arr[mid] ==k)
  {
    return mid;
  }
  while(e>s){
   if(arr[mid]>k)
  {
    e=mid-1;
    return search(arr,s,e,k);
  }
  else{
    s=mid+1;
    return search(arr,s,e,k);
  }
  }
  return -1;
  }
  if(arr[0]>arr[e]){
  int mid=(s +  ((e-s)/2));
   if(arr[mid] ==k)
  {
    return mid;
  }
  while(e>s){
   if(arr[mid]>k)
  {
    s=mid-1;
    return search(arr,s,e,k);
  }
  else{
    e=mid+1;
    return search(arr,s,e,k);
  }
  }
  return -1;
  }
   return 0;
}

int main()
{
   int arr[]={7,6,5,4,3,2,1};
   cout<<search(arr,0,6,5);
}