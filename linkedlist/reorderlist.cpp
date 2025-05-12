#include <bits/stdc++.h>

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


Node* middle(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = next;
    }

    return prev;

}


void reorderlist(Node* head){
    if(head == nullptr || head->next == nullptr){
        return ;
    }
    Node* mid = middle(head);
    Node*  k = reverse(mid->next);
    mid->next = NULL;

    Node* c1 = head;
    Node* c2 = k ;
    Node* f1 = NULL;
    Node* f2 = NULL;


    while(c1 != NULL || c2 != NULL){
        f1 = c1->next;
        f2 = c2->next;

        c1->next= c2;
        c2->next = f1;

        c1 = f1;
        c2 = f2;
    }

}




// swapping of the matrix 


// first do the transpose of the matrix

for(int i = 0 ; i < n ;i++ ){
    for(int j = i+ 1; j < n ; j++ ){
        int temp = matrix[i][j];
        a[i][j] = arr[j][i] ;
        arr[j][i] = temp ;

    }
}


//swap the values of the coloumn 

for(int i = 0 ; i< n ; i++) {
    for(int j = 0; j<n/2; j++){
        int temp= a[i][j];
        a[i][j] = a[i][n-j-1]
        a[i][n-j-1] = temp;
    }
}

for(int i = 0 ; i<n ; i ++){
    for(int j = 0; j<n ; j++){
    
    }
}


int round = (int) (n+1)/2 ;

for(int i = 0 ; i<round; i++){
    //top values
    for(int j = i ; j<= n-i-1; j++){
        cout<< a[i][]
    }   

    for(int j = i+ 1; j<= n-i-1; j++){
        sys
    }
}