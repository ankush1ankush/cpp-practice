#include<bits/stdc++.h>
using namespace std;
template<typename x,typename y>
x add(x num1, y num2) {
    return (num1 + num2);
}
template<typename T>
class Stack{
    private:
       vector<T> vec;

    public:
       bool isEmpty()
       {
         return vec.size()==0;
       }
       void push(T ele)
       {
           vec.push_back(ele);
       }
       T top()
         {
            if(isEmpty())
            {
                cout<<"stack is Empty"<<endl;
                return 0;
            }
            return vec[vec.size()-1];
         }
        void pop()
        {
            if(isEmpty())
            {
                cout<<"stack is Empty"<<endl;
                return ;
            }
            vec.pop_back();
        }
        int size()
        {
            return vec.size();
        }
};

int main()
{
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
    cout<<s3.size()<<endl;
    cout<<add<int,int>(4,5)<<endl;
    return 0;
}