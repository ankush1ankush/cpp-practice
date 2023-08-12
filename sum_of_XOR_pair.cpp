#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[1001];
    int n,res=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<32;i++)
    {   
        int countz=0;
        int counto=0;
        int F=1;
        for(int j=0;j<n;j++)
        {
               if(((arr[j])&(F<<i))>0)
               {
                counto++;
               }
               else{
                countz++;
               }
        }
        int p=counto*countz;
        res=res+((1<<i)*p); // helping in calculating the power of two's formed because of the iTH bit high in the pair

    }
    cout<<res<<endl;
    return 0;
}