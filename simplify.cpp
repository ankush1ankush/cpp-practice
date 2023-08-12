#include<bits\stdc++.h>
using namespace std;
class fraction{
    int num;
    int dmn;
    public: 
    fraction(int num,int dmn)
    {
        this->num=num;
        this->dmn=dmn;
        simplify();

    }
    fraction()
    {};
    void print()
    {
        cout<<num<<"/"<<dmn<<"\n";
    
    }
    fraction(fraction &f)
    {
        this->num=f.num;
        this->dmn=f.dmn;
        
    }
    void simplify()
    {
       int a=num;
       int b=dmn;
       while(b!=0)
       {
        int rem=a%b;
        a=b;
        b=rem;
       }
       num=num/a;
       dmn=dmn/a;
       
    }
    fraction operator + (fraction &fra)
    {
        fraction p;
        int x=((this->num)*(fra.dmn))+((fra.num)*(this->dmn));
        int y=(this->dmn)*(fra.dmn);
        p.num=x;
        p.dmn=y;
        p.simplify();
        return p;
    }
    fraction operator * (fraction &fra)
    {
        fraction p;
        int x=(this->num)*(fra.num);
        int y=(this->dmn)*(fra.dmn);
        p.num=x;
        p.dmn=y;
        p.simplify();
        return p;
    }
};

int main()
{
    
    fraction f1(9,21);
    fraction f2(10,4);
    f2.simplify();
    f2.print();
}