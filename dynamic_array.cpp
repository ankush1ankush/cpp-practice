# include<bits\stdc++.h>
using namespace std;
class dynamic{
     
     int capacity;
     int nextindex;
     int *data;

     public:
        
        dynamic()
        {
          capacity=5;
          data=new int[5];
          nextindex=0;
        }
        void add(int element)
        {
          if(nextindex<capacity)
          {
               data[nextindex]=element;
          
          }
          else if(nextindex==capacity){
               int *newdata= new int[2*capacity];
               for(int i=0;i<nextindex;i++)
               {
                    newdata[i]=data[i];
               }
               delete [] data;
               data=newdata;
               data[nextindex]=element;
               capacity=2*capacity;
          }
          nextindex++;
        }
        int getelement(int i)
        {
          if(i<nextindex && i>=0 )
          {
               return data[i];
          }
          else{
               return -1; 
           }
        }
        void add(int element,int i)
        {
             if(i<=nextindex && i>=0)
             {
                   if(i<nextindex)
                   {
                    data[i]=element;
                   }
                   else if(i==nextindex){
                          add(element);
                   }
             }
             else{
               cout<<-1<<"\n";
             }
        }

        dynamic( dynamic &d)
        {
          this->capacity=d.capacity;
          this->nextindex=d.nextindex;
          this->data=new int[this->capacity];
          for(int i=0;i<nextindex;i++)
          {  
              this->data[i]=d.data[i];
          }

        }
        void operator = (dynamic const &d)
        {
          this->capacity=d.capacity;
          this->nextindex=d.nextindex;
          this->data=new int[this->capacity];
          for(int i=0;i<nextindex;i++)
          {  
              this->data[i]=d.data[i];
          }
        }
        void get()
        {
          for(int i=0;i<nextindex;i++)
          {
               cout<<data[i]<<" ";
          }
          cout<<endl;
        }
        int size()
        {
          return capacity;
        }

};

int main()
{
     dynamic d1;
     d1.add(7);
     d1.add(9);
     d1.add(8);
     d1.add(2);
     d1.add(5);
     d1.add(3);
     d1.get();
     
     dynamic d2=d1;
     d1.add(9,5);
     d1.get();
     d2.get();


}