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
void insertIth( node * &head,int index,int data ) //taking head by reference
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
void deleteith(node * &head,int index)
{
    if(index<0)   
    {
        return;
    }
    if(index==0)
    {   node *tem1=head;
        head=head->next;
        tem1->next=NULL;
        delete tem1;
        return;
    }
    else{
        node *tem=head;
        int i=0;
        while(i<index-1 && tem!=NULL )
        {   
            
            tem=tem->next;
            i++;
            
        }
        if(tem!=NULL &&tem->next!=NULL )
        {
        node *n=tem; 
        node *node_to_delete=NULL; //pointer to store the address of the node to be deleted
        tem=tem->next;
        node_to_delete=tem;    //storing the address of the node to be deleted in to the pointer
        tem=tem->next;
        n->next=tem;
        node_to_delete->next=NULL;
        delete node_to_delete; // deallocating the memory occuppied by the node to be deleted;
        return;
        }
        return;
    }
    return;
}
int length(node*head) // length of linked list recursivley
{
    if(head==NULL)
    {
        return 0;
    }
    int smallans=length(head->next);
    return 1+smallans;
}
bool searchinLL(node *head,int data)
{
    if(head==NULL)
    {
        return false;
    }
    else if(head->data==data)
    {
        return true;
    }
    bool smallans=searchinLL(head->next,data);
    if(smallans==true)
    {
        return true;

    }
    else{
       return false; 
    }
    return false;
}
int main()
{
    node* head=takeinput();
    printList(head);
    cout<<endl;
    cout<<length(head)<<"\n";
    int data;
    cin>>data;
    cout<<searchinLL(head,data)<<endl;
}