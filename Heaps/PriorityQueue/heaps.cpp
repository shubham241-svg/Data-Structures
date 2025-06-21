#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Heap{

    vector<int> v;

    public:
        // step 1
        void push(int val){

            // step1;

            v.push_back(val);

            // fix heap
            int chi = v.size() - 1; // child index == x
            int parI = (chi-1)/2; // parent index

            while(parI >= 0 && v[chi] > v[parI]){ //O(logn)
                swap(v[chi], v[parI]);
                chi = parI;
                parI = (chi - 1)/2;
            }
    }

        void heapify(int i){
            int l = 2*i+1;
            int r = 2*i+2;
            int maxI = i;

            if(l < v.size() && v[l] > v[maxI]){
                maxI = l;
            }

            if(r < v.size() && v[r] > v[maxI]){
                maxI = r;
            }

            if(maxI != i){
                swap(v[i], v[maxI]);
                heapify(maxI);
            }
        }
        

        void pop(){

            // step 1
            swap(v[0], v[v.size()-1]);

            //step 2
            v.pop_back();

            //step 3
            heapify(0); // O(Logn)

        }

        int top(){

            return v[0]; // high priority element

        }

        bool empty(){

            return v.size() == 0;

        }
};

class Student{ // "<" overload
    public :

    string name;
    int marks;

    Student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const{
        return this->marks < obj.marks;  // asscending  if both operator < and this return is also < then we have maxheap
    }


};

struct ComparePair{

    bool operator () ( pair<string, int> &p1, pair<string, int> &p2){
        return p1.second < p2.second;
    }
};
int main(){
    priority_queue<int> pq;
    priority_queue<string, vector<string>, greater<string> > qp;

    pq.push(5);
    pq.push(10);
    pq.push(9);
    pq.push(7);
    pq.push(3);


    qp.push("helloworld");
    qp.push("apnacollege");
    qp.push("c++");
    qp.push("alpha");

    while(!qp.empty()){
        cout << "top : "<< qp.top() << endl;
        qp.pop();
    }

    while(!pq.empty()){
        cout << "top : " << pq.top() << endl;
        pq.pop();
    }


    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    cout << heap.top() << endl;

    while (!heap.empty()){
        cout << heap.top() << endl;
        heap.pop();
    }



    // Priority Queue for Objects
    priority_queue<Student> qe;
    qe.push(Student("aman", 500));
    qe.push(Student("bhumika", 1000));
    qe.push(Student("chetan", 2000));

    while(!qe.empty()){
        cout << "top = " << qe.top().name << ", " << qe.top().marks << endl;
        qe.pop();
    }

    // Priority Queue for pairs

    

    priority_queue<pair<string, int>, vector<pair<string, int> > , ComparePair> ep; // default - maxHeap : "first"

    ep.push(make_pair("ama", 299));
    ep.push(make_pair("bhumika", 1000));
    ep.push(make_pair("chetan", 2000));

    while(!pq.empty()){
        cout << "top" << ep.top().first << ", " << ep.top().second << endl;
        ep.pop();
    }



    return 0;
}