#include <iostream>
#include <vector>
using namespace std;

// in a doubly linked list we need to have back pointer in node
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        // creating back 

        back = back1;
        
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};



// converting the a array to ddl

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i< arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;

    }
    return head;
}



// printing the ddl

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

// deleting the head of the dll

        /* edge cases

        1.) dll -- > empty
        2.) dll --- > 1 element
        
        
        */

// Deleting the head

Node* deleteHead(Node* head){
    if(head == NULL ||  head->next == NULL){
        return NULL;
    }

    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

// Deleting the tail

Node* deletetail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;

    delete tail;
    return head;
}


// Deleting the kth element

Node* removekelement(Node* head, int k){
    if(head == NULL){
        return NULL;
    }

    int cnt = 0;
    Node* knode = head;
    while(knode != NULL){
        cnt ++ ;
        if(cnt == k){
            break;
        }
        knode = knode->next;
    }

    Node* prev = knode->back;
    Node* front = knode->next;

    // if there is an single element
    if(prev == NULL && front == NULL){
        return NULL;
    }

    // if we are the head k =1 ;
    else if(prev == NULL){
        deleteHead(head);
    }

    // if we are at the taile of dll where k = n;

    else if(front == NULL){
        deletetail(head);
    }

    prev->next = front;
    front-> back = prev;

    knode->next = nullptr;
    knode->back = nullptr;
    delete knode;
    return head;

}

// deleting the node
void deleteNode(Node* temp){  // node cannot be head in this scenario
    Node* prev = temp->back;
    Node* front = temp->next;

        // if node is the last element
    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return ;
    }

// if it is in between the 1 to n
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    free(temp);
}



        // Insertion 

// insertion before head

Node* insertbeforehead(Node* head, int val){
    Node* newHead = new Node(val,head,nullptr);
    head->back = newHead;

    return newHead;
}

// insertion before the tail of dll

Node* insertbeforetail(Node* head ,int val){
    if(head->next == NULL){
        return insertbeforehead(head, val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    
    Node* newnode = new Node(val,tail, prev);
    prev->next = newnode;
    tail->back = newnode;
    return head;
}

// insertion before the kth element

Node* insertbeforekthelement(Node* head, int k , int val){
    if(k== 1){
        return insertbeforehead(head, val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt ++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

// insertion before the node

void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);

    prev->next = newNode;
    node->back = newNode;
}



// Reversal of linked list

Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* current = head;
    while(current != NULL){
        prev = current->back;

        current->back = current->next;
        current->next = prev;

        current = current->back;


    }

    return prev->back;
}




int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    return 0;
}

// i am back 