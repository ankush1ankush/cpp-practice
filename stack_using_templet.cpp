#include <bits/stdc++.h>

using namespace std;
template<typename T>
class Stack{
    private:
       T *arr;
       int nextindex;  // point pointing to next index to accuired by the element in the stack
       int capacity;
    public:
       Stack()        // default constructor
       {   
           capacity=4;               
           arr=new T[capacity];
           nextindex=0;
       }
       Stack(int cap)  // parametaries constructor
       {
          capacity=cap;
          arr=new T[capacity];
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
       void push(T ele)
       {
          if(nextindex==capacity)
          {
            T *newArr=new T[2*capacity];
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
       T top()
       {
         if(isEmpty())
         {
            cout<<"stack is empty"<<endl; // We use 0 as the return because 0 is compatible for the datatype
            return 0;
         }
         return arr[nextindex-1];
         
       }
       int size()
       {
          return nextindex;
       }

};
int main(){
    Stack <int> s1;
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
    Stack <char> s2;
    s2.push('1');
    s2.push('2');
    s2.push('3');
    s2.push('4');
    s2.push('5');
    s2.push('6');
    s2.pop();
    cout<<s2.top()<<endl;
    Stack<string> s3;
    s3.push("ankush");
    s3.push("ravi");
    s3.push("angad");
    s3.push("anshul");
    cout<<s3.top()<<endl;
    return 0;
}

