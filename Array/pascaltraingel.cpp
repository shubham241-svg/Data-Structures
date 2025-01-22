#include <iostream> 
#include <vector>
using namespace std;
// function to generate the entire row of an pascal triangle for any given row
vector<int> generaterow(int row){
    long long ans= 1;
    vector<int> ansrow;
    ansrow.push_back(1);
    for(int col=1; col<row ; col++){
        ans = ans * (row - col);
        ans = ans/(col);
        ansrow.push_back(ans);
    }

    return ansrow;
}

// to print the pascal triangle

vector<vector<int>> pascaltriangle(int n ){
    vector<vector<int>> ans;
    for(int i = 1; i<=n; i++){
        ans.push_back(generaterow(i));
    }

    return ans;
}
