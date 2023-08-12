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
int count(int arr[],int s,int e,int k)
{
    int ans=last_occurance(arr,0,8,4)-first_occurance(arr,0,8,4)+1;
    return ans;
}
int main()
{
    int arr[]={1,2,3,4,4,4,4,4,9};
    cout<<count(arr,0,8,4)<<endl;

}