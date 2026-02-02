
#include <bits/stdc++.h>
using namespace std;
//Koko eating bananas

/*
A monkey is given n piles of bananas, where the 'ith' pile has nums[i] bananas. An integer h represents the total time in hours to eat all the bananas.



Each hour, the monkey chooses a non-empty pile of bananas and eats k bananas. If the pile contains fewer than k bananas, the monkey eats all the bananas in that pile and does not consume any more bananas in that hour.



Determine the minimum number of bananas the monkey must eat per hour to finish all the bananas within h hours.


Examples:
Input: n = 4, nums = [7, 15, 6, 3], h = 8

Output: 5

Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.  */
//linear search
class Solution {
private:
    // Helper function to find the maximum element in the vector 
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        
        // Find the maximum element
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    /* Helper function to calculate total hours
    required at given hourly rate */
    long long calculateTotalHours(vector<int> &v, int hourly) {
        long long totalH = 0;
        int n = v.size();
        
        // Calculate total hours required
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }

public:
    // Function to find the minimum rate to eat bananas 
    int minimumRateToEatBananas(vector<int> nums, int h) {
        // Find the maximum number of bananas
        int maxi = findMax(nums);

        /* Find the minimum value of k
        that satisfies the condition*/
        for (int i = 1; i <= maxi; i++) {
            long long reqTime = calculateTotalHours(nums, i);
            if (reqTime <= (long long)h) {
                return i;
            }
        }

        /* Dummy return statement (should 
        not be reached in valid cases)*/
        return maxi;
    }
};
//binary search
//whenever you find pattern: not possible to possible and to find max/min and in a range then binary search
class Solution {
   private:
    int max_element(vector<int> nums) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    };

    // ✅ Changed return type from int to long long
    long long calculateTotalHours(vector<int> nums, int rate) {
        long long totalH = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalH = totalH + ceil((double)nums[i] / (double)rate);
        }
        return totalH;
    }

   public:
    int minimumRateToEatBananas(vector<int> nums, int h) {
        int low = 1;
        int high = max_element(nums);
        int ans;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long total =
                calculateTotalHours(nums, mid);  // Already long long ✅
            if (total <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

//Minimum days to make M bouquets
/*
Given n roses and an array nums where nums[i] denotes that the 'ith' rose will bloom on the nums[i]th day, only adjacent bloomed roses can be picked to make a bouquet. Exactly k adjacent bloomed roses are required to make a single bouquet. Find the minimum number of days required to make at least m bouquets, each containing k roses. Return -1 if it is not possible.


Examples:
Input: n = 8, nums = [7, 7, 7, 7, 13, 11, 12, 7], m = 2, k = 3

Output: 12

Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

*/
//linear search
class Solution {
private:
    /* Function to check if it's possible to make
    m bouquets with k flowers each on day */
    bool possible(vector<int> &nums, int day, int m, int k) {
        int n = nums.size(); 
        
        // Count of flowers bloomed
        int cnt = 0; 
        
        // Count of bouquets formed
        int noOfB = 0; 

        // Count number of bouquets that can be formed
        for (int i = 0; i < n; i++) {
            if (nums[i] <= day) {
                // Increment flower count
                cnt++; 
            } else {
                /* Calculate number of bouquets
                formed with flowers <= day */
                noOfB += (cnt / k);
                
                // Reset flower count
                cnt = 0; 
            }
        }
        // Add remaining flowers as a bouquet
        noOfB += (cnt / k); 

        /* Return true if enough 
        bouquets can be formed */
        return noOfB >= m; 
    }
public:
    /* Function to find the earliest day to
    make m bouquets of k flowers each */
    int roseGarden(int n, vector<int> nums, int k, int m) {
        
        /* Calculate the minimum 
        number of flowers required*/
        long long val = m * 1ll * k * 1ll; 
        
        /* Impossible case: not enough 
        flowers to make m bouquets*/
        if (val > n) return -1; 
        
        /* Find maximum and minimum
        bloom days in the array */
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, nums[i]); 
            maxi = max(maxi, nums[i]); 
        }

        /* Linear search to find the
        earliest day to make m bouquets */
        for (int i = mini; i <= maxi; i++) {
            if (possible(nums, i, m, k))
                return i;
        }
        
        // Return-1 if no such day exists
        return -1; 
    }
};
//binary search
class Solution {
private:
    /* Function to check if it's possible to make
    m bouquets with k flowers each on day */
    bool possible(vector<int> &nums, int day, int m, int k) {
        int n = nums.size(); 
        
        // Count of flowers bloomed
        int cnt = 0; 
        
        // Count of bouquets formed
        int noOfB = 0; 

        // Count number of bouquets that can be formed
        for (int i = 0; i < n; i++) {
            if (nums[i] <= day) {
                // Increment flower count
                cnt++; 
            } else {
                /* Calculate number of bouquets
                formed with flowers <= day */
                noOfB += (cnt / k);
                
                // Reset flower count
                cnt = 0; 
            }
        }
        // Add remaining flowers as a bouquet
        noOfB += (cnt / k); 

        /* Return true if enough 
        bouquets can be formed */
        return noOfB >= m; 
    }
public:
    /* Function to find the earliest day to
    make m bouquets of k flowers each */
    int roseGarden(int n, vector<int> nums, int k, int m) {
        
        /* Calculate the minimum 
        number of flowers required*/
        long long val = m * 1ll * k * 1ll; 
        
        /* Impossible case: not enough 
        flowers to make m bouquets*/
        if (val > n) return -1; 
        
        /* Find maximum and minimum
        bloom days in the array */
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, nums[i]); 
            maxi = max(maxi, nums[i]); 
        }

        /* Binary search to find the
        earliest day to make m bouquets */
        int left = mini, right = maxi, ans = -1;
        while (left <= right) {
            
            // Calculate the middle day
            int mid = left + (right - left) / 2; 
            
            /* Check if it's possible to 
            make m bouquets on day mid */
            if (possible(nums, mid, m, k)) {
                
                // Update the answer to mid
                ans = mid; 
                
                // Try for a smaller day
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        
        /* Return the earliest day or
        -1 if no such day exists */
        return ans; 
    }
};

