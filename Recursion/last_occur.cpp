#include <iostream>
#include <vector>
using namespace std;

int lastOccur(const vector<int>& arr, int target, int i) {
    if (i == arr.size()) {
        return -1; // Base case: reached end of array without finding the target
    }

    int idxFound = lastOccur(arr, target, i + 1); // Recursive call to check the rest of the array

    // If target is not found in the rest of the array and current element is the target, return current index
    if (idxFound == -1 && arr[i] == target) {
        return i;
    }

    return idxFound; // Return the index found in the recursive call
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 5};
    cout << lastOccur(arr, 3, 0) << endl; // Output the last occurrence of 3

    return 0;
}
