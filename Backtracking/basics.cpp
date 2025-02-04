#include <iostream>
#include <string>
#include <vector>
using namespace std;

void changeArr(int arr[], int n, int i){
    if(i == n){
        for(int i= 0; i<n ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }


    arr[i] = i+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2;
} 




// finding the subsets of strings

void printsubstr(string str, string subset){
    if(str.size() == 0){
        cout << subset << "\n";

    }

    char ch = str[0];

    //yes choice
    printsubstr(str.substr(1,str.size()-1), subset + ch);

    //no choice
    printsubstr(str.substr(1, str.size()-1), subset);
}



// finding permutation for the strings

void permutations(string str, string ans){
    if(str.size() == 0){
        cout << ans << "\n";  // Base case: print the completed permutation
        return;
    }

    int n = str.size();
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];  // Pick a character at index 'i'

        // Create new string excluding the picked character
        string newstr = str.substr(0, i) + str.substr(i + 1, n - i - 1);

        // Recursive call with the remaining characters and updated answer
        permutations(newstr, ans + ch);
    }
}

void printBoard(vector<vector<char>> board){
    int n = board.size();
    for(int i = 0; i<n; i++){
        for(int j=0; j<n ; j++){
            cout<< board[i][j]<< " ";
        }
        cout<< endl;
    }
}


int main(){
    string str = "abc";

    vector<vector<char>> board;
    int n=2;

    for(int i = 0; i<n; i++){
        vector<char> newrow;
        for(int j=0; j<n ; j++){
            newrow.push_back('.');
        }
        board.push_back(newrow);
    }

    printBoard(board);
    return 0;
    
}