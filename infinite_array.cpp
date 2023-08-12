#include<bits/stdc++.h>
using namespace std;
int BS(int arr[],int s,int e,int k)
{
    int mid=(s +  ((e-s)/2));
    if(arr[mid]==k)
    {
        return mid;
    }
    while(e>s)
    {
        if(arr[mid]<k)
        {
            s=mid+1;
            return BS(arr,s,e,k);
        }
        else{
            
            e=mid-1;
            return BS(arr,s,e,k);
        }

    }
    return -1;
}
int SI(int arr[],int k)
{
    int low=0;
    int high=1;
    while(k>arr[high])
    {
       low=high;
       high=high*2;
    }
    cout<<low<<" "<<high<<endl;
    int ans=BS(arr,low,high,k);
    return ans;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,27,29,30,31,32,33};
    int ans=SI(arr,32);
    
    cout<<ans<<endl;
   
}