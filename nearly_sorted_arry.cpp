#include<bits/stdc++.h>
using namespace std;
// search in the nearly sorted array 
// nearly sorted array is array in which the element is present in the ith or (i+1)th or (i-1)th index 
int search(int arr[],int s,int e,int k)
{
    int mid=s+((e-s)/2);
    if(arr[mid]==k)    //check for the i th index
    {
        return mid;
    }
    else if((mid+1<=e)&&(arr[mid+1]==k)) //check for the i+1 th index
    {
        return mid+1;
    }
    else if((mid-1>=s)&&(arr[mid-1]==k)) // check for the i-1 th index
    {
        return mid-1;
    }
    while(e>s)
    {
        if(k>arr[mid])
        {
            s=mid+2;
            return search(arr,s,e,k);
        }
        if(k<arr[mid])
        {
            e=mid-2;
            return search(arr,s,e,k);
        }
    }
    return -1;
}
int main()
{
    int arr[6]={4,5,6,10,7,22};
    int ans=search(arr,0,6,7);
    cout<<ans<<endl;
}