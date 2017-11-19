#include <iostream>

using namespace std;
int fib(unsigned int n)
{
    if(n==0)
       return 0;
    else if(n==1)
        return 1;
    else
         if(n==2)
    {
        return 2;
    }
       else
        return fib(n-1)+fib(n-2);
}
unsigned int Fib(unsigned int n)
{
    // first Fibonaci number is Fib(0)
    // second one is Fib(1) and so on

    // unsigned int m;  // m + current_n = original_n
    unsigned int a = 1; // Fib(m)
    unsigned int b = 0; // Fib(m-1)
    unsigned int c = 0; // Fib(m-2)

    while (n--)
    {
        c = b;
        b = a;
        a = b+c;
    }

    return a;
}


int main()
{
    cout<<Fib(7)<<endl;
    cout<<fib(7);
    return 0;
}


/*
    T(n) = T(n-1) + T(n-2) <
     T(n-1) + T(n-1)

     = 2*T(n-1)
     = 2*2*T(n-2)
     = 2*2*2*T(n-3)
     ....
     = 2^i*T(n-i)
     ...
     ==> O(2^n)
*/
