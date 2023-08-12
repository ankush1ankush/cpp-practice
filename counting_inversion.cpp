#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int left[],int right[],int s,int e)
{
       int mid = (s+e)/2;
       int i=s;
       int j = mid+1;
       int k = s;
       int count=0;
       while(i<=mid && j<=e){
           if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
            k++;
            
           }else{
             arr[k] = right[j];
             j++;
             k++;
             count=count+(mid-i+1);
           }
       }
     for(int m=i;m<=mid;m++)
     {
        arr[k]=left[m];
        k++;
     }
     for(int m=j;m<=e;m++)
     {
        arr[k]=right[m];
        k++;
     }
       return count;
}
int merge_count(int arr[],int size,int s,int e)
{
  
  if(s>=e)
  {
    return 0;
  }
  int count =0;
  int mid=(((e+s)/2));
  
  int left[size];
  int right[size];
  for(int i=0;i<=mid;i++)
  {
    left[i]=arr[i];
  }
  for(int i=mid+1;i<=e;i++)
  {
    right[i]=arr[i];
  }
  count=count+merge_count(left,size,s,mid); // left
  count=count +merge_count(right,size,mid+1,e); //right
  count=count+ merge(arr,left,right,s,e);
  
  return count;
}

int main()
{
   int arr[] = { 1 , 5 , 2 , 4 , 13 , 19 , 15};
   int size=sizeof(arr)/sizeof(arr[0]);
   int s=0;
   int e=size-1;
 
    cout << "Number of inversions are "
         << merge_count(arr,size,s,e)<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
      cout<<endl;  
    return 0;   
}