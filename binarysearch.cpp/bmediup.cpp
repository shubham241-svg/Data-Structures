#include <iostream>
using namespace std;


// finding the sqrt of an integer

int floorsqrt(int n){
    int low = 1, high = n;
    while(low <= high){
        long long mid = (low + high)/2;
        long long val = (mid * mid);
        if(val <= n){
            low = mid + 1;

        }
        else{
            high = mid - 1;
        }
    }
    return high ;
}


// Find the nth root of an integer

// function to calcuate the nth multiple of mid without exceeding the multiplication limit
int func(int mid, int n , int m){
    long long ans = 1;
    for(int i = 1; i<= n; i++){
        ans = ans * mid;
        if(ans> m){
            return 2;
        }

    }
    if(ans == m){return 1;}
    return 0;

}


    // the binary search method 
int nthroot(int n, int m){
    long long low = 1, high = m;
    while(low <= high){
        int mid = (low + high)/2;
        int midn = func(mid, n, m);
        if(midn == 1) return mid;
        else if(midn == 0) low = mid + 1;

        else{
            high = mid - 1;
        }
    }
    return  -1;
}



// KOKO ka kela


//writing the max function

int fndmax(vector<int> &v){
    int maxi = INT_MIN;
    int n = v.size();
    for(int i = 0; i<n; i++){
        maxi = max(maxi, v[i]);
    }
    return maxi;
}


// total hours required to eat kela with an k speed

int calculate(vector<int> &v, int hourly){
    int totalh = 0;
    int n = v.size();
    for(int i = 0; i<n; i++){
        totalh += ceil((double)v[i]/(double)hourly);
    }
    return totalh;
}

// minimum 

int mintoeat(vector<int> v, int h){
    int low = 1, high = fndmax(v);
    while(low<=high){
        int mid = (low + high)/2;
        int totalh = calculate(v, mid);
        if(totalh <= h){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

    }
    return low;

}


// Minimum days to make m bouquets;

// creating a possible funciton 

bool possible(vector<int> &arr, int m , int k, int day){
    int cnt = 0;
    int noofb = 0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] <= day){
            cnt ++;
        }
        else{
            noofb += (cnt/k);
            cnt = 0;
        }
    }
    noofb += (cnt/k);
    return noofb >= m;
}

// applying the binary search on this
int rosegarden(vector<int> arr, int m, int k){
     long long val = m * 1LL * k * 1LL;
     if(val > arr.size()) return -1;

     int mini = INT_MAX, maxi = INT_MIN;
     for(int i = 0; i<arr.size(); i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);

     }

     int low = mini, high = maxi;
     while(low <= high){
        int mid = (low + high)/2;
        if(possible(arr, m, k, mid)){
            high = mid -1;
        }
        else low = mid + 1;
     }
     return low;


}

// smallest divisor for a given a threshold 

int sumbyd(vector<int> &arr, int div){
    int sum = 0;
    int n = arr.size();
    for(int i = 0; i<n ; i++){
        sum += ceil((double)(arr[i])/(double)(div));

    }
    return sum;
}

int smallestDivisor(vector<int> &arr, int limit){
    if(n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(),arr.end()); // max element is the stl method
    while(low<= high){
        int mid = (low + high)/2;
        if(sumbyd(arr, mid) <= limit){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        
    }
    return low;
}

// Capacity to ship Packages within Days

int findDays(vector<int> &weights, int cap){
    int days = 1, load = 0;
    for(int i = 0; i< weights.size(); i++){
        if(weights[i] + load > cap){
            days += 1;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
        
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d){
    int low = *max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0); // stl function to calculate the net sum
    while(low <= high){
        int mid = (low + high)/2;
        int numberofdays = findDays(weights, mid);
        if(numberofdays <= d){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

    }
    return low;
}

// Find the kth missing number 

// brute approach using O(N)

int missing(vector<int> arr, int k ){
    int n = arr.size();
    for(int i = 0; i<n ; i++){
        if(arr[i]<= k )k++;
        else break;
    }
    return k ;
}




// New pattern on binary search on answer to min(max) or max(min)


// Aggressive cows

// Binary search method 
//to see if we can place an cow position with an minimum distance

bool canweplace(vector<int> &stalls, int dist, int cows){
    int cntcows= 1, coord = stalls[0];
    for(int i=0; i< stalls.size(); i++){
        if(stalls[i]- coord >= dist){ // calculating the minimum distance between two consecutive cows and stalls
            cntcows += 1;
            coord = stalls[i];
        }
        if(cntcows >= cows) return true;
    }
    return false;
}

int aggressivecows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];
    while(low <= high){
        int mid = (low + high)/2;
        if(canweplace(stalls, mid, k) == true){
            low = mid + 1;

        }
        else high = mid - 1;
    }
    return high;
}

// Book allocation problem hard 

// function to calculate no. of students

int countstudents(vector<int> &arr, int pages){
    int students = 1;
    long long pagesStudents = 0;
    for(int i = 0; i<arr.size(); i++){
        if( pagesStudents + arr[i] <= pages){

            pagesStudents += arr[i];

        }
        else{
            students += 1;
            pagesStudents = arr[i];

        }
    }
    return students;
}

// binary approach to solve this

int findpages(vector<int> &arr, int n , int m){
    if(m > n) return - 1;
    int low = *max_element(arr.begin(), arr.end()); // returns the maximum element of the array
    int high = accumulate(arr.begin() , arr.end(), 0) ;// returns the total sum of the array
    while( low <= high){
        int mid = (low + high)/2;
        int students = countstudents(arr, mid);
        if(students > m){
            low = mid  + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

// painters partition and split the largest array is same to book allocation problem

int countstudents(vector<int> &arr, int pages){
    int students = 1;
    long long pagesStudents = 0;
    for(int i = 0; i<arr.size(); i++){
        if( pagesStudents + arr[i] <= pages){

            pagesStudents += arr[i];

        }
        else{
            students += 1;
            pagesStudents = arr[i];

        }
    }
    return students;
}

// binary approach to solve this

int findpages(vector<int> &arr, int n , int m){
    if(m > n) return - 1;
    int low = *max_element(arr.begin(), arr.end()); // returns the maximum element of the array
    int high = accumulate(arr.begin() , arr.end(), 0) ;// returns the total sum of the array
    while( low <= high){
        int mid = (low + high)/2;
        int students = countstudents(arr, mid);
        if(students > m){
            low = mid  + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int partionsplit(vector<int> arr, int n , int m){
    return findpages(arr, n , m);
}


// Median of two sorted Arrays 

double median(vector<int> &a, vector<int> &b){
    int n1 = a.size(), n2 = b.size();
    int i = 0; 
    int j = 0;
    int n = (n1 + n2);
    int ind2 = n/2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int indel = -1 , ind2el  = -1;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            if(cnt == ind1) indel = a[i];
            if(cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == ind1) indel = b[j];
            if(cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }
    while(i < n1){
        if(cnt == ind1)indel = a[i];
        if(cnt == ind2)indel = a[i];
        cnt ++;
        i++;
    }

    while(j <n2){
        if(cnt == ind2) indel = b[j];
        if(cnt == ind1) indel = b[j];
        cnt ++;
        j++;
    }

    if(n%2 == 1){
        return ind2el;
    }
    return (double)(double)(indel * ind2el)/2.0;
}    


// Row with maximum number of 1s

int lowerbound(vector<int> arr, int n , int x){
    int low = 0, high = n - 1;
    int ans =  n;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;

        }

    }
    return ans;
}

int rowwithmax1(vector<int> arr, int n , int m){
    int cnt_max = 0;
    int index = -1;
    for(int i = 0; i<n ; i++){
        int cnt_ones = m - lower_bound(arr[i], m, 1);
        if(cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}


// Search in 2d matrix 

bool searchmatrix(vector<vector<int>> & mat, int target){
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = n * m - 1;
    while(low <= high){
        int mid = (low + high)/2;
        int row = mid/m;
        int col = mid % m;
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}


// search in 2d matrix for matrix having sorted indivisual rows

bool searchmatrix1ele(vector<vector<int>> &mat, int target){
    int n = mat.size();
    int m = mat[0].size();
    int row = 0, col = m -1;
    while(row <n && col >= 0){
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) row++;
        else col --;
    }
    return false;
}