#include <vector>
#include <queue>
#include <iostream>
using namespace std;


class Car{
    public:
        int idx;
        int distSq;

        Car(int idx, int distSq){
            this->idx = idx;
            this->distSq = distSq;
        }

        bool operator < (const Car &obj) const{
            return this->distSq > obj.distSq;   // min heap
        }

};

void nearbyCars(vector<pair<int, int> > pos, int k){
    // idx, distsquare
    vector<Car> cars;

    for(int i=0; i<pos.size(); i++){ // O(n)

        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(i, distSq));

    }

    priority_queue<Car> pq(cars.begin(), cars.end()); // O(n) this insertion only takes O(N)

    // for(int i = 0; i<cars.size(); i++){ // O(nlogn)
    //     pq.push(cars[i]);
    // }

    for(int i = 0; i<k; i++){ // O(k+logn + n)
        cout << "car" << pq.top().idx << endl;
        pq.pop(); 
    }
}

//Connect N ropes
 // if cost to connect 2 ropes = sum of their lengths find min cost to connect N ropes

 int minRope(vector<int>& arr){
    priority_queue<int, vector<int>, greater<int> > pq(arr.begin(), arr.end()); // O(N)
    int cost = 0;

    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        cost += min1 + min2;
        pq.push(min1 + min2);


    }

    cout << "mincost. " << cost << endl;
    return cost;
 }


 // Weakest Soldier 

 class Row{
    public: 
        int count;
        int idx;

        Row(int count, int idx){
            this->count = count;
            this->idx = idx;
        }

        bool operator < (const Row &obj) const{
            if(this->count == obj.count){
                return this->idx > obj.idx;
            }
            return this->count > obj.count ;
        }
 };
 void weakestSoldier(vector<vector<int> > matrix, int K){
    vector<Row> rows;

    for(int i=0; i<matrix.size(); i++){
        int count = 0;
        for(int j = 0; j<matrix[i].size() && matrix[i][j] == 1; j++){
            count++;
        }

        rows.push_back(Row(count, i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i = 0; i<K; i++){
        cout << "Row" << pq.top().idx << endl;
        pq.pop();
    }
 }  


 // sliding windo maximum

 void slidingwindomax(vector<int> arr, int k){

    priority_queue<pair<int, int> > pq;

    // first window
    for(int i = 0; i<k; i++){
        pq.push(make_pair(arr[i], i));
    }

    cout << "output : " << pq.top().first << " ";

    for(int i = k; i<arr.size(); i++){
        while(!pq.empty() && pq.top().second <= (i -k)){ // outside window
            pq.pop();

        }

        pq.push(make_pair(arr[i], i));
        cout << pq.top().first << " ";
    }

    cout << endl;


 }
int main(){
    vector<pair<int, int> > pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5, 1));
    pos.push_back(make_pair(-2, 4));

    int k = 2;

    vector<int> ropes;
    ropes.push_back(4);
    ropes.push_back(3);
    ropes.push_back(2);
    ropes.push_back(6);

    nearbyCars(pos, 2);
    minRope(ropes);

//     vector<vector<int> > matrix = {{1, 0, 0, 0},
//                                    {1, 1, 1, 1},
//                                    {1, 0, 0, 0},
//                                    {1, 0, 0 , 0}};

//    weakestSoldier(matrix, 3);

   vector<int> aray;
   aray.push_back(1);
   aray.push_back(3);
   aray.push_back(-1);
   aray.push_back(-3);
   aray.push_back(5);
   aray.push_back(3);
   aray.push_back(6);
   aray.push_back(7);

   slidingwindomax(aray,3);




   return 0;
}
