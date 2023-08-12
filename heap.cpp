#include<bits/stdc++.h>
using namespace std;
void Max_heapify(int A[],int i,int size)
{
    
    int L=2*i+1;
    int R=2*i+2;
    int max;
    if(L<size&&A[L]>A[i])  // L>size-1 means we at leaf element   //
    {                                                             //
        max=L;                                                    //
    }                                                             //
    else{                                                         //  extracting max
        max=i;            // means i is the max emelment now                                            //
    }                                                             //
    if(R<size&&A[R]>A[max])  // R>size-1 means we at leaf element //
    {                                                             //
        max=R;                                                    //
    }                                                             
    if(max!=i){                                                
    swap(A[i],A[max]);// swaping the largest of Left and right with ith element
    Max_heapify(A,max,size);  // recursice call on the swap element to ensure heap property
                      // in the lower subtree
    }
   // this will backtrack if i is the index of leaf element
}
void Build_heap(int A[],int size)
{
    
    for(int i=(size/2)-1;i>=0;i--)
    {
        Max_heapify(A,i,size); // call max_heapify from node leaf node to 0;  
    }
}
void heap_sort(int A[],int size)
{    Build_heap(A,8);
    for(int i=size-1;i>0;i--)
    {
        swap(A[0],A[i]);
        Max_heapify(A,0,i);
    }
}
int main()
{  
    int A[]={3,6,5,0,8,2,1,9};
     
   
    heap_sort(A,8);
    for(int i=0;i<8;i++)
    {
        cout<<A[i]<<" ";
    }
    
}