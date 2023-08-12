#include<bits/stdc++.h>
using namespace std;
int peak(int arr[],int s,int e)
{
    int mid;
    int size=e;
    while(s<=e)
    {
       mid= s + ((e-s)/2);
       if(mid>0 && mid<size)
       {
         if((arr[mid]>arr[mid-1])&&(arr[mid]>arr[mid+1])){
           return mid; 
         }
         else if(arr[mid]<arr[mid-1])
         {
           e=mid-1;
         }
         else{
           s=mid+1;
         }
       }
       else if(mid==0)
       {
          if(arr[0]>arr[1])
          {
             return 0;
          }
          else{
            return 1;
          }
       }
       else if(mid==size)
       {
        if(arr[size]>arr[size-1])
        {
            return size;
        }
        else{
            return size-1;
        }
       } 

    }
    return 0;
}
int main()
{
    int arr[]={1,2,15,2,23,90,67};
    int ans=peak(arr,0,6);
    cout<<ans<<endl;
}