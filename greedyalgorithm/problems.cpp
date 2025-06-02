#include <iostream>
#include <vector>
#include <string>

using namespace std;


int splitstring(string str){

    int n = str.size();
    int cnt=0;
    vector<string> v;
    string new_str = "";
    
    for(int i= 0; i<n ;i++){
        if(cnt == 0){
            v.push_back(new_str);
            new_str = "";
        }
        
        if(str[i] == 'L'){
            cnt++;
            new_str += str[i];
            }
        else{
            cnt--;
            new_str += str[i];
        }
            
        }
    return v.size() - 1;


    }
    
