#include <iostream>

using namespace std;
const int MAX=100;

class Stack
{
private:
    int a[MAX];
    int topIndex;//index on the top
    bool full() const;
public:
    Stack();

    bool empty() const;
    void push(int const& x);//pushing an element
    int pop();//removing an element
    int top() const; //return the top of the stack

};

Stack::Stack():topIndex(-1) {}

bool Stack::full() const
{
    return topIndex==MAX-1;
}

bool Stack::empty() const
{
    return topIndex==-1;
}

void Stack::push(int const& x)
{
    if(full())
    {
        cerr<<"Stack is full\n";
    }
    else
        a[++topIndex]=x;
}
int Stack::pop()
{
    if(empty())
    {
        cerr<<"Empty stack!\n";
        return 0;
    }
    return a[topIndex--];
}
int Stack::top() const
{
    if(empty())
    {
        cerr<<"empty stack\n";
        return 0;
    }
    return a[topIndex];
}

int main()
{

    Stack help1;
    Stack help2;

    Stack a;
    Stack b;

    int g;
    cin>>g;

    int n, m, x;
    cin>>n>>m>>x;

    char helper[n*2];
    char str1[n*2];
    char str2[n*2];

    int num1,num2;
    for (int i = 0; i < n*2; i++)
    {
        if (str1[i] >= '0' && str1[i] <= '9')
        {
            num1=str1[i] - '0';
            help1.push(num1);
        }
    }

    int elemA;
    for (int j = 0; j < n; j++)
    {
        elemA=help1.top();
        help1.pop();
        a.push(elemA);
    }
    for (int k = 0; k < m*2; k++)
    {


        if (str2[k] >= '0' && str2[k] <= '9')
        {
            num2=str2[k] - '0';

            help2.push(num2);
        }

    }

    int elemB;
    for (int p = 0; p < m; p++)
    {
        elemB=help2.top();
        help2.pop();

        b.push(elemB);

        int sum = 0;
        int stAelem, stBelem;
        int countTokens=0;

        while (sum < x)
        {
            stAelem=a.top();
            a.pop();
            sum+=stAelem;

            stBelem=b.top();
            b.pop();
            sum+=stBelem;

            countTokens++;

        }



        cout<<"Count: "<<countTokens<<endl;

        return 0;
    }
}
