// Check if there exists a subsequence with sum K
//  Given an array nums and an integer k. R﻿eturn true if there exist
//  subsequences such that the sum of all elements in subsequences is equal to k
//  else false.

// Example 1

// Input : nums = [1, 2, 3, 4, 5] , k = 8

// Output : Yes

// Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up
// to 8.

// Example 2

// Input : nums = [4, 3, 9, 2] , k = 10

// Output : No

// Explanation : No subsequence can sum up to 10.
class Solution {
private:
  // This method recursively checks for the subsequence with the given sum
  bool func(int ind, int sum, std::vector<int> &nums) {
    // Base case: if all elements are processed, check if sum is 0
    if (ind == nums.size()) {
      return sum == 0;
    }
    // Recursive call: include the current element in the subsequence
    // or exclude the current element from the subsequence
    return func(ind + 1, sum - nums[ind], nums) | func(ind + 1, sum, nums);
  }

public:
  // This method initiates the recursive process
  bool checkSubsequenceSum(std::vector<int> &nums, int target) {
    return func(0, target, nums); // Start the recursive process
  }
};

// Count all subsequences with sum K
// Given an array nums and an integer k.Return the number of non-empty
// subsequences of nums such that the sum of all elements in the subsequence is
// equal to k.

// Example 1

// Input : nums = [4, 9, 2, 5, 1] , k = 10

// Output : 2

// Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].

// Example 2

// Input : nums = [4, 2, 10, 5, 1, 3] , k = 5

// Output : 3

// Explanation : The possible subsets with sum k are [4, 1] , [2, 3] , [5].
class Solution {
private:
  // Helper function to count subsequences
  // with the target sum
  int func(int ind, int sum, vector<int> &nums) {
    // Base case: if sum is 0, one valid
    // subsequence is found
    if (sum == 0)
      return 1;
    // Base case: if sum is negative or
    // index exceeds array size
    if (sum < 0 || ind == nums.size())
      return 0;
    // Recurse by including current number
    // or excluding it from the sum
    return func(ind + 1, sum - nums[ind], nums) + func(ind + 1, sum, nums);
  }

public:
  // Function to start counting subsequences
  int countSubsequenceWithTargetSum(vector<int> &nums, int target) {
    return func(0, target, nums);
  }
};