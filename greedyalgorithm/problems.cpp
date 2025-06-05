#include <iostream>
#include <vector>
#include <string>

using namespace std;


int splitstring(string str){

    int n = str.size();
    int cnt=0;
    vector<string> v;
    string new_str = "";
    
    for(int i= 0; i<n ;i++){
        if(cnt == 0){
            v.push_back(new_str);
            new_str = "";
        }
        
        if(str[i] == 'L'){
            cnt++;
            new_str += str[i];
            }
        else{
            cnt--;
            new_str += str[i];
        }
            
        }
    return v.size() - 1;


    }
    
string getSmallestString(int n , int k){

    string res(n, 'a');
    int rem = k - n;
    for(int i = n-1; i>=0 && remaining > 0; i--){
        int add = min(25, remaining); // maximum we can add to 'a' to reach z
        res[i] = 'a' + add; // convert to the new character
        remaining -= add;

    }

    return res;
}



int minChocolatesLeft(int c, int n) {
    int low = 1, high = c, best_k = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long sum = 1LL * n * (2LL * mid + n - 1) / 2;

        if (sum <= c) {
            best_k = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    long long used = 1LL * n * (2LL * best_k + n - 1) / 2;
    return c - used;
}

int main() {
    int c = 20, n = 5;
    cout << minChocolatesLeft(c, n) << endl;
    return 0;
}
