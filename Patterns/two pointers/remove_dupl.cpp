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





    /**Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well. */


    class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* l = head;
        ListNode* r = head->next;
        while(r != NULL){
            if(l->val == r->val){
                r= r->next;
                l->next = NULL;
            }else if(l->val != r->val){
                l->next = r;
                l = r;
                r=r->next;
            }
        }

        return head;
        
    }
};



/**
    remove the duplicates from the sorted linked list

    Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 */


 class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int ans = 1;
        int cnt = 1;
        int l = 0;
        int r = 1; 
        while( r < nums.size()){
            if(nums[l] == nums[r]){
                if(cnt < 2){
                    nums[l+1] = nums[r];
                    r++;
                    l++;
                    cnt++;
                    ans++;

                }
                else{r++;}
                
            }else if(nums[l] != nums[r]){
                nums[l+1] = nums[r];
                l++;
                r++;
                cnt=1;
                ans++;

            }         
        }
        cout << ans;
        return ans;

        
    }
};