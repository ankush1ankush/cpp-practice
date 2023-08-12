#include<bits/stdc++.h>
using namespace std;
bool isSort(int a[],int n)
{   cout<<"call"<<endl;
    if(n==0||n==1)
    {
        return true;
    }
    if(a[0]>a[1])
    {
       return false;
    }
    bool smalloutput=isSort(a+1,n-1);
    return smalloutput;
}
int main()
{
    int arr[]={1,2,3,5,4};
    if(isSort(arr,5)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
}