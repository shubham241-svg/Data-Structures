// create stack using a vector

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

//create stack using vector
template<class T>
class Stack{
    vector<T> vec;

    public: 
        void push(T val){

            
            vec.push_back(val);
        }

        void pop(){ //O(1)
            if(isEmpty()){
                cout <<"stack is empty";
                return ;
            }
            vec.pop_back();
        }

        T top(){ //O(1)
            int lastIdx = vec.size() - 1;
            // if(isEmpty()){
            //     cout <<"stack is empty";
            //     return -1;
            // }
            return vec[lastIdx];
        }

        bool isEmpty(){ //O(1)
            return vec.size() == 0;
        }
};


// pushing an element in the bottom of the stack recursive O(N)

void pushAtBottom(stack<int> &s, int val){

    if(s.empty()){
        s.push(val);
        return;
    }

    int top = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(top);
}

// Reverse of a string using a stack 

void reverseString(string str){
    string ans;
    stack<char> st;

    for(int i = 0 ; i<str.size(); i++){ //i:str
        st.push(str[i]);
        
    }

    while(!st.empty()){
        char top = st.top();
        ans += top;
        st.pop();
    }

    cout<< ans << endl;


}

// reverse a stack
void reverseStack(stack<int> &st){

    if(st.empty()){
        return;
    }

    int temp = st.top();
    st.pop();
    reverseStack(st);
    pushAtBottom(st, temp);

}

// stock span  O(N) and sc = O(N) as the elements are popped once in the process so the tc = O(N)
void stockSpanProblem(const vector<int>& stock, vector<int>& span) {
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < stock.size(); i++) {
        while (!s.empty() && stock[i] >= stock[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - s.top();
        }

        s.push(i); // Push current index to stack
    }
}


// Next greater element

    // using stock span approach 

void nextgreaterelement(vector<int>& ele, vector<int>& ans){
    stack<int> st;
    int n = ele.size() - 1;
    st.push(n);
    ans[n] =  -1;
    
    for(int i = n-1; i>=0 ; i--){

        while(!st.empty() && ele[i] >= ele[st.top()]){
            st.pop();
        }
        if(st.empty()){

            ans[i] = -1;
        }
        else{
            ans[i] = ele[st.top()];
        }
        st.push(i);
    }
}


// Valid paranthesis //tc - O(N) && sc-O(N)

bool validpara(string str){
    stack<int> s;
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else{
            if(s.empty()){
                return false;
            }
            //matching the closing char with the opening top of the stack 
            char top = s.top();
            if((ch=='}' && top == '{') || (ch==']' && top=='[') || (ch==')' && top == '(')){
                s.pop();
            }
            else{
                return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }
    return false;

}


// duplicate parantheses

bool isduplicatepara(string str){
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if(ch != ')'){ // non closing
            s.push(ch);
            
        }else{
            // if top '(' , then its is a duplicate
            if(!s.empty() && s.top() ==  '('){
                return true; // duplicate
            }
            // pop till
            while(!s.empty() && s.top() != '('){
                s.pop();
            }
            
            if(!s.empty()) s.pop();

            
        }
    }
    return false;
}


// max area in histogram 
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;

    // NSL - Previous Smaller to Left
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty()) {
            left[i] = -1;
        } else {
            left[i] = st.top();
        }
        st.push(i);
    }

    // Clear stack for NSR
    while (!st.empty()) st.pop();

    // NSR - Next Smaller to Right
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty()) {
            right[i] = n;
        } else {
            right[i] = st.top();
        }
        st.push(i);
    }

    // Calculate area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}



void printstack(stack<int> st){
    while(!st.empty()){
        cout<< st.top()<< " ";
        st.pop();
    }
    cout << endl;
}


int main(){
    Stack<string> s;

    s.push("ar");
    s.push("basdf");
    s.push("cadsf");

    while(!s.isEmpty()){
        cout << s.top()<< " ";
        s.pop();
    }

    cout<< endl;

    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);

    while(!st.empty()){
        cout<< st.top()<< " ";
        st.pop();
    }

    cout << endl;

    st.push(3);
    st.push(2);
    st.push(1);

    pushAtBottom(st, 4);

    while(!st.empty()){
        cout<< st.top()<< " ";
        st.pop();
    }

    cout << endl;

    reverseString("Shubham");

    st.push(3);
    st.push(2);
    st.push(1);

    reverseStack(st);
    printstack(st);

    string str2 = "(([]))";
    string str1 = "()))))";
    cout << validpara(str1) << endl;
    cout << validpara(str2) << endl;

    string st1 = "((x + y) + c)"; // false not duplicate paranthesis
    string st2 = "((a+b))"; // true is duplicate para

    cout << isduplicatepara(st1) << endl;
    cout << isduplicatepara(st2) << endl;



    return 0;


}