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

    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }

};

class List{
    Node* tail;

    public:
        Node* head;
        List(){
            head = NULL;
            tail = NULL;
        }

        // creating a destructor to explicitly delete the ll which dynamically created

        ~List(){

            if(head != NULL){
                delete head;
                head = NULL;
            }

        }

        void push_front(int val){

            Node* newNode = new Node(val);

            if(head == NULL){
                head = tail = newNode;
            }

            else{
                newNode ->next = head;
                head = newNode;
            }
        }


        void push_back(int val){
            Node* newNode = new Node(val);

            if(head == NULL){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        void printList(){
            Node* temp = head;

            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;

        }

        void insert(int val, int pos){
            Node* newNode = new Node(val);

            Node* temp = head;
            for(int i = 0 ; i<pos-1; i++){
                if(temp == NULL){
                    cout << "position is INVALID\n";
                    return;
                }
                
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }


        void pop_front(){
            if(head == NULL){
                cout << " ";
            }
            Node* temp = head;
            head = head->next;

            temp->next = NULL;
            delete temp;



        }

        void pop_back(){
            Node* temp = head;
            while(temp->next->next != NULL){
               temp = temp->next; 
            }

            temp->next = NULL ;// temp = tail's prev
            delete tail;
            tail = temp;
        }

        int searchItr(int key){
            Node* temp = head;
            int idx = 0;

            while(temp != NULL){
                if(temp != NULL){
                    return idx;
                }
                temp = temp->next;
                idx ++ ;
            }

            return -1;
        }

        int helper(Node* temp, int key){
            if(temp == NULL){
                return -1;
            }

            if(temp->data == key){
                return 0;
            }

            int idx = helper(temp->next, key);
            if(idx == -1){
                return -1;
            }

            return idx + 1;
        }

        int searchRec(int key){
            return helper(head, key);
        }


        // Reverse of linked list 

        void reversell(){

            Node* temp = head;
            Node* prev = NULL;
            while(temp != NULL){
                Node* front = temp->next;
                temp->next = prev;

                //updating the prev value and current value
                prev = temp;
                temp = front;

            }

            head = prev;

        }


        // Removing the nth node in the linked list 

        void removenth(int n){

            if(!head) return ;

            Node* temp = head;
            int cnt = 0;

            while(temp!=NULL){
                cnt++;
                temp = temp->next;

            }

            // if n is equal to total count, remove head
            if(n == cnt){
                Node* todelete = head;
                head = head->next;
                delete todelete;
                return ;
            }

            // if n is invalid 
            if(n>cnt || n<= 0) return ;

            int n1 = cnt - n ;
            temp = head;

            // Move to the nod just before the one to be deleted
            for(int i = 1; i <n1; i++){
                temp = temp->next;
            }
            Node* front = temp->next;
            temp->next = temp->next->next;
            delete front;
            
        }

        // LL being palindrome linked list is the palindrome or not 

        bool palindrome(){
  
            Node* fast = head;
            Node* slow = head;
            
            while(fast->next != NULL && fast->next->next != NULL){

                slow = slow->next;
                fast = fast->next->next;

            }

  
            Node* temp = slow->next;
            slow->next = NULL;

            Node* prev = NULL;

            while(temp != NULL){
                Node* front = temp->next;
                temp->next = prev;
                prev = temp ;
                temp = front;
            }

            temp = head;

            while(prev && temp ){
                if(prev->data != temp->data) return false;
                prev = prev->next;
                temp = temp->next;
            }

            return true;
        }


        // Cycle in linked list

        bool isCycle(){
            Node* fast = head;
            Node* slow = head;

            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next; // + 2

                if(slow == fast){
                    cout << "Cycle exist\n";
                    return true;
                }

            }
            cout << "Cycle does not exist \n"; 
            return false;

        }


        // Remove Cycle linked list 

        void RemoveCycle(){
            Node* fast = head;
            Node* slow = head;

            while(fast!= NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast){
                     break;
                } 
            }

            // if there is no cycle 
            if(fast == NULL || fast->next == NULL) return ;
            
            slow = head;
            if(slow == fast){
                while(fast->next != slow){
                    fast= fast->next;
                    
                }

                fast->next = NULL;
                return ;
            }
            while(fast ->next != slow){
                fast = fast->next;
                slow = slow->next;

            }
            fast->next = NULL;
            return ;
            
        };



        // Merge Sort in linked list

        Node* splitNode(Node* head){
            Node* slow = head;
            Node* fast = head;
            Node* prev = NULL;
            while(fast!= NULL && fast->next != NULL){
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            

            prev->next = NULL;
            return slow;

        }

        Node* merge(Node* left, Node* right){
            Node* i = left;
            Node* j = right;

            List amul;

            while(i != NULL || j!= NULL){
                if(i->data >= j->data){
                    amul.push_back(i->data);
                    i = i->next;
                }else{
                amul.push_back(j->data);
                j = j->next;}
            }
            while(i != NULL){
                amul.push_back(i->data);
                i = i->next;
            }

            while(j != NULL){
                amul.push_back(j->data);
                j = j->next;
            }

            return amul.head;

        }

        Node* mergeSort(Node* head){
            if(head == NULL || head->next == NULL)return head;

            Node* rightNode = splitNode(head);

            // sort the left half
            Node* left = mergeSort(head);

            // sort the right half
            Node* right = mergeSort(rightNode);

            return merge(left, right);
        }


        // Zig Zag in linked list 

        Node* ZigZag(){
            

            // finding the middle 
            Node* fast = head;
            Node* slow = head;
            while( fast!=NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
            }
            
            Node* right = slow->next;
            slow->next = NULL;

            // reverse the right linkedlist
            Node* prev = NULL;
            Node* temp = right;
            while(temp  != NULL){
                Node* front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }

            right = prev;

            // now point them to each other 
            temp = head;
            while(temp != NULL && right != NULL){
                Node* front = temp->next;
                Node* rightfront = right->next;
                temp->next = right;
                if(front == NULL) break;
                right->next = front;
                temp = front;
                right = rightfront;
            }

            return head;
        }


    
    };


    Node* ZigZag(Node* head){
            

            // finding the middle 
            Node* fast = head;
            Node* slow = head;
            while( fast!=NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
            }
            
            Node* right = slow->next;
            slow->next = NULL;

            // reverse the right linkedlist
            Node* prev = NULL;
            Node* temp = right;
            while(temp  != NULL){
                Node* front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }

            right = prev;

            // now point them to each other 
            temp = head;
            while(temp != NULL && right != NULL){
                Node* front = temp->next;
                Node* rightfront = right->next;
                temp->next = right;
                if(front == NULL) break;
                right->next = front;
                temp = front;
                right = rightfront;
            }

            return head;
        }




int main(){

    List ll;

    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();

    ll.head = ZigZag(ll.head);

    ll.printList();

    return 0;
}