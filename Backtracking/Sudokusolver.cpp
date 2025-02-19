#include <iostream>
#include <vector>
using namespace std;

void printsud(int sud[][9]){
    for(int i = 0 ; i<9 ; i++){
        for(int j = 0 ; j<9; j++){
            cout<< sud[i][j] << " ";
        }
        cout<< endl;
    }

}

bool isSafe(int sudo[9][9], int row, int col, int digit ){

    //vertical 

    for(int i = 0; i<= 8 ; i++){
        if(sudo[i][col] == digit){
            return false;
        }
    }

    //horizontal
    for(int j = 0; j<=8 ; j++){
        if(sudo[row][j] == digit){
            return false;
        }
    }

    // 3X3 grid
    int startRow  = (row/3) * 3;
    int startCol = (col/3) * 3;

    for(int i = startRow; i<= startRow + 2; i++){
        for(int j = startCol; j<= startCol + 2; i++){
            if(sudo[i][j] == digit){
                return false;
            }
        }
    }
    return true;


}




bool sudokousolver(int sudo[9][9], int row, int col){
    if(row == 9){
        //sudokou solve
        printsud(sudo);
        return true;
    }

    int nextrow = row;
    int nextcol = col + 1;
    if(nextcol == 9){
        nextrow = row + 1;
        nextcol = 0;
    }

    if(sudo[row][col] != 0){
        return sudokousolver(sudo, nextrow, nextcol);
    }

    for(int digit = 1; digit <= 9; digit++){

        if(isSafe(sudo, row, col, digit)){
            sudo[row][col] = digit;
            if(sudokousolver(sudo, nextrow, nextcol)){
                return true;
            }

            sudo[row][col] = 0;
        }

    }
    return false;

}


int main(){

    int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
}