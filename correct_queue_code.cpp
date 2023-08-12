#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int capacity;             // capacity of queue
    int size;                 //size of queue
    int fi;                   //first index
    int ni;                   //next index 
    public:
    Queue(){
       arr=new int[5];
       capacity=5;
       size=0;
       ni=0;
       fi=-1;  
    }
    Queue(int cap){
       arr=new int[cap];
       capacity=cap;
       size=0;
       ni=0;
       fi=-1;  
    }
    void push(int data)
    {
        if(size==capacity)
        {
            cout<<"queue is full"<<endl;
            return;
        }
        if(fi==-1)
        {
            fi=0;
        }
        arr[ni]=data;
        ni=(ni+1)%capacity; // for the cyclic array
        size++;
    }
    bool isempty()
    {
        return size==0;
    }
    void pop()
    {  
        if(isempty())
        {
          cout<<"queue is empty"<<endl; 
          return;
        }
        fi=(fi+1)%capacity;     // for the cyclic array
        size--;
    }
    int Size()
    {
        return size;
    }
    int front()
    {
        if(isempty())
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return arr[fi];
    }
};
int main()
{ 
    Queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);
    q1.pop();
    q1.push(6);
    cout<<q1.front()<<endl;
    
}