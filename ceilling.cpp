#include<bits/stdc++.h>
using namespace std;
int floor(int arr[],int s,int e,int k)
{
    
    int result=-1;
    int mid=s+((e-s)/2);
    
    while(e>=s)
    {    
        if(arr[mid]==k)
        {
            return mid;
        }
        if(arr[mid]>k)
        {
            e=mid-1;
            int ans=floor(arr,s,e,k);
            if(ans!=-1)
            {
                return ans;
            }
            else{
                return mid;
            }
           
        }
        else{
            s=mid +1;
            return floor(arr,s,e,k);
        }
        
    }
    
    return result;
    
}
int main()
{
    int arr[]={1,2,3,4,8,10,10,12,29};
    int ans=floor(arr,0,7,9);
    cout<<ans<<endl;
}