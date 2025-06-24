#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void heapify(int i, vector<int> &arr, int n){
    cout << "heapify called with i=" << i << " n=" << n << endl;

    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxI = i;

    if(left < n && arr[left]> arr[maxI]){
        maxI = left;
    }

    if(right < n && arr[right] > arr[maxI]){
        maxI = right;
    }

    if(maxI != i){
        cout << "Swapping " << arr[i] << " and " << arr[maxI] << endl;
        swap(arr[i], arr[maxI]);
        heapify(maxI, arr, n);
    }
}


void heapSort(vector<int> &arr){
    int n = arr.size();

    // step1 : build maxHeap
    for(int i = n/2 - 1; i>=0; i--){
        heapify(i, arr, n);
    }

    // step2: taking els to correct pos
    for(int i= n-1; i> 0; i--){
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main(){
    // vector<int> arr = {1, 4, 2, 5, 3};

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);
    heapSort(arr);

    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}