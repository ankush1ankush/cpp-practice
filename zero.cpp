#include <bits/stdc++.h>
using namespace std;
int zeroes(int num)
{

    int ans=0;
    if(num==0)
    {
        return 0;
    }
    int smallans=zeroes(num/10);
    int rem=num%10;
    if(rem==0)
    {
        ans++;
    }
    return ans+smallans;
}
int main()
{
    cout<<zeroes(10320);
}