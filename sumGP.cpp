#include<bits/stdc++.h>
using namespace std;
double sumGP(int k)
{
    if(k==0)
    {
        return 1;
    }
    double smallans=sumGP(k-1);
    return smallans+(1/pow(2,k));
    
}
int main()
{
    cout<<sumGP(1);
}
