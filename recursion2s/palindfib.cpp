#include <iostream>
using namespace std;

bool f(int i , string n){

    if(i>= n.size()/2){
        return true;
    }

    if(n[i] != n[n.size()-i-1]){
        return false;

    }

    return f(i+1,n);
    
}

// fibonacci using 2 recursion function calls

int fib(int n) {
        if(n<=1){
            return n;
        }
        int first = fib(n-1);// 1st recursion call
        int second = fib(n-2); // 2nd recursion calls
        return first + second;
        
    }

int main(){
    string s = "MADAM";
    cout<<  f(0 , s);
}