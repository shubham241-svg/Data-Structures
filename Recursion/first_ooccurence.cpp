#include <iostream>
#include <vector>
using namespace std;

int firstOccur(vector<int> arr, int i , int target){
    if(i == arr.size()){
        return -1; // Return -1 if target is not found
    }

    if(arr[i] == target){
        return i; // Return the index if the target is found
    }

    return firstOccur(arr , i + 1, target);    
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    cout << firstOccur(arr, 0, 6);
    return 0;
}
