#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node <T>* NextNode;
    Node(T data)
    {
       this->data=data;
       
    }
    
};
template<typename T>
class Queue{
         Node <T>* head=NULL;
         Node <T>*tail=NULL;
         int size=0;

      public:
      Queue()
      {
         head=NULL;
         tail=NULL;
         size=0;
      }
      void push(T data)
      {
         Node <T>*newNode=new Node(data);
         if(head==NULL&&tail==NULL){
            head=newNode;
            tail=newNode;
            size++;
         }
         else{
            tail->NextNode=newNode; // all node at tail
            tail=newNode;  //shifting of tail
            size++;
         }   
      }
      void pop()
      {
        if(size==0)
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        else{
            Node<T>*x;
            x=head;
            head=head->NextNode;
            size--;
            delete x;
        }
      }
      int getSize()
      {
        return size;
      }
      T front()
      {
        if(size==0)
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return head->data;
        
      }
      bool isEmpty()
      {
        return size==0;
      }
      
};
int main()
{
    Queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    cout<<q1.getSize()<<endl;
    cout<<q1.front()<<endl;
    
    q1.pop();
    cout<<q1.getSize()<<endl;
    q1.push(5);
    cout<<q1.front()<<endl;
    cout<<q1.getSize()<<endl;
    while(!q1.isEmpty())
    {
      cout<<q1.front()<<endl;
      q1.pop();
    }


}