#include<bits/stdc++.h>
using namespace std;

int getpartion(vector<int>&vec,int s,int e) // bringing smaller element than pivot to left and
                                            // greater to right
{   
   
   int pivot=vec[e]; // pivot element is the last element
   int i=s-1;   // i is denoting last number which is less than pivot

   for(int j=s;j<e;j++)
   {
    if(vec[j]<pivot)
    {
       i++;
       swap(vec[i],vec[j]);
    }
   }                      // 6 , 3 , 5 , 2 , 9 , 8 , 7  <-pivot
                          //             i        j     
   swap(vec[i+1],vec[e]); // best position for the piovat element is i+1
                          // i is denoting the last element which is smaller than pivot
   return i+1; 
}

void quicksort(vector<int>&vec,int s,int e)
{
    if(s<e)
    {
        int pi=getpartion(vec,s,e);
        quicksort(vec,s,pi-1);
        quicksort(vec,pi+1,e);
    }
}






int main()
{  
   int n;
   cin>>n; //entering the size of the array
   vector<int> a(n+1);
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }
   
   a[n]=INT_MAX;
   quicksort(a,0,a.size()-1);
   
   for(int i=0;i<n;i++)
   {
    cout<<a[i]<<" ";
   }
    
}