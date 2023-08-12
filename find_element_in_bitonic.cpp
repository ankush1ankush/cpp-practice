#include<bits/stdc++.h>
using namespace std;
int max(int arr[],int s,int e)
{
    int mid;
    int size=e;
    while(e>=s)
    {   

        mid=s+((e-s)/2);
        
        if((mid>0)&&(mid<size))
        {
            if((arr[mid]>arr[mid-1])&&(arr[mid]>arr[mid+1]))
            {
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
            else {
                return size-1;
            }
        }
    }
    return 0;
}
int increasing(int arr[],int s,int e,int k){
    int mid;
    while(e>=s)
    {
        mid=s+((e-s)/2);
        if(arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]<k)
        {
            s=mid+1;
        }
        else{
            e=mid+1;
        }
    }
    return -1;
}
int decreasing(int arr[],int s,int e,int k){
    int mid;
    while(e>=s)
    {
        mid=s+((e-s)/2);
        if(arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]>k)
        {
            s=mid+1;
        }
        else{
            e=mid+1;
        }
    }
    return -1;
}
int index(int arr[],int s,int e,int k)
{
    int peak=max(arr,s,e);
    int ans1=increasing(arr,s,peak-1,k);
    int ans2=decreasing(arr,peak,e,k);
    if(ans1!=-1)
    {
        return ans1;
    }
    else if(ans2!=-1)
    {
        return ans2;
    }
    else {
        return -1;
    }
    return -1;
}
int main()
{
    int arr[]={10,11,15,21,97,51,45,36,20,9,4,1};
    int ans=index(arr,0,11,36);
    cout<<ans<<"\n";
}