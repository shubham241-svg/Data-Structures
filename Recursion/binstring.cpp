#include <iostream>
using namespace std;

void binstring(int n , int last_place , string ans){
    if(n==0){
        cout << ans << endl;
        return ;
    }

    if(last_place != 1 ){
        binstring(n-1 , 0 , ans + "0");
        binstring(n-1,1, ans + '1');
    }

    else {
        binstring(n-1, 0 , ans + "0");
    }
}

// without using last place last place is nothing but the last index of string ans
// do not check with == 0 but !=1  because in empty string we cannot check with 0 as it will give false 
// so we use not equal to 1 as when compared to ans.size()-1


void binstring1(int n , string ans){
    if(n==0){
        cout << ans << endl;
        return ;
    }

    if((ans.size()-1) != 1 ){
        binstring1(n-1 ,  ans + "0");
        binstring1(n-1, ans + '1');
    }

    else {
        binstring1(n-1, ans + "0");
    }
}



int main(){
    string p = " ";
    string a = " ";
    binstring(3, 0 , p);
    binstring1(3,  a);
}