#include<bits/stdc++.h>
using namespace std;
void sort( vector<int> &vec)
{
    int n=vec.size();
    
    

    for(int i=0;i<n-1;i++)
    {   int smallest=vec[i];
        int index;
        for(int j=i+1;j<n;j++)
        {
             if(vec[j]<smallest)
             {
                  smallest=vec[j];
                  index=j;
             }
        }
        if(vec[i]>vec[index]){
        swap(vec[i],vec[index]);
        }
    }
}
int main()
{
    vector <int> vec;
    int n;
    cin>>n;
    
        for(int i=0;i<n;i++)
        {
             int k;
             cin>>k;
             vec.push_back(k);
        }
        
    
    sort(vec);
    for(int i=0;i<n;i++)
        {
            cout<<vec[i]<<" ";
        }
       cout<<endl;

}
