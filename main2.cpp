
#include <iostream>

using namespace std;
template <typename T>
struct node
{
    T data;
    node<T>* next;
};

template <typename T>
class LStack
{
private:
        node<T>* topNode;
        void copy(node<T>* toCopy);
        void eraseStack();
        void copyStack(LStack const&);
    public:
        LStack();
        LStack(LStack const&); //
        LStack& operator=(LStack const&); //
        ~LStack(); //
        bool empty() const;
        void push(T const& x);
        T pop();
        T top() const;
        T MaxElement();
};

template <typename T>
LStack<T>::LStack() : topNode(NULL) {}

template <typename T>
bool LStack<T>::empty() const {
    return topNode == NULL;
}
template <typename T>
    void LStack<T>::push(T const& x) {
    node<T>* p = new node<T>;
    p->data = x;
    p->next = topNode;
    topNode = p;
}
template <typename T>
    T LStack<T>::pop()
    {
        if(empty())
        {
            cerr<<"prazen stek!\n";
            return 0;
        }

            node<T>* p = topNode;
            topNode=topNode->next;
            T x = p->data;
            delete p;
            return x;

    }

template <typename T>
T LStack<T>::top() const
{
   if(empty())
   {
       cerr<<"prazen stek!";
   }

    return topNode->data;
}
template <typename T>
void LStack<T>::eraseStack()
{
    while(!empty())
        pop();
}
template <typename T>
LStack<T>::~LStack() {
 eraseStack();
}
template <typename T>
void LStack<T>::copy(node<T>* toCopy)
{
    if(toCopy==NULL)
        return;
    copy(toCopy->next);
    push(toCopy->data);
}

template <typename T>
void LStack<T>::copyStack(LStack const& ls) {
 topNode = NULL;
 copy(ls.topNode);
}
template <typename T>
LStack<T>::LStack(LStack const& ls) {
 copyStack(ls);
}
template <typename T>
LStack<T>& LStack<T>::operator=(LStack const& ls)
{
 if (this != &ls) {
 eraseStack();
 copyStack(ls);
 }
 return *this;
}
template <typename T>
T LStack<T>::MaxElement()
{
    T max = topNode->data;
    node<T>* start = topNode;
    start = start->next;
    while(start)
    {
        if (max < start->data) {
            max = start->data;
        }
        start = start->next;
    }

    return max;
}

int main()
{
    LStack<int> st;
    st.push(5);
    st.push(10);
    st.push(20);
    st.push(3);

    std::cout << st.top();

    std::cout << st.MaxElement() << std::endl;

    std::cout << st.top();

    return 0;
}
