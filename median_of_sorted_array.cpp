#include<bits/stdc++.h>
using namespace std;
int getmedian(int arr[],int n)
{
    if(n%2==0)
    {
        return (arr[(n-1)/2]+arr[(n)/2])/2;
    }
    else
    {
        return arr[n/2];
    }
}
int getans(int arr1[],int arr2[],int n)
{  
   
    if(n==1)
    {
        return (arr1[0]+arr2[0])/2;
    }
    if(n==2)
    {
        return ((max(arr1[0],arr2[0])+min(arr2[1],arr2[1]))/2);
    }
    int median1=getmedian(arr1,n);
    int median2=getmedian(arr2,n);
    if(median1==median2)
    {
        return median1;
    }
   
    if(median1<median2)
    {
       if(n%2==0)
       {
        return getans(arr1+(n/2)-1,arr2,(n/2)+1); // arr1[(n/2)-1]--arr1[n],arr2[0]--arr2[n/2]; n==even;
     
       }
       else
       {
        return getans(arr1+(n/2),arr2,(n/2)+1);
       }
    }
    if(median2<median1)
    {
        if(n%2==0)
        {
            return getans(arr1,arr2+(n/2)-1,(n/2)+1); //arr1[0]--arr1[n/2],arr2[(n/2)-1]--arr2[n] n==even;
        }
        else{
            return getans(arr1,arr2+(n/2),(n/2)+1);
        }

        
    }
    return -1;
}
int main()
{
    int arr1[]={1,12,15,26,38};
    int arr2[]={2,13,17,30,45};
    int ans=getans(arr1,arr2,5);
    cout<<ans<<endl;
    return 0;
}