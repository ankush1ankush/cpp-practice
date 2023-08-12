#include<bits/stdc++.h>
using namespace std;
int integer(string input,int n,int i) //left to right
{
    if(i==n)
    {
        return 0;
    }
    else{
        int smallint=integer(input,n,i+1);
        int a=input[i]-'0';
        return a*pow(10,n-1-i)+smallint;
    }
}
int integer3(string input,int n) // right to left

{
    if(n==0)
    {
        return 0;
    }
    else{
        int smallint=integer3(input,n-1);
        int a=input[n-1]-'0';
        return smallint*10+a;
    }
}
int main()
{  
    string s="12345";
    cout<<integer3(s,s.length());
}