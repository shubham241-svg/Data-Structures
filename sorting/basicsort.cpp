#include <iostream>
using namespace std;

// selection sort
// get the minimum in the entire array and then swap t 

void selection_sort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int mini = i;

        for(int j = i; j<=n-1; j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i]; // swapping
        arr[i] = temp;
        
    }
}

// bubble sort
// pushes the maximum element to the last by adjacent swapping

void bubblesort(int arr[], int n){

    int didswap = 0;
    for(int i = n-1; i<=0; i--){
        for(int j= 0; j<= i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);

                didswap = 1;
            }
        }

        if(didswap = 0){break;}
    }
}

//insertion sort 

void insertionsort(int arr[], int n ){
    for(int i = 0; i<= n-1; i++){
        int j=i;

        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}


// merge sort
// divide and merge concept
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = high;
    while(left<=mid && right<= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }



    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
}

void ms(vector<int> &arr, int low, int high){
    if(low == high) return ;
    int mid  = (low+high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void mergesort(vector<int> &arr, int n){
    ms(arr,0,n-1);
}