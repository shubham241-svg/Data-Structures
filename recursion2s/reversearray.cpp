#include <iostream>
using namespace std;


//using single pointer method

void f(int i, int arr[], int n){
    if(i>=n/2){
        return;
    }

    swap(arr[i],arr[n-i-1]);

    f(i+1,arr,n);
}

int main(){
    int arr[] ={1,2,43,5,3};
    f(0,arr,5);

    for(int i = 0; i<5; i++){
        cout << arr[i];
    }
    return 0;
}