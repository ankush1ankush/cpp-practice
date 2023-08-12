// #include<bits\stdc++.h>
#include<iostream>
using namespace std;
int bsrch(int arr[],int n,int key)
{
    int s=0;
    int e=n-1;
    int mid;
    while(s<=e)
    {    mid=(s+e)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
       
    }
    return mid;
}
int main()
{
    int arr[]={1,3,5,100};
    cout<<lower_bound(arr, arr+4,100)-arr;
}
