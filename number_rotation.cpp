#include<bits/stdc++.h>
using namespace std;
int num_rotate(int arr[],int s,int e,int N)
{
    int mid = s + ((e-s)/2);
    int next=(mid+1)%N;
    int pre=(mid+N-1)%N;
    if((arr[mid]<arr[next])&&(arr[mid]<arr[pre]))
    {
        return mid;
    }
    while(s<=e)
    {
        if(arr[mid]>arr[s])
        {
            s=mid+1;
            return num_rotate(arr,s,e,N);
        }
        else{
            e=mid-1;
            return num_rotate(arr,s,e,N);
        }
    }
    return 0;
}
int main()
{
    int arr[]={4,5,6,7,8,9,1,2,3};
    cout<<num_rotate(arr,0,8,9);
}
