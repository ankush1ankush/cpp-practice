
using namespace std;
int power(int x,int n)
{  /// base case
    if(n==0)
    {
       return 1; 
    }
    ///  recursive case f(k) where k=n-1;
    int smalloutput=power(x,n-1);
    //  calculation for f(k+1) where k+1=(n-1+1)=n;
    return x*smalloutput;
}
int main()
{
    cout<<power(5,3);
}
