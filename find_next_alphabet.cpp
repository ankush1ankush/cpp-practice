#include<bits/stdc++.h>
using namespace std;
char find_next(char arr[],int s,int e,char k)
{
    int mid=s+((e-s)/2);
    int result=-1;
    while(e>=s)
    {
        if(arr[mid]==k)
        {
            s=mid+1;
            return find_next(arr,s,e,k);
        }
        if(arr[mid]>k)
        {    
            e=mid-1;
            int ans=find_next(arr,s,e,k);
            if(ans!=-1)
            {
                return ans;
            }
            else
            {
                return mid;
            }
        }
        if(arr[mid]<k)
        {
            s=mid+1;
            return find_next(arr,s,e,k);
        }
    }
    return -1;

}
int main()
{
    char arr[]={'a','b','c','f','f'};
    int ans=find_next(arr,0,4,'f');
    cout<<ans<<endl;
}