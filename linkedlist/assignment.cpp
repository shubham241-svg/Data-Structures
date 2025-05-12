#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class Linkedlist{

    public: 
        Node* head;
        Linkedlist(){
            head = NULL;
        }

        // creating a destructor to explicitly delete the ll which dynamically created

        ~Linkedlist(){

            if(head != NULL){
                delete head;
                head = NULL;
            }}

        Node* intersection(Node* heada, Node* headb){

            int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

Node* intersection(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    Node* tempA = headA;
    Node* tempB = headB;

    // Move the pointer of longer list ahead
    if (lenA > lenB) {
        int diff = lenA - lenB;
        while (diff--) tempA = tempA->next;
    } else {
        int diff = lenB - lenA;
        while (diff--) tempB = tempB->next;
    }

    // Now traverse both together
    while (tempA != NULL && tempB != NULL) {
        if (tempA == tempB) return tempA; // intersection found
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return NULL; // no intersection
}


        }
        

       
};