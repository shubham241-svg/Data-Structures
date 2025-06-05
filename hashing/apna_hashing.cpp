#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <pair> 
using namespace std;

class Node{
    public: 
        string key;
        int val;
        Node* next;

        Node(string key, int val){
            this->key = key;
            this->val = val;
            next = NULL;
        }
};

class HashTable{
    int totSize;
    int currSize;
    Node** table;

    public:     
        HashTable(int size=5){
            totSize = size;
            currSize = 0;

            table = new Node*[totSize];

            for(int i = 0; i<totSize; i++){
                table[i] = NULL;
            }

        }

        void insert(string key, val){

        }

        void remove(string key){

        }

        int search(string key){
            
        }
}
int main(){

    //UNORDERED_MAP 
    unordered_map<string, int> m;

    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;

    cout << m["India"] << endl;
    for(pair<string, int> country : m){
        cout << country.first << ","<< country.second << endl;
    }

    // tells if the "nepal" is inside the unordered map if yes then 1 else 0
    if(m.count("Nepal")){
        cout << "Canada exists\n";
    }else{
        cout << "Canada doesn't exits\n"
    }

    m.erase("Nepal");






    //MAP

    map<string, int> ma;

    ma["China"] =  150;
    ma["India"] = 100;
    ma["USA"] = 20;

    for(auto it : ma){  //instead of auto can use pair<string, int>
        cout << it.first << ", "<< it.second << endl;
    }
    
    m["nepal"] = 120;
    if(m.count("nepal")){
        cout << "nepal exisits\n";
    }else{
        cout << "nepal does'nt exists\n"
    }

    m.erase("nepal");



    // UNORDERED SET

    unordered_set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);

    //s.insert(1);
    
    if(s.find(3) != s.end()){
        cout << "3 exist\n";
    }else{
        cout << "3 doesn't exists"
    }
    for(auto el: s){
        cout << el << " ";
    }
    cout << endl;


    return 0;
}