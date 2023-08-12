#include<bits/stdc++.h>
using namespace std;
int arr1[2]={-1,-1};
void find(int m,int n,int arr[][4],int key)
{
    
    int i=0;
    int j=n-1;
    while(i>=0&&i<m&&j>=0&&j<n)
    { 
        if(arr[i][j]==key)
        {
            arr1[0]=i;
            arr1[1]=j;
           
        }
        else if(arr[i][j]>key)
        {
            j--;
        }
        else if(arr[i][j]<key)
        {
            i++;
        }
    }

}
int main()
{
    int arr[4][4]={{10,20,30,40},{15,25,35,35},{27,29,37,48},{32,33,39,50}};
    find(4,4,arr,32);
    cout<<arr1[0]<<" "<<arr1[1]<<endl;
    
}