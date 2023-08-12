#include<bits/stdc++.h>
using namespace std;
int digits(int num)
{
   int rem;
   int ans=0;
   int smalloutput=0;
   if(num>0) //base case
   {
    ans++;
    num=num/10;
     if(num==0)
    {
        return ans; 
    }
   }
  
   if(num>0)
   {
    smalloutput=digits(num);    // f(k)         k=n-1;
   }
    
   return ans+smalloutput;     // f(k+1)        k+1=n;
}
int main()
{
    cout<<digits(1000);
}