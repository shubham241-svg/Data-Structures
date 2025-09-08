#include<bits/stdc++.h>
using namespace std;
#define int long long

/**
 * 
 *  two array a , and b same length n 
 */

bool pussy(int n , vector<int> &a, vector<int> &b){
    for(int i = 0; i< n; i++){
        if(a[i] > b[i]) return false;
    }

    return true;
}

int func(int n , vector<int> &a, vector<int> &b){

    int cnt = 0;
    
    // while(!pussy(n, a, b)){
    // for(int i = 0; i<n; i++){
    //     if(a[i] > b[i]){ a[i] = a[i] - 1; cnt++;}
    //     else if(b[i] > a[i]){a[i] = a[i] + 1; cnt++;}
    // }
    // }
    // return cnt;

    for(int i = 0; i<n; i++){
        if(a[i] > b[i]) cnt += a[i] - b[i];
    }

    return cnt + 1;

}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    for(int i = 0; i<n; i++){
        cin >> b[i];
    }

    cout << func(n, a, b)<< endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }
}