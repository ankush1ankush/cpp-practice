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

int length(node*head)
{
    if(head==NULL)
    {
        return 0;
    }
    int smallans=length(head->next);
    return 1+smallans;
}
void deleteKthNode( node *&head,int k)                                                           
{
    node * one= head;                         // pointer one pointing to the head of List
    node * two=head;                          // pointer two pointing to head of the list
    while(k--)
    {
        two=two->next;

    }
    while(two->next!=NULL)
    {
        two=two->next;
        one=one->next;
    }
    node *tem=one->next;
    one->next=tem->next;
    delete tem;
    return;

}
node* mergeTwoLists(node* head1, node* head2) {
        node *head=NULL;
    node *tail=NULL;
    node *tem1=head1;
    node *tem2=head2;
    if( head1==NULL){
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    while(tem2!=NULL && tem1!=NULL)
    {
         if(head==NULL && tail ==NULL)
         {
           if((tem1->data)<(tem2->data))
           {
              head=tem1;
              tail=tem1;
              tem1=tem1->next;
           }
           else{
            head=tem2;
            tail=tem2;
            tem2=tem2->next;
           }
         }
         else{
            if((tem1->data)<(tem2->data))
            {
                tail->next=tem1;
                tail=tail->next;
                tem1=tem1->next;
            }
            else{
                tail->next=tem2;
                tail=tail->next;
                tem2=tem2->next;
            }
         }   
    }
    if(tem2 && tail)
    {
        tail->next=tem2;
    }
    else if(tem1 && tail){
        tail->next=tem1;
    }
    return head;
    }
node *mergeListrecursively( node *a,node *b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    node *newHead=NULL;
    if((a->data)<(b->data))
    {
        newHead=a;
        newHead->next=mergeListrecursively(a->next,b);
    }
    else{
        newHead=b;
        newHead->next=mergeListrecursively(a,b->next);
    }
    return newHead;
}
int main()
{
    node* head1=takeinput();
    node * head2=takeinput();
    printList(head1);
    cout<<endl;
    printList(head2);
    node * head=mergeListrecursively(head1,head2);
    cout<<endl;
    printList(head);
}