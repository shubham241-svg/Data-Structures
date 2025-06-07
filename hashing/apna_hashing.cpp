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

#include <iostream>
using namespace std;

// Node class for the linked list
class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string k, int v) {
        key = k;
        val = v;
        next = NULL;
    }
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    int HashFunction(string key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % totSize;
        }
        return hash;
    }

public:
    HashTable(int size = 5) {
        totSize = size;
        currSize = 0;
        table = new Node*[totSize];

        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {
        int idx = HashFunction(key);
        Node* temp = table[idx];

        // Check if key already exists, update value if found
        while (temp != NULL) {
            if (temp->key == key) {
                temp->val = val;
                return;
            }
            temp = temp->next;
        }

        // Insert new node at head (chaining)
        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;
        currSize++;
    }

    bool exists(string key) {
        int idx = HashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void remove(string key) {
        int idx = HashFunction(key);
        Node* temp = table[idx];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == NULL) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                currSize--;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    int search(string key) {
        int idx = HashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1; // Key not found
    }

    ~HashTable() {
        // Free memory
        for (int i = 0; i < totSize; i++) {
            Node* temp = table[i];
            while (temp != NULL) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] table;
    }
};

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