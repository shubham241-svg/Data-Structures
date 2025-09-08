#include <bits/stdc++.h>
using namespace std;

int balls(int n , int x, int y, vector<int> &v){
    int cnt = 0;
    for(auto &it: v){
        if(it >= x &&  it <= y)cnt++;
    }
    return cnt;
}

int main() {
	// your code goes here
	
	int t;
	while(t){
	    
	    int n, x, y;
	    cin>> n ;
	    cin >> x;
	    cin >> y;
	    
	    
	    
	    vector<int> v(n);
	    for(int i = 0; i<n; i++){
	        cin >> v[i];
	    }
	    
	    cout << balls(n , x, y, v) << endl;
	    t--;
	    
	}

}
