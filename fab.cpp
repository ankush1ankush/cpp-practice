#include<bits/stdc++.h>
using  namespace std;

int fab(int n){
    
    if(n==0)
    {
        return 0;

    }
     
    if(n==1)
    {
        return 1;
    }
    
    int first=fab(n-1);
    int second=fab(n-2);
    return first+second;

}
int main()
{
    cout<<fab();
}