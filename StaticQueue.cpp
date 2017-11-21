#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

template <class T>
class StaticQueue{
    T a[MAX_SIZE];
    int front,back,n;

    bool full() const{
    return n==MAX_SIZE;
    }

public:
    bool empty() const{
    return n==0;
    }
    StaticQueue() : front(0),back(0),n(0){}

    T head() const{
    if(empty()){
        cerr<<"opashkata e prazna!\n";
        return T();
        }
    return a[front];
    }
    void push(T const& x){
        if(full())
            cerr<<"Opashkata e palna!\n";
        else{
            a[back] = x;
            n++;
            back++;
            back=back%MAX_SIZE;
        }
    }
    T pop(){
    if(empty()){
        cerr<<"Opashkata e prazna!\n";
        return T();
    }
    T x = a[front];
    n--;
    front++;
    front=front % MAX_SIZE;
    return x;
    }
};

int main()
{
    StaticQueue<int> st;
    st.push(5);
    st.push(6);
    st.push(7);

    return 0;
}
