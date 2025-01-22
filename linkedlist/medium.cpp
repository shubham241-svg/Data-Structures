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



// find the middle element in ll

// 1st approach brute force  (space complexity O(1) and TC O(N) + O(N/2)

Node *findmiddle(Node *head){

    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt ++ ;
        temp->next;
    }

    int midnode = (cnt/2) + 1;
    temp = head;

    while(temp != NULL){
        if(midnode == 0) break;
        temp -> next;
        midnode - 1;
        }

    return temp;

}

//optimal approach tortoise and hare approach


Node *findmiddleopt(Node *head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    } 

    return slow;
}







// Reversal of linked list


// in notes a simple approach using stack is done but it cost sc(O(n))

//1st approach with tc(O(N)) and sc O(1)


Node* reversell(Node* head){
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}


// using recursion 

Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* newhead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newhead;
}



// Loop Detction in Linked list

     // brute force using hashing is used to check the repetion of the node

// optimal approach using tortoise and hare approach

        // TC will be O(N) 

bool loopdetector(Node* head){

    Node *slow = head;
    Node *fast = head;
    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;

    }
    return false;

}




// 2nd variation find the starting point of the loop linkedlist 

// optimal approach using tortoise and hare to find the starting point 

        //1  we findout if the ll have loop
        //2 if it has loop then slow = head and fast = collision point 
        //3 move slow and fast by 1 until they colide 


        /* THe Intuition behind it 
        
        nother way to put the intuition can be :
 If the starting point of loop is at distance x from head, 
 cycle length is c and the point where slow and fast meet is at distance y from the starting point,
  as we know the slow and fast starts at head and slow moves by 1 and fast moves by 2 from the start, we can say, 
2*distance traveled by slow pointer = distance traveled by fast pointer.
==> 2*(x+y) = x + c + y   ==> x = c-y
        

        // edge case it the collision happens at the starting point itself then it might fail
        */


Node* startpoint(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
        return slow;
        }

    }
    return NULL;
}


// in brute we could have just used the hashmap approach





// L - 15 How do we find the length of the loop 

        // In brute force as usual we can use hashmap 
        // where we can store the node with there timer 
        // once the node is repeated then we takeout their differences
        // and we return with the length of the loop


// Optimal approach (tortoise and hare )

        
int findlength(Node* slow, Node* fast){
    int cnt = 1; 
    fast = fast->next;
    while(slow != fast){
        cnt ++ ; 
        fast = fast->next;
    }

    return cnt;

}


int lengthofLOOP(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findlength(slow, fast);
        }

    }
    return 0;
}



// Check if a Linkedlist is Palindrome or Not 

// Optimal approach  tC ( O(2N)) && sc(O(1))

Node* reverseLinkedList( Node* head){

    if(head == NULL || head->next == NULL) return head;

    Node* newhead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newhead;
}


bool ispalindromell(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;



    }

    Node* newhead = reverseLinkedList(slow->next);
    Node* first = head;
    Node* sec = head;
    while(sec != NULL){
        if(first->data != sec->data)   {

         reverseLinkedList(newhead);   
         return false;}

         first = first->next;
         sec = sec->next;

    }

    reverseLinkedList(newhead);
    return true;
}



// ODD Even Linkedlist

// brute force approach 

    // Takes SC(O(1)) && TC O(N)
    // create two while loop to iterate the ll for odd = head 

    /*
        1st while loop for odd = head and odd = odd.next.next store them in an array 
        2nd while loop do as same starting even from head.next and move them by head.next.next and store them after odd elements
        3rd while loop take temp != NULL add temp->data = arr[i] and i++ is the index of the array
    */


// Optimal approach O(n/2)

Node* evenodd(Node* head){

    if(head == NULL || head->next == NULL) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenhead = head->next;
    
    while(even != NULL && even->next != NULL){

        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;

    }

    odd->next = evenhead;
    return head;
}


// Remove the nth node from the end of the linked list

    // Brute force  
        // worstcase tc (O(2N))

    /* 
        we will try approach the last element of linked list and calculate its length
         
        2) we find out the difference between the n and cnt
        3)if(cnt == N) delete = head->next return delete
        4) while(temp != NULL) diff-- break if diff = 0
    */


   // Optimal approach

   Node* removenthnode(Node* head, int k){
    Node* fast = head;
    Node* slow = head;
    for(int i = 0 ; i<k; i++){
        fast = fast->next;
    }
    if(fast == NULL){
        Node* delnode = head->next;
        free(head);
        return delnode;
    }

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    Node* delnode = slow->next;
    slow->next = slow->next->next;
    free(delnode);
    return head;
   }


// Delete the middle node of the linked list

//Brute force approach

Node* deletemiddle(Node* head){
    if(head == NULL && head->next == NULL) return NULL;

    Node* temp = head;
    int n = 0;
    while(temp != NULL){
        temp = temp->next;
        n ++;
    }

    int res = n/2;
    temp = head;
    while(temp != NULL){
        res--;
        if(res == 0){
            Node* middle = temp->next;
            temp->next = temp->next->next;
            delete middle;
            break;
        }

        temp = temp->next;
    }

    return head;
}


// Optimal approach just going in one pass

    /* we will use tortoise and hare approach where we skip one slow step*/

Node* deltemiddle(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    fast = fast->next->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

    }

    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}