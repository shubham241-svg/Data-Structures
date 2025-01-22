#include <iostream>
#include <vector>
using namespace std;

int i =1;
void printNos(int N)
    {   
    //Your code here
    if (i > N){
            return ;
        }
        
    cout<< i;
    i++;
    printNos(N);
    }

// sum of n terns using paremetrized way mostly used for printing cases
void su(int i , int sum){
    if(i<1){ cout<< (sum);}

    su(i-1,sum+1);
    

}

// sum of n terms using functional method which is used for return cases
int s(int n){
    if(n==0){
        return 0;
    }
    return n + s(n-1);
}

// factorial of the program

int f(int n){
    if(n==0){return 1;}
    return n * f(n-1);
}


 
vector<long long> c;
vector<long long> factorialNumbers(long long n,long long i) {
        // Write Your Code her
        
    if(n == 0){
        return c;
        }
        
    if(f(n) <= i){
        c.push_back(f(n));
            
        }
        
    factorialNumbers(n-1,i);
        
        
        
        
    }
    int main(){
        long long x;
        cin>> x;
        factorialNumbers(x,x);
    }