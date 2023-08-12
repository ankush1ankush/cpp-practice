#include<bits/stdc++.h>
using namespace std;
class Queue{
    int *arr;
    int capacity;
    int isfull;
    int isempty;
    int fi;
    int ni;
    public:
    Queue()
    {
         arr=new int[5];
         capacity=sizeof(arr)/sizeof(int);
         isfull=-1;
         isempty=1;
         fi=-1;
         ni=0;
    }
    Queue(int cap)
    {
         arr=new int[cap];
         capacity=sizeof(arr)/sizeof(int);
         isfull=-1;
         fi=-1;
         ni=0;
    }
    void push(int data)
    {
        if(isfull==1){
            cout<<"queue is full"<<endl;
            return ;
        }
        if(fi==-1&&isfull==-1)
        {
          fi=ni;
          arr[ni]=data;
          ni++; 
          isempty=-1; 
        }
        else if(fi==0&&ni<capacity&&ni>fi&&isfull==-1)
        {   
            arr[ni]=data;
            isempty=-1;
            ni++;
            if(ni==capacity)
            {
                isfull=1;
                ni=0;
            }
            
        }
        else if(fi>0&&ni<capacity&&ni>fi&&isfull==-1)
        {
            arr[ni]=data;
            ni++;
            isempty=-1;
            if(ni==capacity)
            {
                ni=0;
            }

        }
        else if(ni<fi&&ni<capacity&&fi>0&&isfull==-1)
        {
            arr[ni]=data;
            ni++;
            isempty=-1;
            if(ni==fi)
            {
                isfull=1;
            }
        }

    }
    void pop()
    {
        if(fi!=-1&&isempty==-1)
        {

           if(fi<ni&&ni<capacity)
           {
               fi++;
               isfull=-1;
               if(fi==ni)
               {
                fi=-1;
                isempty=1;
               }
           }
           else if(fi==ni&&isempty==-1)
           {
              
              
                fi++;
                isfull=-1;
                if(fi==capacity)
                {
                    fi=0;
                    if(fi==ni)
                    {
                        isempty=1;
                        fi=-1;
                    }
                }
              


           }
           else if(fi>ni)
           {
            fi++;
              if(fi==capacity)
              {
                fi=0;
                if(fi==ni)
                {
                    fi=-1;
                    isempty=1;
                }
              }
           }
        }
        else
        {
            cout<<"queue is empty"<<endl;
        }

    }
    int front()
    {
        if(isempty==-1)
        {
            return arr[fi];
        }
        else{
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return 0;
    }
    int size()
    {
        int Size=(ni-fi+capacity)%capacity;
        return Size;
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
    q1.pop();
     
    q1.push(6);
    cout<<q1.front()<<endl;
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    cout<<q1.front()<<endl;
    q1.push(9);
    cout<<q1.front()<<endl;
    cout<<q1.size()<<endl;
}