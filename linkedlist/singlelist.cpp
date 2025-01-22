#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
// multiple constructors for same class
    public:
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
// multiple constructors 
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

// converting an array to linked list 

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp; // It is simillar to temp -> next;
        mover = temp;
    }
    return head;
}

// prints all the elements in a linked list
void traverseLL(vector<int> &arr){
    Node* head = convertArr2LL(arr);
    Node*  temp = head;
    while(temp){
        cout<< temp->data<<" " ;
        temp = temp->next;
    }
}

// returns the length of linked list 

int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }

    return cnt;
}


// Searching the element in a linkedlist

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}




int main(){
    int arr[5]= {2, 5, 6, 4, 6};
    Node* y = new Node(arr[0]);

    Node x = Node(arr[1]);

    cout<< y->data << " "<< y->next << endl;
    cout<< x.data << " " << x.next << endl;



}