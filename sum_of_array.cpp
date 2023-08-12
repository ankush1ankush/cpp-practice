#include<bits/stdc++.h>
using namespace std;
int sum(int a[],int n)
{
    if(n==0)
    {
        return 0;
    }
    int smalloutput=sum(a+1,n-1);
    return a[0]+smalloutput;
}
int  main()
{
    int arr[]={1,2,3,4,5};
    cout<<sum(arr,5);
}