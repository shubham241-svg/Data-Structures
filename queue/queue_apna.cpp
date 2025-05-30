#include <iostream>
#include <stack>
#include <queue>
using namespace std;


class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Queue{
    Node* head;
    Node* tail;

    public : 
        Queue(){
            head = tail = NULL;
        }

        void push(int data){
            Node* newNode = new Node(data);
            if(head == NULL){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }

        }

        void pop(){
            if(empty()){
                cout << "queue is empty\n";
                return ;
            }
            Node* temp = head;
            head = head->next;
            delete temp;

        }


        int front(){
            if(empty()){
                cout << "queue is empty\n"; 
                return -1 ;
            }

            return head->data;
        }

        bool empty(){
            return head == NULL;
        }
};

// implementing the queue using an array 1

class Queue1{
    int* arr;

    int capacity;
    int currSize;

    int f, r;

    public: 
        Queue1(int capacity){
            this->capacity = capacity;
            arr = new int[capacity];
            currSize = 0;

            f = r = -1;
        }

        void push(int data){
            if(currSize == capacity){
                cout << "Queue is full \n";
                return;
            }
            r = (r + 1) % capacity;
            arr[r] = data;
            currSize++ ;


        }



};

// implementing circular queue 

class Queue3{
    int* arr;

    int capacity;
    int currsize;
     
    int f, r;
public:
    Queue3(int capacity){ // constructor
        this->capacity = capacity;
        arr = new int[capacity];
        currsize = 0 ;
        f = 0;
        r = -1;
    }


    // creating push , pop and front function

    void push(int data){
        if(currsize == capacity){
            cout << "Queue is full";
            return;
        }

        r = (r+1)%capacity;
        arr[r] = data;
        currsize++;
    }

    void pop(){
        if(empty()){
            cout << "Queue is  empty\n";
            return ;
        }

        f = (f + 1)% capacity;
        currsize--;
    }

    int front(){
        if(empty()){
            cout<< "Queue is empty\n";
            return -1;
        }

        return arr[f];
    }

    bool empty(){
        // if(currsize == 0){
        //     return true;
        // }

        // return false;

        return currsize == 0;
    }

    ~Queue3(){
        delete[] arr;
    }
};

// implementing queue

class Queue4{
    stack<int> s1;
    stack<int> s2;

    public: 
        void push(int data){ // O(N)
            // step 1: s1 --> s2
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            // s1 push data
            s1.push(data);

            // now put the s2 to s1
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        void pop(){
            s1.pop();
        }

        int front(){
            return s1.top();
        }

        bool empty(){
            return s1.empty();
        }


};

// implementing stack using an queue
class stack1{
    queue<int> q1;
    queue<int> q2;

    public: 
        void push(int data){

        // step1 q1 --> q2

        while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        //  q1.push()
        q1.push(data);

        // step2 q2--> q3
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        }

        void pop(){
            q1.pop();
        }


        int top(){
            return q1.front();

        }

        bool empty(){
            return q1.empty();
        }

};


int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout << q.front()<< endl;
        q.pop();
    }

    Queue3 q3(4);
    q3.push(1);
    q3.push(2);
    q3.push(4);
    q3.push(5);

    cout << q3.front() << endl;
    q3.pop();
    cout << q3.front()<< endl;
    q3.push(5);


    return 0;
}