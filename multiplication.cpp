#include<bits/stdc++.h>
using namespace std;
int mul(int m,int n)
{
    int sum=0;
    if(n==0)
    {
        return 0;
    }
    sum=mul(m,n-1);
    return m+sum;
}
int main()
{
    cout<<mul(10,7);
}