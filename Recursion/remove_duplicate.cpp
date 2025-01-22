#include <iostream>
using namespace std;


void removeduplicates(string str, string ans ,int i ,  bool map[26]){


    if( i == str.size()){
        cout << "ans " << ans << endl;
        return ;
    }

    char ch = str[i];
    int mapidx = int (ch - 'a');

    if(str[mapidx]){
        removeduplicates( str, ans, i +1 , map);
    }

    else{
        
        map[mapidx] = true;
        removeduplicates(str , ans+str[i], i+1, map);
    }



}

int main(){

    string str = "hello";
    string ans = " ";
    bool map[26] = {false};

    removeduplicates(str, ans, 0, map);
    return 0;





}