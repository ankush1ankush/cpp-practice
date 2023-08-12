#include<bits/stdc++.h>
using namespace std;
int find_majority(int arr[],int n)
{
    int count=1;
    int majority_element=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]==majority_element)
        {
            count++;
        }
        else{
            count--;
        }
        if(count==0)
       {
        majority_element=arr[i];
        count=1;
       }
    }
    return majority_element;
}
int main()
{
    int arr[]={2,3,4,3,3,4,5,3,3};
    int ans=find_majority(arr,9);
    cout<<ans<<endl;

}