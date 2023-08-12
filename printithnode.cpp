#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void printlist (node *head)
{
    node *tem;
    tem=head;
    while(tem!=NULL)
    {
        cout<<tem->data<<" ";
        tem=tem->next;
    }
}
int  length(node *head)
{
    node *tem;
    tem=head;
    int len=0;
    while(tem!=NULL)
    {
        len++;
        tem=tem->next;
    }
    return len;
}
node *List()
{
    int data;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;

    while(data!=-1)
    {
        node *n=new node(data);
        if(head==NULL&&tail==NULL)
        {
            head=n;
            tail=n;
        }
        else{
            tail->next=n;
            tail=n;
        }
        cin>>data;

    }
    return head;
   
}
void printIth(node * head,int i)
{
   node *tem=head;
   int k=0;
   if(i>=0){
   while(tem!=NULL&&k<i){
    tem=tem->next;
    k++;
     }
     if(tem!=NULL)
     {
        cout<<tem->data<<endl;
     }
     else{
        cout<<-1<<endl;
     }
   }
   else{
    cout<<-1<<endl;
   }

   
}

int main()
{
   node *head=List();
   int len=length(head);
   cout<<len<<endl;
   printIth(head,0);
}