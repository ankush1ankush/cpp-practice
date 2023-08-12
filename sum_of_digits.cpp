#include<bits/stdc++.h>
using namespace std;
int digitsum(int num){
    if(num==0)
    {
        return 0;
    }
    int smallans=digitsum(num/10);
    int rem=num%10;
    return smallans+rem;
}

int main()
{
    cout<<digitsum(0);
}