#include <iostream>
#include <string>
using namespace std;


/*Recursion(AssignmentQuestions)

Question1:WritearecursivefunctiontoperformBinarySearch.Input:arr[]={1,2,3,4,5,6,7},n=7,key=5
Output:4(indexofkey)

*Usethestartingindex&endingindexlogicusedinrotated,sortedarrayQs
*/


int binsearch(int arr[], int si , int ei , int key){

    if(si> ei){
        return -1;
    }

    int mid = (si + ei)/2 ; 

    if(arr[mid] == key ){
        return mid;
    }

    else if(arr[mid]> key){
        return binsearch(arr, si, mid -1, key);
            }

    else{
        return binsearch(arr, mid +1 , ei , key);
    }
    }


    /*ForagivenintegerarrayofsizeN.You have to find all the occurrences(indices) of a given element(Key)andprintthem.
    Use a recursivefunction to solve this problem.
    SampleInput:arr[]={3,2,4,5,6,2,7,2,2},key=2
    SampleOutput:1578*/

void alloccurence(int arr[], int key , int i , int n ){

    if( i == n ){
        return ;
    }

    if(arr[i] == key){
        cout<< i << " ";
    }

    alloccurence(arr, key, i+1 , n);
}


/* We are given a string S,we need to find the count of all contiguous substrings starting and ending 
with the same character.[LeetcodePremiumQs]

SampleInput1:S="abcab"
SampleOutput1:7
There are 15 substrings of "abcab":a,ab,abc,abca,abcab,b,bc,bca,bcab,c,ca,cab,a,ab,b
Outoftheabovesubstrings,there are 7substrings:a,abca,b,bcab,c,aandb.So,only7contiguoussubstringsstartandendwiththesamecharacter.

SampleInput2:S="aba"Sample
Output2:4Thesubstringsarea,b,aandaba*/



int substringcheck(string str , int i , int n , int count ){
    if(i == n ){
        return count;
    }

    string x = str.substr(i, n);
    if(x[i] == x[n]){
        count += 1;
        substringcheck(str, i, n-1 , count)   ; }

    
    substringcheck(str, i , n-1, count);




}


// tower of hanoi

void towerofhanoi(int n , string src, string helper, string dest){
    if( n == 1){
        cout<< "transfer disk "<< n << " from "<< src<< " to "<< dest << endl;

        return ; 
    }

    //transfer top n-1 from src to helper using dest as helper 

    towerofhanoi(n-1, src, dest, helper);

    // transfer nth from src to dest 
    cout << "transfer disk " << n << " from " << src << " to " << helper << endl;

    //transfer n - 1 from the helper to src as 'helper'

    towerofhanoi(n-1, helper, src, dest);

}

int main(){
    int count = 0;
    string x = " abcab";

    cout << substringcheck(x, 0 , x.size()-1, count);

    cout<< x.substr(0,x.size()-1);
    return 0;
}