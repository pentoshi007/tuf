// in one second there are 10^8 operations
// so if we have to solve a problem in 1 second, we need to have 10^8 operations
// outside int main, bool hash[10**8], and int hash[10**7]
// inside int main, bool hash[10**7], and int hash[10**6]

#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 5, 6, 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
//     int n = 17;
//     int hash[11] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         hash[arr[i]]++;
//     }
//     for (int i = 0; i < 11; i++)
//     {
//         cout << i << ":" << hash[i] << ", ";
//     }
//     return 0;
// }

// hash[26]={0} for lowercase letters
// hash[arr[i]-'a']++ -- to save space, now a will have 0 index, b will have 1 index, and so on

// in cpp we have map and unordered_map
// time complexity of map is O(logn)
// time complexity of unordered_map is O(1)
// map is sorted and unordered_map is unsorted
// map is implemented using red black tree and unordered_map is implemented using hash table
// map is slower than unordered_map
// map is used when we need to sort the keys
// unordered_map is used when we need to store the keys in any order

// return max occuring element in an array
// brute force

int mocc_brute(int arr[], int n)
{
    int vis[1000000] = {0};
    int max_count = 0;
    int ele = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (vis[arr[i]] == 0)
        {
            vis[arr[i]] = 1;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            if (count > max_count)
            {
                max_count = count;
                ele = arr[i];
            }
        }
    }
    return ele;
}

// using hash
int mocc_hash(int arr[], int n)
{
    int hash[1000000] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    int max_count = 0;
    int ele = -1;
    for (int i = 0; i < 1000000; i++)
    {
        if (hash[i] > max_count)
        {
            max_count = hash[i];
            ele = i;
        }
    }
    return ele;
}

// second most occuring element
int smocc_hash(int arr[], int n)
{
    int hash[1000000] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    int max_count = 0;
    int second_max_count = 0;
    int ele = -1;
    for (int i = 0; i < 1000000; i++)
    {
        if (hash[i] > max_count)
        {
            second_max_count = max_count;
            max_count = hash[i];
        }
        else if (hash[i] > second_max_count && hash[i] < max_count)
        {
            second_max_count = hash[i];
        }
    }

    // Find the element with second max count
    for (int i = 0; i < 1000000; i++)
    {
        if (hash[i] == second_max_count)
        {
            ele = i;
            break;
        }
    }
    return ele;
}

// sum of the highest and lowest frequency of elements
int sum_of_highest_and_lowest_frequency(int arr[], int n)
{
    int hash[1000000] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    int max_count = 0;
    int min_count = 1000000;
    for (int i = 0; i < 1000000; i++)
    {
        if (hash[i] > max_count)
        {
            max_count = hash[i];
        }
    }
    for (int i = 0; i < 1000000; i++)
    {
        if (hash[i] < min_count)
        {
            min_count = hash[i];
        }
    }
    return max_count + min_count;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 6, 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 17;
    cout << mocc_brute(arr, n) << endl;
    cout << mocc_hash(arr, n) << endl;
    cout << smocc_hash(arr, n) << endl;
    cout << sum_of_highest_and_lowest_frequency(arr, n) << endl;
    return 0;
}
