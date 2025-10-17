// move zeroes to end of array
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int j = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[++j], nums[i]);
            }
        }
    }
};
// remove duplicates from sorted array
//---brute force
// time complexity o(nlogn+n),space complexity o(n)
class Solution
{
public:
    // Function to remove duplicates from the array
    int removeDuplicates(vector<int> &nums)
    {

        /* Set data structure to store unique
        elements maintaining the sorted order */
        set<int> s;

        // Add all elements from array to the set
        for (int val : nums)
        {
            s.insert(val);
        }

        // Get the number of unique elements
        int k = s.size();

        int j = 0;
        // Copy unique elements from set to array
        for (int val : s)
        {
            nums[j++] = val;
        }

        // Return the number of unique elements
        return k;
    }
};

//--optimal
// time complexity o(n),space complexity o(1)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int index = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[index])
            {
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
};

// find the missing number in an array
// brute force--o(n^2)
//--optimal-1
class Solution
{
public:
    // Function to find the missing number
    int missingNumber(vector<int> &nums)
    {
        // Calculate N from the size of nums
        int N = nums.size();

        // Summation of first N natural numbers
        int sum1 = (N * (N + 1)) / 2;

        // Summation of all elements in nums
        int sum2 = 0;
        for (int num : nums)
        {
            sum2 += num;
        }

        // Calculate the missing number
        int missingNum = sum1 - sum2;

        // Return the missing number
        return missingNum;
    }
};
//--optimal-2
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int xor1 = 0, xor2 = 0;

        // Calculate XOR of all array elements
        for (int i = 0; i < nums.size(); i++)
        {
            xor1 = xor1 ^ (i + 1); // XOR up to [1...N]
            xor2 = xor2 ^ nums[i]; // XOR of array elements
        }

        // XOR of xor1 and xor2 gives missing number
        return (xor1 ^ xor2);
    }
};

// union of two sorted arrays
// brute force
class Solution
{
public:
    vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
    {
        // Using set for storing unique elements
        set<int> s;
        vector<int> Union;

        // Insert all elements of nums1 into the set
        for (int num : nums1)
        {
            s.insert(num);
        }

        // Insert all elements of nums2 into the set
        for (int num : nums2)
        {
            s.insert(num);
        }

        // Convert the set to vector to get the union
        for (int num : s)
        {
            Union.push_back(num);
        }

        return Union;
    }
};
// optimal
class Solution
{
public:
    vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> uni;
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
            {
                if (uni.size() == 0 || uni.back() != nums1[i])
                {
                    uni.push_back(nums1[i]);
                }
                i++;
            }
            else
            {
                if (uni.size() == 0 || uni.back() != nums2[j])
                {
                    uni.push_back(nums2[j]);
                }
                j++;
            }
        }
        while (i < n1)
        {
            if (uni.size() == 0 || uni.back() != nums1[i])
            {
                uni.push_back(nums1[i]);
            }
            i++;
        }
        while (j < n2)
        {
            if (uni.size() == 0 || uni.back() != nums2[j])
            {
                uni.push_back(nums2[j]);
            }
            j++;
        }
        return uni;
    }
};
// intersection of two sorted arrays
// brute force
class Solution
{
public:
    // Function to find intersection of two sorted arrays
    vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        // To maintain visited status
        vector<int> visited(nums2.size(), 0);

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {

                /*If nums1[i] is equal to nums2[j] and nums2[j]
                is not visited then add nums2[j] in ans.*/
                if (nums1[i] == nums2[j] && visited[j] == 0)
                {
                    ans.push_back(nums2[j]);

                    // Mark as visited
                    visited[j] = 1;

                    break;
                }
                /** If num2[j] is greater than nums1[i]
                break out of the loop */
                else if (nums2[j] > nums1[i])
                    break;
            }
        }
        // Return ans vector
        return ans;
    }
};

// optimal
class Solution
{
public:
    vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        vector<int> inter;
        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
            {
                i++;
            }
            else if (nums2[j] < nums1[i])
            {
                j++;
            }
            else
            {
                inter.push_back(nums1[i]);
                i++;
                j++;
            };
        };
        return inter;
    };
};
