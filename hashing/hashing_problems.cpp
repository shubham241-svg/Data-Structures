#include <bits/stdc++.h>
// #include <iostream>
// #include <unordered_map>
// #inlude <vector>
// #include <string>
using namespace std;

// majority element 

int majorityele(vector<int> arr){

    unordered_map<int, int> ma;
    for(int i = 0 ; i<arr.size(); i++){
        ma[arr[i]]++;
    }

    // if single element
    for(auto i : ma){
        if(i.second > (arr.size()/3)){
            return i.first;
        }
    }

    // if more than 1 elements are greater > n/3;
    vector<int> res;
    for(auto& [key, count]: ma){
        if(count > arr.size()/3){
            res.push_back(key);
       
     }
    }

    //return res;
    return -1;

}


// valid anagram using set or map like that

bool validanagram(string s, string t){

    if(s.size() != t.size()) return false;
    unordered_map<char, int> ma;
    for(int i = 0; i<s.size(); i++){
        ma[s[i]]++;
        ma[t[i]]--;
    }
        
    for(auto it : ma){
        if(it.second != 0) return false;
    }
    return true;
}

// count distinct elements 

int countDistinct(vector<int> arr){
    unordered_set<int> s;
    
    for(int i = 0; i<arr.size(); i++){
        s.insert(arr[i]);
    }

    return s.size();
}

// union and intersection of the elements

void union(vector<int> v1, vector<int> v2){
    set<int> st;
    for(int i = 0 ; i<v1.size(); i++){
        st.insert(v1[i]);
    }
    for(int i = 0; i<v2.size(); i++){
        st.insert(v2[i]);
    }

    for(auto i : st){
        cout << i ;
    }

}

// itenary of the tickets

void printItenary(unordered_map<string, string> tickets){
    // starting poin
    unordered_set<string> to;

    for(pair<string, string> ticket: ticket){ // <from , to>
        to.insert(ticket.second);

    }

    string start = "";
    for(pair<string, string> ticket: tickets){ 
    //    ticket.first -> from
        if(to.find(ticket.first) == to.end()){
            start = ticket.first;
        }

    }

    while(tickets.count(start)){
        cout << tickets[start];
        start = tickets[start];
    }

    cout << "destination\n";
}

// largest subarray with sum 0

// int largesub(vector<int> arr){
    
//     int len = 0;
//     int sum =0;
//     for(int i=0; i<arr.size(); i++){
//         int sum += arr[i];
//         if(sum == 0){
//             len = max(len , i+1);

//         }
//     }
//     sum = 0;
//     int low = 1; 
//     int high = arr.size()-2;
//     while(low <=high){
//         for(int i=low ; i<=high; i++){
//             sum += arr[i];
//             if(sum == 0){
//                 len = max(len , high-i+1);
//                 sum = 0;

//             }
//         }
//         low ++ ;
//         high -- ;
//     }


//     sum = 0;

//     for(int i=arr.size()-1; i>=1; i--){
//          sum += arr[i];
//         if(sum == 0){
//             len = max(len, i+1);
//         }
//     }

//     return len;
// }


// largest subarray with sum 0 almost take Tc as O(N)
int largestSubWithSum(vector<int> arr){
    unordered_map<int, int> m;
    int sum = 0;
    int ans = 0;

    for(int j = 0; j<arr.size(); j++){
        sum += arr[j];

        if(m.count(sum)){
            int currLen = j-m[sum];
            ans = max(ans, currLen);

        }else{
            m[sum] = j;

        }
    }
    return ans;
}


// SUBARRAY SUM EQUALS K 

int subaaraysumk(vector<int> arr, int k){
    unordered_map<int, int> m ;
    int sum = 0;
    int ans = 0;

    m[0] = 1;

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];

        if(m.count(sum - k)){
            ans = ans + m[sum-k];
        }
        
        m[sum]++;
        
    }

    return ans;
}

void intersection(vector<int> v1, vector<int> v2){
    map<int, int> ma; 
    for(int i= 0; i<v1.size(); i++){
        ma[v1[i]]++;
    }
    for(int i=0; i<v2.size(); i++){
        ma[v2[i]]++;
    }
    for(auto i : ma){
        if(i.second > 1) cout << i.first ;
    }
}

int main(){
    int arr[7] = {1, 2, 7, 11, 15, 5, 9};
    int n = 7;
    int target = 9;
    unordered_map<int, int> m; // key = arr[i], val=i

    for(int i = 0; i<n; i++){
        int comp = target - arr[i];
        if(m.count(comp)){
            cout << "ans = " << m[comp]<< ", " << "i" << endl;
            break;
        }

        m[arr[i]] = i;
    }



}