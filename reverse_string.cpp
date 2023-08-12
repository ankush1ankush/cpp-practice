#include<bits\stdc++.h>
using namespace std;

int length(char input[]){
    int len=0;
    for(int i=0; input[i]!='\0';i++)
    {
      len++;
    }
     return len;
}
void reverse(char input[])
{
   int e=length(input)-1;
   int s=0;
   while(e>s)
   {
    swap(input[e],input[s]);
    e--;
    s++;
   }
}
int main()
{
   char input[100];
   cin.getline(input,100);
   reverse(input);
   cout<<input<<"\n";
}