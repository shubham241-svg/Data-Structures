#include <iostream>
using namespace std;

// Recursive code for binary search 
// Time complexity is O(N)

int bs(vector<int> &nums, int low, int high, int target){
    if(low > high) return -1;
    int mid = (low + high)/2; // low + (high-low)/2
    if(nums[mid] ==  target) return mid;
    else if (target > nums[mid]) return bs(nums, mid+1, high, target);
    return bs(nums, low, high -1 , target);
}

int search(vector<int> &nums, int target){
    return bs(nums,0,nums.size(),target);
}

        // there is a chance of overflow case as the mid can be the last element in the array 
        //so we can use another mid formula which is mid = low + (high - low)/
        


// lower bound 

int lowerbound(vector<int> arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low+high)/2;

        // maybe an answer
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}


// Upper bound

int upperbound(vector<int> &arr, int x , int n){
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (high + low)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }

        else{
            low = mid + 1;
        }
    }
    return ans;
}                   // Time complexity O(log2n)


// L.C First and Last position of an element in Sorted array

pair<int, int> firstAndLastposition(vector<int> &arr, int n , int k){
    int lb = lowerbound(arr,n,k);
    if(lb == n || arr[lb] != k) return {-1,-1} ;
    return {lb , upperbound(arr, n , k) - 1};
}





// using binary search 
// first occurence

int firstoccurence(vector<int> &arr, int n , int k){
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k){
            first = mid;
            high = mid - 1;

        }
        else if(arr[mid] < k ) low = mid + 1;
        else high = mid - 1;
    }

    return first ;
}




// Last occurence 


int lastoccurence(vector<int> &arr, int n , int k){
    int low = 0, high = n - 1;
    int last = - 1;
    while(low <= high ){
        int mid = (low + high)/2;
        if(arr[mid] == k){
            last = mid;
            low = mid + 1;

        }
        else if(arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }

    return last;
}

pair<int, int> firstandlastpos(vector<int> &arr, int n , int k){
    int first = firstoccurence(arr, n , k);
    if(first == -1) return {-1, -1};
    int last = lastoccurence(arr, n , k);
    return {first, last};
}


int count(vector<int> &arr, int n , int k){
    pair<int, int> ans = firstandlastpos(arr, n , k);
    if(ans.first == -1) return 0;
    return ans.second - ans.first + 1;
}



// Search in sorted array lc

int search(vector<int> &arr, int n , int k){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k) return mid;

        // left sorted 
        if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }
        }

        else{
            if(arr[mid] <= k && k<= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }

    return -1;
}

// variation 2

// Search in sorted array in leetcode with duplicates

int search(vector<int> &arr, int n , int k){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k) return mid;
        
        // adding the extra edge case 
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }

        // left sorted 
        if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }
        }

        else{
            if(arr[mid] <= k && k<= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }

    return -1;
}


// Minimum element  in rotated sorted array lc 


int findmin(vector<int> &arr){
    int low = 0, high = arr.size() -1 ;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low + high)/2;

        // if search space is already sorted 
        // then always arr[low] is will be smaller 
        // in that search space

        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }


        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;

        }

        else{
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }


    }
    return ans;
}

// This above logic can be used for finding out the no. of times an array has been rotated

        // just have to return the index for every element that has been put into an ans
int findmin(vector<int> &arr){
    int low = 0, high = arr.size() -1 ;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = (low + high)/2;

        // if search space is already sorted 
        // then always arr[low] is will be smaller 
        // in that search space

        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            break;
        }

        
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;

        }

        else{
            high = mid - 1;
            if(arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
        }


    }
    return index;
}



// Single element in a sorted array  

int singleNonduplicate(vector<int> &arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1, high = n -2 ;
    while(low <= high ){
        int mid = (low + high)/2;
        if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid -1]){
            return arr[mid];
        }

        if((mid %2 == 1 && arr[mid] == arr[mid - 1]) || (mid %2 == 0 && arr[mid] == arr[mid + 1])){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }
    return -1;
    
}


//Find the Peak Element 

// Brute force method 


int findpeak(vector<int> &arr){
    int n = arr.size();
    for(int i = 0 ; i<n ; i++){
        if((i == 0 || arr[i-1] < arr[i]) && (i = n-1 || arr[i]> arr[i+1])){
            return i ;
        }
    }
    return -1;
}


// Optimal Approach 
 // time complexit O(log n)
int findPeak(vector<int> &arr){
    int n = arr.size();
    if(n == 1) return 0;                        // important edge cases 
    if(arr[0] > arr[1]) return 0;
    if(arr[n - 1] > arr[n -2]) return n -1 ;

    int low = 1 , high = n -2;  // starting the search from 2nd element upto second last element ;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        else if(arr[mid] > arr[mid - 1]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}


// find the peak element in 2d array

int findmaxindex(vector<vector<int>> &mat, int n , int m, int col){
    int maxvalue = -1;
    int index = -1; // this function will return the row of max element of that columns
    for(int i = 0; i < n; i++ ){
            if(mat[i][col] > maxvalue){
                maxvalue = mat[i][col];
                index = i;
            }        
    }

    return index;
}

vector<int> findpeakin2d(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    int low = 0 , high = m -1;
    while(low <= high){
        int mid = (low + high)/2;
        int maxrow = findmaxindex(mat, n, m , mid);
        int left = mid - 1>= 0? mat[maxrow][mid - 1] : -1;
        int right = mid + 1< m? mat[maxrow][mid + 1]: -1;

        if(mat[maxrow][mid] > left && mat[maxrow][mid] > right){
            return {maxrow, mid};
        }
        else if(mat[maxrow][mid] < left){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return {-1, -1};
}


// find the median of two sorted arrays

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}