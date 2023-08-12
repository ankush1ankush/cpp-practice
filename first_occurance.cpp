#include<bits/stdc++.h>
using namespace std;
int first_occurance(int arr[],int s,int e,int k)
{
    int mid=s+((e-s)/2);
    int result;
    
    while(s<=e)
    {
        if(arr[mid]<k)
        {
            s=mid+1;
            result=first_occurance(arr,s,e,k);
            if(result !=-1)
            {
                return result;
            }
            else if( arr[mid]==k)
            {
                return mid;
            }
            else {
                return -1;
            }
            
        }
        else{
           
            e=mid-1;
            result=first_occurance(arr,s,e,k);
            if(result !=-1)
            {
                return result;
            }
            else if( arr[mid]==k)
            {
                return mid;
            }
            else {
                return -1;
            }
        }
    }
    
    if(arr[mid]==k)
    {
        return mid;
    }
    else 
    {
        return -1;
    }
    
}
int last_occurance(int arr[],int s,int e,int k)
{
    int mid=s+((e-s)/2);
    int result;
    
    while(s<=e)
    {
        if(arr[mid]<=k)
        {
            s=mid+1;
            result=last_occurance(arr,s,e,k);
            if(result !=-1)
            {
                return result;
            }
            else if( arr[mid]==k)
            {
                return mid;
            }
            else {
                return -1;
            }
            
        }
        else{
           
            e=mid-1;
            result=last_occurance(arr,s,e,k);
            if(result !=-1)
            {
                return result;
            }
            else if( arr[mid]==k)
            {
                return mid;
            }
            else {
                return -1;
            }
        }
    }
    
    if(arr[mid]==k)
    {
        return mid;
    }
    else 
    {
        return -1;
    }
    
}
int main()
{
   int arr[]={1,3,2,2,2,2,4,4,4,4,4,6,7};
   int ans=first_occurance(arr,0,12,4);
   int ans2=last_occurance(arr,0,12,4);
   cout<<ans<<endl;
   cout<<ans2<<endl;
}
