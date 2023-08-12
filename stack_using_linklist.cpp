#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *nextNode;
    Node(int data){
        this->data=data;
        nextNode=NULL;
    }
    Node(){

        nextNode=NULL;
    }
};

class Stack{
     Node *head=NULL;
     Node *tail=NULL;
     
     int count=0;
     public:
    
     void push(int data)
     { 
       Node *newNode=new Node(data);
      
       if(head==NULL&&tail==NULL)
       {
            head=newNode;
            tail=newNode;
       }
       else{
          newNode->nextNode=head;
          head=newNode;
       }
       count ++;
     }
     bool isEmpty()
     {
           return head==NULL;
        }
     int top()
     {
        if(isEmpty())
        {   
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else {
            return -1;
        }
     }
     void pop()
     {
        Node *saveNode;
        saveNode=head;
        if(isEmpty())
        {
             cout<<"stack is empty"<<endl;
        }
        else{
            
            head=head->nextNode;
            count--;
            saveNode->nextNode=NULL;
            delete saveNode;
        }

        
     }
    int elementcount()
    {
        return count;
    }
    void print_stack()
    {   
        Node *tem=head;
        while(tem!=NULL)
        {
            cout<<tem->data<<" ";
            tem=tem->nextNode;
        }
        cout<<endl;
    }

};

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print_stack();
    cout<<s1.elementcount()<<endl;
    s1.pop();
    s1.print_stack();
}