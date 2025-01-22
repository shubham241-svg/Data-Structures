#include <iostream>
#include <vector>

using namespace std;

int countSwapsAscending(vector<int> arr) {
    int n = arr.size();
    int swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

int countSwapsDescending(vector<int> arr) {
    int n = arr.size();
    int swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ascSwaps = countSwapsAscending(arr);
    int descSwaps = countSwapsDescending(arr);

    cout << min(ascSwaps, descSwaps) << endl;

    return 0;
}
