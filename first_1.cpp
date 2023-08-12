#include<bits/stdc++.h>
using namespace std;
int first_occurance(int arr[],int s,int e,int k)
{
    int mid;
    while(e>s)
    {
        mid=s+((e-s)/2);
        if(arr[mid]==k)
        {
            e=mid-1;
        }
        else if(arr[mid]>k)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    if(arr[mid]==k)
    {
        return mid;
    }
    else{
             return -1;

    }
    return 0;
}
int SR(int arr[],int k)
{
   int low=0;
   int high=1;
   while(arr[high]<k)
   {
    low=high;
    high=2*high;
   }
   int ans=first_occurance(arr,low,high,1);
   return ans;
}
int main()
{
    int arr[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int ans=SR(arr,1);
    cout<<ans<<endl;
}