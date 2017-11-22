#include <iostream>

using namespace std;
const int MAX=100;

class Stack{
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

Stack::Stack():topIndex(-1){}

bool Stack::full() const
{
    return topIndex==MAX-1;
}

bool Stack::empty() const
{
    return topIndex==-1;
}

void Stack::push(int const& x){
    if(full())
    {
        cerr<<"Stack is full\n";
    }else
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

    return 0;
}
