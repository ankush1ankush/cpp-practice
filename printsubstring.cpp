#include<bits/stdc++.h>
using namespace std;
void print_subs(string input,string output)
{
    if(input=="")
    {
        cout<<output<<endl;
        return;
    }
    print_subs(input.substr(1),output);
    print_subs(input.substr(1),output+input[0]);
}
int main()
{
    /*string input;
    string output="";
    cin>>input;
    print_subs(input,output);
    */
    string s="ankushjk";
    s[9]='o';
    string output="";
    print_subs(s,output);
}