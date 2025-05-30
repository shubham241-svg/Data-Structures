#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <deque>
using namespace std;

// Non repeating letter : find the first non- repeating letter in the stream of characters
void nonRepeating(string word){
    queue<char> Q;
    int freq[26] = {0};
    for(int i=0; i<word.size(); i++){
        char ch = word[i];
        freq[ch - 'a']++;
        Q.push(ch);

        while(!Q.empty() && freq[Q.front() -'a'] > 1){
            Q.pop();
        }

    if(Q.empty()){
        cout << "-1\n";
    }else{
        cout << Q.front() << "\n";
    }
 }
}

// interleave of a queue
void interleave(queue<int> &org){
    int n = org.size();
    queue<int> first;

    for(int i=0; i<n/2; i++){
        first.push(org.front());
        org.pop();
    }

    while(!first.empty()){
        org.push(first.front());
        first.pop();

        org.push(org.front());
        org.pop();
    }
}

//reverse a queue

void reverseQueue(queue<int> &org){

    stack<int> st; 

    while(!org.empty()){
        st.push(org.front());
        org.pop();
    }

    while(!st.empty()){
        org.push(st.top());
        st.pop();

    }

    while(!org.empty()){
        cout << org.front() << " ";
        org.pop();
    }
}

// time needed to buy tickets

int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int, int> dq; 
        int cnt = 0 ;
        for(int i=0; i<tickets.size(); i++){
            dq.push({tickets[i], i});
        }

        while(!dq.empty()){
            auto front = dq.front();
            dq.pop();

            front.first--;
            cnt++;

            if(front.first > 0){
                dq.push(front);
            }

            if(front.second == k && front.first == 0){
                return cnt;
            }
    }

    return cnt;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    reverseQueue(q);
    vector<int> v = {2,3,2};
    int k = timeRequiredToBuy(v , 2);
    cout << k;

}