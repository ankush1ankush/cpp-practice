#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s,int n,int i)
{
    if(s[i]==s[n-1] && i<=n)
    {
       bool present= palindrome(s,n-1,i+1);
       return present; 
    }
    else{
      if(i>n)
      {
        return true;
      }
      else{
        return false;
      }
    }

}
int main()
{
   string s="ankussuna";
   cout<<palindrome(s,9,0);   

}