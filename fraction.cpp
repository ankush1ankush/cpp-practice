#include<bits\stdc++.h>
using namespace std;
class fraction{
    private:
       int numirator;
       int denominator;
    public:
       fraction(int numirator,int denominator)
       {
        this->numirator=numirator;
        this->denominator=denominator;
       }
       void display(){
        cout<<numirator<<"/"<<denominator<<endl;
       }
       void add(fraction F)
       {
         int lcm=denominator*(F.denominator);
         int x= (lcm/denominator);
         int y= (lcm/F.denominator);
         int num=(x*numirator)+(y*(F.numirator));
         this->numirator=num;
         this->denominator=lcm;
       }
    void simplify()
    {
        int gcd=__gcd(numirator,denominator);
        this->numirator=(this->numirator)/gcd;
        this->denominator=(this->denominator)/gcd;
    }
};
int main()
{
    fraction F1(8,16);
    fraction F2(2,8);
    
    F1.add(F2);
    F1.simplify();
    F1.display();
    return 0;
}