#include<bits\stdc++.h>
using namespace std;
int comp(char s1[],char s2[])
{
   int len1=strlen(s1);
   int len2=strlen(s2);
   int result=0;
   if(len1==len2){
   for(int i=0;i<len1;i++)
   {
         result=result+abs(s1[i]-s2[i]);
   }
   }
   else {
    result=1;
   }
   
   return result;
}
int main()
{
    char str1[1000];
    char str2[1000];
    cin>>str1>>str2;
    int result=comp(str1,str2);
    if(result==0)
    {
        cout<<"equal"<<"\n";
    }
    else{
        cout<<"not equal"<<"\n";
    }
    return 0;
}