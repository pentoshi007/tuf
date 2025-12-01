class Solution {
    private:
     void merge(vector<int>& nums, int low, int mid, int high) {
         vector<int> temp;
         int left = low;
         int right = mid + 1;
 
         // Main merging loop
         while (left <= mid && right <= high) {
             if (nums[left] <= nums[right]) {
                 temp.push_back(nums[left]);
                 left++;
             } else {
                 temp.push_back(nums[right]);
                 right++;
             }
         }
 
         // Copy any remaining elements from left subarray
         while (left <= mid) {
             temp.push_back(nums[left]);
             left++;
         }
 
         // Copy any remaining elements from right subarray
         while (right <= high) {
             temp.push_back(nums[right]);
             right++;
         }
 
         // Write sorted subarray back to original vector
         for (int i = low; i <= high; i++) {
             // cout<<"low: "<<low<<" "<<"mid: "<<mid<<" "<<"high: "<<high<<" ";
             nums[i] = temp[i - low];
         }
         // cout<<endl;
     }
 
     void mergeSortHelper(vector<int>& nums, int low, int high) {
         if (low >= high) { // Correct base case!
             return;
         }
         int mid = low + (high - low) / 2;
         mergeSortHelper(nums, low, mid);
         mergeSortHelper(nums, mid + 1, high);
         merge(nums, low, mid, high);
     }
 
    public:
     vector<int> mergeSort(vector<int>& nums) {
         int left = 0;
         int right = nums.size() - 1;
         mergeSortHelper(nums, left, right);
         return nums; // returns the sorted vector
     }
 };
 