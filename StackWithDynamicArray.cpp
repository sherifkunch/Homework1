#include <iostream>

using namespace std;


class RStack{
private:
    int* a;
    int capacity;
    int topIndex;

    bool full() const;// checking if the stack is full
    void copyStack(RStack const& );//Copy of the stack
    void eraseStack();//deleting the memory
    void resize();///Razshirqvane na steka
    void copy(int const*);//Copy the memory of the stack from another plache

public:
    RStack();
    ~RStack();
    RStack& operator=(RStack const&);
    RStack(RStack const&);

    bool empty() const;
    void push(int const& x);
    int pop();
    int top() const;
};
const int INITIAL = 16;
RStack::RStack(): capacity(INITIAL),topIndex(-1) {}

RStack::~RStack()
{
    eraseStack();
}
bool RStack::empty() const
{
    return topIndex == -1;
}
bool RStack::full() const
{
    return topIndex == capacity-1;
}
RStack& RStack::operator=(RStack const& rs)
{
    if(this != &rs)
    {
        eraseStack();
        copyStack(rs);
    }
    return *this;
}

void RStack::copyStack(RStack const& rs)
{
    topIndex=rs.topIndex;
    capacity=rs.capacity;
    a = new int[capacity];
    copy(rs.a);
}
void RStack::copy(int const* other)
{
    for(int i=0; i<capacity; i++)
        a[i] = other[i];
}
void RStack::eraseStack()
{
    delete[] a;
}

RStack::RStack(RStack const& rs)
{
    copyStack(rs);
}
void RStack::resize()
{
    int* olda = a;
    a = new int[2* capacity];
    copy(olda);
    capacity = capacity *2;
    delete[] olda;
}
int RStack::top() const
{
    if(empty())
    {
        cerr<<"Stack is empty!";
        return 0;
    }
    return a[topIndex];
}
void RStack::push(int const& x)
{
    if(full())
    {
        cerr<<"the stack is full\n";
    }
    a[++topIndex] = x;
}

int RStack::pop()
{
    if(empty())
    {
        cerr<<"The stack is empty.You cannot pop!";
        return 0;
    }
    return a[topIndex--];
}

int main()
{
    RStack rs;
    rs.push(5);
    rs.push(6);
    return 0;
}
