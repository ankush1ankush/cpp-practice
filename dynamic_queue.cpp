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
           int *newarr=new int[2*capacity];
           
           
           int i=0;
           
           int j=0;
           for(int i=fi;i<capacity;i++)
           { 
               newarr[j]=arr[i];
               j++;
            }
            for(int i=0;i<fi;i++)
           { 
               newarr[j]=arr[i];
               j++;   
            }
           fi=0;
           ni=capacity;
           capacity=capacity*2;
           delete []arr;
           arr=newarr;
           arr[ni]=data;
           ni++;
           size++;
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
        if(size==0)
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
        if(size==0)
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        else{
        return arr[fi];
        }
    }
    int Capacity()
    {
        return capacity;
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
    
    q1.push(7);
    
    q1.push(8);
    
    q1.push(9);
    q1.push(10);
    q1.pop();
    q1.push(11);
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    
    cout<<q1.Size()<<endl;
    cout<<q1.front()<<endl;
    cout<<q1.Capacity()<<endl;
    
}