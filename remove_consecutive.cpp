#include<bits/stdc++.h>
using namespace std;
void  remove_consecutive(char input[])
{
    if(input[0]=='\0')
    {
        return;
    }
    if(input[0]==input[1])
    {
        for(int i=0;input[i]!='\0';i++)
        {
            input[i]=input[i+1];
        }
        remove_consecutive(input);
    }
    else{
        remove_consecutive(input+1);
    }
}

int main()
{
    char input[100];
    cin>>input;
    remove_consecutive(input);
    cout<<input;
}