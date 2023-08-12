#include<bits/stdc++.h>
using namespace std;
class node{
    public:
     int data;
     node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node *takeinput() //function to make the list
{
    int data;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;
    while(data!=-1)
    {
        node *n=new node(data);
        if(head==NULL && tail==NULL)
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
void printList(node *head)
{
    node *tem=head;
    while(tem!=NULL)
    {
        cout<<tem->data<<" ";
        tem=tem->next;
    }
   return;
}
void insertIth( node * &head,int index,int data )
{
    node *n=new node(data);
    node *tem=head;
    int i=0;
    if(i<0)
    {
        return;
    }
    if(index==0)
    {
        n->next=tem;
        head=n;
        return;
    }
    else{
        while(i<index-1)
        {
          tem=tem->next;
           i++;
        }
        n->next=tem->next;
        tem->next=n;
        
        return;
    }
}
node *reverselist(node *head)
{
    node *pre=NULL;
    node *crn=head;
    node *n=NULL;
    while(crn!=NULL)
    {  
        n=crn->next;
        crn->next=pre;
        pre=crn;
        crn=n;

    }
    return pre;
}
int main()
{   
    cout<<"enter the list data:";
    node *head=takeinput();
    printList(head);
    cout<<endl;
    head=reverselist(head);
    printList(head);
}