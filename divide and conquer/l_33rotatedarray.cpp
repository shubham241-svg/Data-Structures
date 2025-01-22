#include <iostream>
#include <vector>
using namespace std;

int search(int arr[], int si , int ei, int tar){ // O(log n )
    if(si>ei){
        return -1;
    }

    int mid = si + (ei - si )/2;
    if(arr[mid]== tar){
        return mid;
    }
// to check for line 1
    if(arr[si]<= arr[mid] ){
        //l1
        if(arr[si]<=tar && tar <= arr[mid]){
            //left half
            return search(arr, si, mid-1 , tar);
        }
        else{
            //right half
            return search(arr, mid +1 , ei , tar);
        }


    }

    else{
        //line 2
        if(arr[mid]<= tar && tar <= arr[ei]){
            //right half
            return search(arr, mid + 1, ei, tar);
        }
        else{
            //left half
            return search(arr, si, mid-1, tar);
        }
    }
}

int main(){
    int arr[9] = {4,5,6,7,8,0,1,2,3};
    int n = 9;

    cout << " idx "<< search(arr, 0 , n-1, 0) << endl ;
    return 0;

}