#include<bits\stdc++.h>
using namespace std;
int main()
{
   int sr,er,sc,ec;
   int row,col;
   cin>>row>>col;
   vector <vector<int>> vec;
   for(int i =0;i<row;i++)
   {
    vector <int> v;
    for(int j=0;j<col;j++)
    {  
        int k=0;
        cin>>k;

        v.push_back(k);

    }
    vec.push_back(v);
   }
   sr=0;
   er=row-1;
   sc=0;
   ec=col-1;
   int count =0;
   while(sr<=er && sc<=ec && count<row*col )
   {
     for(int j=sc;j<=ec;j++)
     {  
        cout<<vec[sr][j]<<" ";
        count++;
        
     }
     sr++;
     if(count==row*col)
        {
         break;
        }
     for(int i=sr;i<=er;i++)
     {  
        cout<<vec[i][ec]<<" ";
        count++;
       
     }
     ec--;
     if(count==row*col)
        {
         break;
        }
     for(int j=ec;j>=sc;j--)
     {  
      
        cout<<vec[er][j]<<" ";
        count++;
        
        
     }
     er--;
     if(count==row*col)
        {
         break;
        }
     for(int i=er;i>=sr;i--)
     {
        
        cout<<vec[i][sc]<<" ";
        count++;
        

     }
    sc++;
    if(count==row*col)
        {
         break;
        }
    
    
   }
   
  return 0; 
}