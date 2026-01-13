#include <bits/stdc++.h>
using namespace std;


/* 2nd problem  Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

*/
int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int r = 1;
        int ans = 1;
        while(r < nums.size()){
            if(nums[r] == nums[i]){
                r++;

            }
            else if(nums[i] != nums[r]){
                nums[i+1] = nums[r];
                i++;
                r++;
                ans++;
            }
        }
        return ans;
          
    }
