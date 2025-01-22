#include <iostream>
using namespace std;

// largest element in a array

void le(int arr[], int n){
    int largest =0 ;
    for(int i=0; i<n; i++){
        if(largest <= arr[i]){
            largest = arr[i];
        }
    
    cout << largest; 


    }
}

// 2nd largest element in a array

int secondlargest(int arr[], int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i =0 ; i<n; i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }

        else if(arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }


    }

    return slargest ;


}


// remove duplicates

int rd(int arr[], int n){
    int i = 0;
    for(int j = 1; j<n;j++){
        if(arr[j]==arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }

    return i+1;
}