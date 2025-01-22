#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;



int missingNumber(vector<int>&a, int N){
    int xor1 = 0,  xor2 = 0;
    int n = N-1;
    for(int i = 0; i<n ; i++){
        xor2 = xor2 ^ a[i];
        xor1 =  xor1^ (i+1);

    }

    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}


// finding the number that appears once

int getsingleElement(vector<int> &arr){
    int xor1 = 0;
    for(int i = 0 ; i<arr.size() ; i++){
        xor1 = xor1^i;

    }

    return xor1;

}


//sort an array of 0s and 1s 
//optimal solution 3 pointer approach

// this optimal solution has time complexity On and space complexity O1

void sortarray(vector <int>&arr, int n){
    int low = 0, mid = 0,high = n -1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low ++ , mid++;
        }

        else if(arr[mid]==1){
            mid ++ ;
            
        }

        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// majority element in an array which occurs n/2 times a

// better solution

int f(vector<int> v){
    map<int,int> mpp;
    for(int i = 0 ; i<v.size(); i++){
        mpp[v[i]]++;
    }

    for(auto it: mpp){
        if(it.second>v.size()/2){
            return it.first;
        }
    }
    return -1;
}

// optimal solution

int majorelment(vector<int> v){
    int cnt = 0;
    int el;
    for(int i = 0; i<v.size(); i++){
        if(cnt == 0){
            cnt = 1;
            el = v[i];
        }
        else if(v[i] == el ){
            cnt ++;
        }
        else{
            cnt --;
        }
    }

    int cnt1 = 0;
    for(int i = 0; i<v.size(); i++){
        if(v[i]==el) cnt ++;
    }
    if(cnt1 > (v.size()/2)){
        return el;
    }
    return -1;
}
    // majority element in an array which occurs n/3 times 

// better solution

vector<int> majorityelement(vector<int> v){
    vector<int> ls;
    map<int,int> mpp;
    int n = v.size();
    int mini = (int)(n/3)+1;
    for(int i = 0; i<n; i++){
        mpp[v[i]] ++;
        if(mpp[v[i]]== mini){
            ls.push_back(v[i]);
        }
        if(ls.size() == 2) break;
    } 
    sort(ls.begin(), ls.end());
    return ls;
}

// optimal solution 

vector<int> majorityelement1(vector<int> v){
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    int n = v.size()/2;
    for(int i = 0; i<n; i++){
        if(cnt1 == 0 && el2 != v[i]){
            cnt1 = 1;
            el1 = v[i];
        }

        else if(cnt2 == 0 && el1 != v[i]){
            cnt2 = 1;
            el2 = v[i];
        }
        else if(v[i] == el1) cnt1++;
        else if(v[i] == el2) cnt2++;
        else{
            cnt1 -- , cnt2--;
        }

    }
   // checking manually the occurence of the el1 and el 2
    vector<int> ls;
    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i<v.size(); i++){
        if(el1 ==  v[i]) cnt1++;
        if(el2 ==v[i]) cnt2++;
    }

    int mini = (int)(n/3) + 1;
    if(cnt1 >= mini) ls.push_back(el1);
    if(cnt2 >= mini) ls.push_back(el2);
    sort(ls.begin(), ls.end());
    return ls;

}



// maximum subarray using kadanes algorithm

// kadanes algorithm 

long long maxsubarray(int arr[], int n){
    long long sum = 0, maxi = LONG_MIN;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        if(sum>maxi){
            maxi = sum;
        }
        if(sum < 0){
            sum = 0;
        }


    }
    return maxi;
}

// print subarrays using kadanes algorithm

long long maxsu(int arr[], int n){
    long long sum = 0 , maxi = LONG_MIN;
    int start = 0;
    for(int i = 0 ; i<n ; i++ ){
        if(sum == 0 ) {int start = i;}
        sum = sum + arr[i];

        if(sum > maxi){
            maxi = sum;
            int ansstart = start , ansend = i;
        }

        if(sum<0){
            sum = 0;
        }

    }
}

// leet code rearrange the elements of an array variety -2 



/*There’s an array ‘A’ of size
 ‘N’ with positive and negative elements
(not necessarily equal). Without altering the
 relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.
*/


vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
    
}

// LEADERS IN AN ARRAY 

vector<int> superiorelement(vector<int> &a){
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();

    for(int i = n-1; i>0; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
        }

        maxi = max(maxi, a[i]);
    }

    return ans;
}



// Consecutive sequence in array 


int longestsequence(vector<int> &nums){
    if(nums.size()== 0) return 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int lastsmaller = INT_MIN;
    int count = 0; 
    int longest = 1;
    for(int i = 0; i<n; i++){
        if(nums[i] - 1 == lastsmaller){
            count += 1;
            lastsmaller = nums[i];

        }

        else if(lastsmaller != nums[i]){
            count = 1;
            lastsmaller = nums[i];
        }

        longest = max(longest, count);
    }

    return longest;


}

        // optimal solution

int longestsubsequence2(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;

    for(int i = 0; i<n ; i++){
        st.insert(nums[i]);
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int count = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x = x+1;
                count = count + 1;

            }
            longest = max(longest , count);

                    }
    }

    return longest;
 
}


//SET OF MATRIX ZERO

// better approach
vector<vector<int>> zeromatrix(vector<vector<int>> &matrix, int n , int m){
    vector<int> col(m,0);
    vector<int> row(n, 0);

    for(int i = 0 ;i<n; i++){
        for(int j = 0; j< m ; j++){
            if(matrix[i][j] ==  0){
                col[j] = 1;
                row[i] = 1;
            }
        }
    }

    // reitrating the matrix to substitute the zero at column and row
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m ; j++){
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;

}


// ROTATE THE MATRIX BY 90 (ROTATE THE IMAGE)

void rotatematrix(vector<vector<int>> &mat){
    int n = mat.size();
// Transpose of the matrix
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j< n ; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reversing the rows
    for(int i = 0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}

// PRINTING THE MATRIX IN THE SPIRAL MANNER

vector<int> spiralmatrix(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    int left = 0, right = m -1;
    int top = 0, bottom = n-1;

    vector<int> ans;

    while(top<= bottom && left<= right){
        for(int i = left; i<= right; i++){
            ans.push_back(mat[top][i]);
        }
        top ++;

        for(int i = top; i<= bottom; i++){
            ans.push_back(mat[i][right]);
        }
        right--;

        if(top<= bottom){
            for(int i = right; i>=left; i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom --;
        }

        if(left <= right){
            for(int i = bottom; i>= top; i--){
                ans.push_back(mat[i][left]);
            }

            left ++;
        }
    }
    return ans;
}

// 3 SUM (GOOGLE )

// Brute force approach

vector<vector<int>> triple(int n , vector<int> &nums){
    set<vector<int>> st;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = k+1; k<n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin() , temp.end());
                    st.insert(temp);

                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


// Better approach

vector<vector<int>> triplet(int n , vector<int> &nums){

    set<vector<int>> st;
    for(int i = 0; i<n; i++){
        set<int> hashset;
        for(int j = i+1; j<n; j++){
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[i]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

}

// Optimal approach

vector<vector<int>> triplet(int n , vector<int> &num){
    vector<vector<int>> ans;
    sort(num.begin(), num.end());

    for(int i = 0; i<n; i++){
        if(i>0 && num[i] == num[i-1]) continue;
        int j = i+1;
        int k = n - 1;

        while(j<k){
            int sum = num[i] + num[j] + num[k];
            if(sum < 0){
                j++;
            }
            if(sum > 0){
                k-- ;
            }
            else{
                vector<int> temp = {num[i], num[j], num[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && num[j] == num[j-1]) j++;
                while(j<k && num[k] == num[k+1]) k--;
            }

        }
        return ans;
    }

}


// 4 sum (GOOGLE)

// better approach using hashset and better approach of 3 sum 

vector<vector<int>> foursum(vector<int>& nums, int target){
    int n = nums.size();
    set<vector<int>> st;
    for(int i = 0; i<n ; i++){
        for(int j = i+1; j<n ; j++){
            set<long long> hashset;
            for(int k = j+1; j<n; j++){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - (sum);
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }

        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


// optimal approach
vector<vector<int>> foursum(vector<int> &nums, int target){
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin() , nums.end());
    for(int i = 0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j = i + 1; j<n ; j++){
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = nums[i];
                sum += nums[j];
                sum+= nums[k];
                sum += nums[l];
                if(sum == target){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    k++, l--;
                    while(k<l && nums[k] == nums[k-1]) k++ ;
                    while(k<l && nums[l] == nums[l+1]) l--;
                }
                else if(sum< target) k++;
                else l--;

            }
        }
    }
    return ans;
}

// COUNT SUBARRAYS WITH XOR BEAUTY K

// optimal approach using prefix xor

int subarraywithxork(vector<int> a, int k){
    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for(int i = 0; i<a.size() ; i++){
        xr = xr ^ a[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}


// Merge intervals 

// optimal solution
vector<vector<int>> mergeoverlappe(vector<vector<int>> &arr){
    int n =arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i<n ; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }

    }
    return ans;
}

// Merge sorted 
void merge(long long arr1[], long long arr2[], int n , int m){
    int left = n-1;
    int right =0;
    while(left >= 0 && right<m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--, right++;

        }
        else{break;}}

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    }


int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}