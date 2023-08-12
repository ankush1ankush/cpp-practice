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
int main()
{   
    cout<<"enter the list data:";
    node *head=takeinput();
    printList(head);
    int index;
    int data;
    cout<<endl;
    cout<<"index"<<" : ";
    cin>>index;
    /*cout<<"data"<<" : ";
    cin>>data;
    insertIth(head,index,data);*/
    deleteith(head,index);// this is temprary delete not permanent(memory leak)
    printList(head);
}