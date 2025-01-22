#include <iostream>
#include <map>
#include <vector>
using namespace std;
// longest subarray with sum k for +ve and -ve numbers
int longestSubarrayWithSumK(vector<int> a, long long k) {
    map<long long, int> presumMap;
    long long sum = 0;
    int maxlen = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i];

        if (sum == k) {
            maxlen = max(maxlen, i + 1);
        }

        long long rem = sum - k;
        if (presumMap.find(rem) != presumMap.end()) {
            int len = i - presumMap[rem];
            maxlen = max(maxlen, len);
        }

        if (presumMap.find(sum) == presumMap.end()) {
            presumMap[sum] = i;
        }
    }
    
    return maxlen;
}


// longest subaarray with sum k optimal soln for positive numbers

int longsubarrsumk(vector<int> a, long long k){
    int left = 0, right = 0;
    long long sum = a[0];
    int maxlen = 0;
    int n = a.size();
    while(right<n){

        //trimming down the elements to reduce the sum
        while(left <= right && sum>k){
            sum -= a[left];
            left++;
        }

        if(sum == k ){
            maxlen = max(maxlen, right - left + 1);
        }
        // adds the sum 
        right ++;
        if(right<n ) sum += a[right];

    }
    return maxlen;
}

// 2 SUM Problem 

string read(int n , vector<int> book, int target){
    map<int, int> mpp;
    for(int i = 0; i<n; i++){
        int a = book[i];
        int more = target -a ;
        if(mpp.find(more) !=mpp.end()){ // checks for the target in the hashmap
            return "yes"; // when we want to return the index of the {mpp[more], i}

        }

        mpp[a] = i;// inserts the elements in the map with the index
    }

    return "no"; // return(-1, -1)
}

        // when we don't want to use the map function and return yes or no then we can do it by using two pointer approach

string read1(int n , vector<int> book , int target){
    int left = 0 , right = 0;
    sort(book.begin(), book.end());
    while(left<right){
        int sum = book[left] + book[right];
        if(sum == target){
            return "yes";
        }
        else if(sum < target){ left ++;}
        else right --;
    }
    return "no";

}// to return the indexes we have to use another data structure like maps like above that is an optimal answer for this variety.


//NUMBER OF SUBARRAYS WITH SUM K

int findallsubarray(vector<int> &arr, int k){
    map<int,int> mpp;
    mpp[0] =  1;
    int presum = 0, cnt = 0;
    for(int i = 0; i<arr.size(); i++){
        presum += arr[i];
        int remove = presum - k;
        cnt += mpp[remove];
        mpp[presum] += 1;

    }
    return cnt;

}