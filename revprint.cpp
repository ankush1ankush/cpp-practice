#include<bits/stdc++.h>
using namespace std;
void revprint(char input[])
{
    if(input[0]=='\0')
    {
        return;
    }
    revprint(input+1);
    cout<<input[0];
}
int length(char input[])
{
    if(input[0]=='\0')
    {
        return 0;
    }
    int small_length=length(input+1);
    return small_length+1;
}

int main()
{
    char input[100];
    cin>>input;
    revprint(input);
    cout<<endl;
    cout<<length(input);
}