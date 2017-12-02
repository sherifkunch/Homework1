#include <iostream>
#include <stack>

using namespace std;


class MyQueue
{
    stack<int> firstStack;
    stack<int> secondStack;
public:
    void enQueue(int x) /// add a new element to the end of the queue.
    {
        firstStack.push(x);
    }
    void deQueue() ///remove the element from the front of the queue and return it.
    {
        if(secondStack.empty())
        {
            while(!firstStack.empty()) //dokato parviq stack ne e prazen
            {
                secondStack.push(firstStack.top());
                firstStack.pop();
            }
        }
        secondStack.pop();
    }
    void print()
    {
        if(secondStack.empty())
        {
            while(!firstStack.empty())
            {
                secondStack.push(firstStack.top());
                firstStack.pop();
            }
        }
        cout<<secondStack.top()<<endl;
    }
};
int main()
{
    int number;
    cin>>number;

    MyQueue q;
    for(int i = 0; i<number; i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int x;
            cin>>x;
            q.enQueue(x);
        }else
        {
            if(a==2)q.deQueue();
            if(a==3)q.print();
        }

    }



    return 0;
}
