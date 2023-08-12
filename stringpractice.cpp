#include<bits\stdc++.h>
using namespace std;

int main()
{
    string *s=new string();
    *s="hello world";
    cout<<s<<"\n";
    cout<<*s;
    vector <string> v;
    for(int i=0;i<4;i++)
    {
        string m;
        getline(cin,m);
        v.push_back(m);
    }
    for(int i=0;i<4;i++)
    {
        cout<<v[i]<<'\n';
    }
}
