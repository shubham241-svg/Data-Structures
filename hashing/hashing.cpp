#include <iostream>
#include <map>
#include <vector>
using namespace std;

// count elements

int count(int arr[], int n, int target){
    int hashh[13]; // let suppose the maximum elemnt that array can take is 13

    for(int i =0 ; i < n ; i++){
        hashh[arr[i]] += 1;
    }

    return hashh[target];


}


// counting the alphabets for a string

// if it is specifically mention that all letter will be in lower case
// char - 'a'

void count1(string s){
    int hasharr[256]= {0}; // hasharr[26]

    for(int i = 0; i< s.size(); i++){
        hasharr[s[i]]++;  // hasharr[s[i] - 'a']++
    }


}


// mapping as hashmap

void m(int arr[], int n, int target){

    map<int,int> mpp;

    unordered_map<int,int> mp1;

    for(int i = 0; i<n ; i++){
        mpp[arr[i]]++;
    }

    cout<< mpp[target];


}

 void frequencyCount(vector<int>& arr,int N, int P)
{ 
    // code here
    map<int,int> mpp;
        
    for(int i = 0 ; i<N; i++){
            mpp[arr[i]++];
        }
        
    for(int i=1; i<=P;i++){
            cout << mpp[arr[i]] << " ";
        }}
        
int main() {
    vector<int> v1 = {1, 1, 2, 4, 2, 6};
    frequencyCount(v1, 6, 4);
    return 0;
}