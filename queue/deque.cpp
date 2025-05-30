#include <iostream>
#include <deque>
using namespace std;


// implementing queue using a deque

class Queue1{
    deque<int> deq;
    public: 
    void push(int data){
        deq.push_back(data);
    }

    void pop(){
        deq.pop_front();
    }

    int front(){
        return deq.front();
    }

    bool empty(){
        return deq.empty();
    }

};

// implementing stack using a deque

class stack1{
    deque<int> deq;
    public: 
    void push(int data){
        deq.push_front(data);
    }

    void pop(){
        deq.pop_front();
    }

    int top(){
        return deq.front();
    }

    bool empty(){
        return deq.empty();
    }
};

int main(){
    deque<int> deq;

    deq.push_front(2);
    deq.push_front(1);

    deq.push_back(3);
    deq.push_back(4);

    // 2 1 3 4
    
    deq.pop_front();

    cout << deq.front(); 
    cout << deq.back() << endl;

    Queue1 q1;

    for(int i = 1; i<= 5; i++){
        q1.push(i);
    }

    for(int i = 1; i<= 5; i++){
        cout << q1.front() << endl;
        q1.pop();
    }

    stack1 st;

    for(int i = 1; i<= 5; i++){
        st.push(i);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}