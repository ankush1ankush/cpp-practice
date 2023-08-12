#include<bits\stdc++.h>
using namespace std;

struct node{
    int data;
    node *nextnode=nullptr;
    
};
struct node *head; 

int main()
{
    struct node *node1=new node();
    struct node *node2=new node();
    struct node *node3=new node();
    node1->data=1;
    node1->nextnode=node2;
    node2->data=2;
    node2->nextnode=node3;
    node3->data=3;
    head=node1;
    struct node *n=head;
    while(n!=nullptr)
    {   
        cout<<n->data<<endl;
        
        n=n->nextnode;  
        
        
    }

}