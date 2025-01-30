#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*k) where k is the number of elements in the subarray
// space complexity: O(k) where k is the number of elements in the subarray
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maximumSubarraySum = 0;
        for(int i = 0; i <= n - k; i++){ // iterate through last index also
            unordered_set<int> us;
            bool flag = true;
            long long currSum = 0;
            for(int j = i; j < i + k; j++){
                if(us.find(nums[j]) != us.end()){
                    flag = false;
                    break;
                }
                us.insert(nums[j]);
                currSum += nums[j];
            }
            if(flag) {
                maximumSubarraySum = max(maximumSubarraySum,currSum);
            }
        }
        return maximumSubarraySum;
    }
};

// this code will generate time limit exceeded error so the optimised will be sliding window approach

// Time Complexity: O(n) where n is the number of elements in the array
// space complexity: O(k) where k is the number of elements in the subarray
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maximumSubarraySum = 0;
        long long currSum = 0;
        unordered_map<int,int> ump;
        // first k window sum
        for(int i = 0; i < k; i++){
            currSum += nums[i];
            ump[nums[i]]++;
        }
        // check in first window if it has all distinct elements
        if(ump.size() == k) {
            maximumSubarraySum = currSum;
        }
        for(int i = k; i < nums.size(); i++){
            currSum += nums[i];
            ump[nums[i]]++;

            // remove the first element from the previous window
            int prev = nums[i - k];
            currSum -= prev;
            ump[prev]--; // removing the count of the element from hash map by 1
            if(ump[prev] == 0) {
                ump.erase(prev);
            }
            if(ump.size() == k){
                maximumSubarraySum = max(maximumSubarraySum,currSum);
            }
        }
        return maximumSubarraySum;
    }
};