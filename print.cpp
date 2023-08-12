#include<bits/stdc++.h>
using namespace std;
void print(int n)
{
    if(n==1)
    {
        cout<<1<<" ";
        return; // return is nessaccery with base case in both void and non void recursive function so that it could get to know that where is to stop
    }j
   
    print(n-1);
    cout<<n<<" ";
    return; // optional
}
int main()
{
   print(6);
}