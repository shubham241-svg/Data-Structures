#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* converttoll(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
        
    }

    return head;

}
// printing a linkedlist

void print(Node *head){
    while(head != NULL){
        cout << head-> data<< " ";
        head = head->next;
    }
    cout<< endl;
}



// Deletion

        // Removal of head

Node* removehead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}


        // Removal of Tail
Node* removetail(Node*  head){
    if(head == NULL || head->next == NULL){   // what if the linked list is empty or just contains an single element
        return NULL;
    }

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

        // Removal of kth element 

Node* removek(Node* head, int k){
    if(head == NULL) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt ++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}


        // Removal of the element 

Node* removek(Node* head, int el){
    if(head == NULL) return head;
    if(head->data == el){ // if the given element is the head of linked list
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == el){  //  this is very simillar to removal of kth element we just have to check if temp data is equal to the element 
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}


// Insertion 

        // insertion at the head of LL 

Node* insertHead(Node* head, int val){
    return new Node(val, head);
}


        // Insertion at the tail of LL

Node* insertattail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* newNode = new Node(val); // we are adding the element to the end so it should point to the null pointer
    temp-> next = newNode ;

    return head;
}


        // Insertion between the 1st and end element

Node* insertposition(Node* head, int el, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(el);
        }
        else return NULL;
    }
    if(k== 1){
        return new Node(el, head);
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt ++;
        if(cnt == (k-1)){
            Node* x = new Node(el, temp-> next);
            temp-> next = x; // 1st the we need a pointer pointing to the next element of temp so first we make the element point to the next element
            break;           // after the x is pointing to temp->next then we make the temp point to the x;
        }
        temp = temp->next;
    }

    return head;

}

        // Insertion before value

Node* insertbeforevalue(Node* head, int el, int val){
    if(head == NULL){
         return NULL;
    }
    if(head->data == val){
        return new Node(el, head);
    }

    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x = new Node(el, temp-> next);
            temp-> next = x; // 1st the we need a pointer pointing to the next element of temp so first we make the element point to the next element
            break;           // after the x is pointing to temp->next then we make the temp point to the x;
        }
        temp = temp->next;
    }

    return head;

}
int main(){
    vector<int> arr= {12, 5, 8, 9};
    Node* head = converttoll(arr);
    head = removehead(head);

    head = removetail(head);
    print(head);

}