#include<bits/stdc++.h>
using namespace std;
int rotate_search(int arr[],int s,int e,int k)
{
    int mid=s+((e-s)/2);
    if(arr[mid]==k)
    {
        return mid;
    }
    while(e>s)
    {
        if(arr[mid]>arr[s])
        {
            if(k<arr[mid]&&k>arr[s])
            {
                e=mid-1;
                return rotate_search( arr,s,e,k);
            }
            else{
                s=mid+1;
                return rotate_search( arr, s, e, k);
            }
        }
        if(arr[mid]<arr[e])
        {
            if(k>arr[mid]&&k<arr[e])
            {
                s=mid+1;
                return rotate_search(arr,s,e,k);
            }
            else{
                e=mid-1;
                return rotate_search( arr, s, e, k);
            }
        }
    }
    return -1;
}

int main()
{
    int arr[]={10,11,12,13,14,1,2,3,4,5,6,7,8,9};
    int ans=rotate_search(arr,0,13,1);
    cout<<ans<<endl;
}