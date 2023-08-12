#include <bits/stdc++.h>

using namespace std;

class Stack{
    private:
       int *arr;
       int nextindex;  // point pointing to next index to accuired by the element in the stack
       int capacity;
    public:
       Stack()        // default constructor
       {   
           capacity=4;               
           arr=new int[capacity];
           nextindex=0;
       }
       Stack(int cap)  // parametaries constructor
       {
          capacity=cap;
          arr=new int[capacity];
          nextindex=0;
       }
       bool isEmpty(){
        /*if(nextindex==0)
        {
            return true;
        }
        else{
            return false;
        }*/
        return nextindex==0; // similar as the above code
       }
       void push(int ele)
       {
          if(nextindex==capacity)
          {
            int *newArr=new int[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newArr[i]=arr[i];

            }
            delete []arr;
            arr=newArr;
            capacity=2*capacity;
          }
          arr[nextindex]=ele;
          nextindex++;
          return;
       }
       void pop()
       {
        if(isEmpty())
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        nextindex--;
        return;
       }
       int top()
       {
         if(isEmpty())
         {
            cout<<"stack is empty"<<endl;
            return -1;
         }
         return arr[nextindex-1];
         
       }
       int size()
       {
          return nextindex;
       }

};
int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.pop();
    cout<<s1.top()<<endl;
    /*s1.pop();
    s1.pop();
    s1.pop();
    cout<<s1.top()<<endl;
    Stack *s2=new Stack(5);
    s2->push(1);
    s2->push(2);
    s2->push(3);
    cout<<s2->top()<<endl;
    cout<<s2->size()<<endl;*/
    return 0;
}

