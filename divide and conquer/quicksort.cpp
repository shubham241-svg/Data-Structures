#include <iostream>
#include <vector>
using namespace std;

void printarr(int arr[], int n){
    for(int i = 0 ; i< n; i++){
        cout<< arr[i]<< " ";
    }

    cout<< endl;
}

int partition(int arr[], int si, int ei){
    int i = si -1 ;
    int pivot = arr[ei];

    for(int j =si; j<ei; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[ei]);

    //pivot index 
    return i ; 
}


void quicksort(int arr[], int si , int ei){
    if(si >= ei){
        return ;

    }

    int pivotidx = partition(arr, si , ei);
    
    quicksort(arr, si , pivotidx - 1);// left half
    quicksort(arr, pivotidx + 1, ei); // Right half
    }


int main(){
    int arr[] = {6,4,7,3,5,2};
    int n = 6;

    quicksort(arr, 0, n-1);
    printarr(arr, 6);

    return 0;

}
