#include <iostream>
#include <set>
using namespace std;


// LEFT ROTATE ARRAY TO D PLACES

void leftrotate(int arr[], int n , int d){
    d = d%n;

    int temp[d] ;
// creating the elements which will be rotated to back
    for(int i = 0; i<d; i++){
        temp[i] = arr[i];

    }
// shifting the elements from back to front
    for(int i = d; i< n; i++){
        arr[i-d] = arr[i];
    }

// put back temp
    for(int i = n-d ; i<n; i++){
        arr[i] = temp[i - (n-d)];
    }
}

// optimal approach for left rotate to d places

void reverse1(int arr[], int start , int end){
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++;
        end --;
    }
}

void oleftrotate(int arr[], int n , int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
    



}


// MOVE ALL THE ZEROES

// optimal approach

vector<int> movezeroes(int n , vector<int> arr){
    int j = -1;

    // finding the 1st zero element
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            j = i;
            break;

        }
    }

    if(j==-1) return arr;

    // swapping with j

    for(int i = j+1; i<n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }

    return arr;
}


// UNION OF TWO SETS 

        
        // BRUTE FORCE APPROACH

vector<int> sortedarray(vector <int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();

    set<int> st;
    for(int i = 0; i<n1; i++){
        st.insert(a[i]);
    }


    for(int i = 0; i<n2; i++){
        st.insert(a[i]);
    }


    vector<int> temp;
    for(auto it:st){
        temp.push_back(it);
    }
    return temp;
}

    // OPTIMAL APPROACH

vector<int> sortedarray(vector <int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionarr;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            if(unionarr.size() == 0||unionarr.back() != a[i]){
                unionarr.push_back(a[i]);
            }
            i++;

        }

        else{
            
            if(unionarr.size() == 0||unionarr.back() != b[j]){
                unionarr.push_back(b[j]);
            }
            j++;

        }
    }

    while(j<n2){
        if(unionarr.size() == 0||unionarr.back() != b[j]){
            unionarr.push_back(b[j]);
            }
        j++;

        }
    while(i<n1){
        if(unionarr.size()==0 || unionarr.back() != a[i]){
            unionarr.push_back(a[i]);
        }

        i++;
    }
    return unionarr;
        
    }

    
