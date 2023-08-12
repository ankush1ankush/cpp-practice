#include<bits\stdc++.h>
using namespace std;
void strcopy(char s1[],char s2[])
{
   int len1=strlen(s1);
   int len2=strlen(s2);
  
   
   for(int i=0;i<=len2;i++)
   {
         s1[i]=s2[i];
   }  
}
int main()
{
    char str1[1000];
    char str2[1000];
    cin>>str1>>str2;
  
    cout<<"brfore copy:\n";
    cout<<"str1: "<<str1<<"\n";
    cout<<"str2: "<<str2<<"\n";
    strcopy(str1 ,str2);
    cout<<"after copy:\n";
    cout<<"str1: "<<str1<<"\n";
    cout<<"str2: "<<str2<<"\n";
    return 0;
}