#include <bits/stdc++.h>
using namespace std;

// fibonacci series

int f(int n, vector<int> &dp){
    if(n <=1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

//without using any space

int fibwspace(int n){
    int prev2 = 0;
    int prev = 1;

    for(int i = 2; i<=n ; i++){
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }

    cout << prev;
    return 0;
}


// DP 1d

// climb stairs


// memoization climb stairs

int helepr(int n , vector<int> &dp){
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1) + f(n-2);

}

int climbstairs(int n){
    vector<int> dp(n+1, -1);
    return helper(n, dp);


}

// bottom up - Tabulation()
int climbstairs(int n ){
    if(n == 0) return 1;
    if(n == 1) return 1;

    vector<int> dp(n +1, 0);
    for(int i = 2; i<=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];

    }

    return dp[n]
}



/* Frog jump */
    //Recursion

    int frog(int n ){
        if(n == 0) return 0;

        int left = frog(n-1) + abs(frog[n] - frog[n-1]);
        int right = INT_MAX;
        if(n > 1) right = frog(n-2) + abs(frog[n] - frog[n-2]);

        return min(left, right);
    }

    // memoization

    int f(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[ ];
        int left = f(n-1) + abs(f[n] - f[n-2]);
        int right = f(n-2) + abs(f[n] - f[n-2]);

        return dp[n] = min(left, right);
    }

    // space optimized TC - O(N) and sc - O(1)
    int frog(int n){
        int prev = 0;
        int prev1 =0;

        for(int i = 1; i<n; i++){
            int fs = prev + abs(frog[n] - frog[n-1]);
            int ss = INT_MAX;
            if(i > 1) ss = prev1 + abs(frog[n] - frog[n-2]);

            int curr = min(fs, ss);
            prev1 = prev;
            prev = curr;
        }

        return prev;
    }


// frogs with k jumps

class Solution {
public:
    int helper(vector<int>& heights, int n, int k) {
        if (n == 0) return 0;  // base case: first stone cost = 0

        int mm = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (n - j >= 0) {
                int fs = helper(heights, n - j, k) 
                         + abs(heights[n] - heights[n - j]);
                mm = min(mm, fs);
            }
        }
        return mm;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return helper(heights, n - 1, k);
    }
};

// memoized one 
class Solution {
public:
    int helper(vector<int>& heights, int n, int k, vector<int>& dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int mm = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (n - j >= 0) {
                int fs = helper(heights, n - j, k, dp) 
                         + abs(heights[n] - heights[n - j]);
                mm = min(mm, fs);
            }
        }
        return dp[n] = mm;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return helper(heights, n - 1, k, dp);
    }
};

// tabulated one

class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, INT_MAX);

        dp[0] = 0; // cost to stay at stone 0 is 0

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
                }
            }
        }

        return dp[n - 1];
    }
};