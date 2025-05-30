#include <iostream>
#include <stack>
#include <string>
using namespace std;

check if a linked list is palindrome or not 

bool isPalindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    stack<int> s;

    // find the midpoint and push first half onto stack
    while(fast != NULL && fast->next != NULL){
        s.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // if odd number of odds of nodes, skip the middle one
    if(fast != NULL) slow = slow->next;

    // compare the second half witht the stack 
    while(slow != NULL){
        if(s.empty() || s.top() != slow->data){
            return false;
        }
        s.pop();
        slow = slow->next;
    }
    return true;


}

string decodeString(string s){
    stack<int> sta;
    for(int i = 0 ; i< s.size(); i++){
        char ch = s[i];
        if(isdigit(c)){
            sta.push();
        }

    }
    string ans = "";
    for(int i=0; i<s.size(); i++){
        int j = i;
        if(s[i] == '['){
            while(s[j+1] != ']'){
                for(int k=1; k<= sta.top()){
                    ans += s[j+1];
                    j++;
                }
                

            }
            sta.pop();
            j= i;
        }

    }

    return ans;
}

string decodeString(string s){
    stack<int> coutStack;
    stack<int> stringStack;
    string current = "";
    int k = 0 ;

    for (char ch : s){
        if(isdigit(ch)){
            k  = k*10 + (ch - '0');
        }else if(ch == '['){
            countStack.push(k);
            stringStack.push(current);
            k = 0;
            current = "";
        }else if(ch == ']'){
            string decoded = stringStack.top(); stringStack.pop();
            int repeat = countStack.top(); countStack.pop();
            for(int i = 0; i<repeat; ++i){
                decoded += current;
            }
            current = decoded ;
        }else{
            current += ch;
        }

    }

    return current;
}

string unixtoabsolute(string s){
    stack<string> st;
    string current = "";
    for(char ch: s){
        if(ch == "/"){
            st.push(current);
            current
        }
    }
    
}




int main(){

    string  arm=  2 * "bc";
    cout <<arm;

    return 0;
}