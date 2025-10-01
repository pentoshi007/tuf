// reverse a string
#include <bits/stdc++.h>

using namespace std;

string reverseString(string str)
{
    reverse(str.begin(), str.end());
    return str;
}
// check if a string is palindrome
// using two pointers
bool isPalindrome(string str)
{
    int i = 0;
    int j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
// largest odd number in a string in string format, if no odd return "", without zero prefix in starting
int largestOddNumber(string str)
{
    int n = str.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] % 2 != 0)
        {
            return str.substr(0, i + 1).erase(0, str.find_first_not_of('0'));
        }
    }
    return "";
}
// another way
string largeOddNum(string &s)
{
    // your code goes here
    int refs = 0;
    int refe = -1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 != 0)
        {
            refe = i;
            break;
        }
    }
    int j = 0;
    while (refs <= refe && s[j] == '0')
    {
        refs++;
        j++;
    }
    return s.substr(refs, refe - refs + 1);
}

// longest common prefix
string longestCommonPrefix(vector<string> &str)
{
    // Edge case: empty vector
    if (str.empty())
        return "";

    // Sort the vector to get the lexicographically smallest and largest
    // strings
    sort(str.begin(), str.end());
    // First string (smallest in sorted order)
    string first = str[0];
    // Last string (largest in sorted order)
    string last = str[str.size() - 1];

    // Compare characters of the first and last strings
    int minLength = min(first.size(), last.size());
    string ans = "";
    for (int i = 0; i < minLength; i++)
    {
        // If characters don't match, return the current prefix
        if (first[i] != last[i])
        {
            return ans;
        }
        // Append the matching character to the result
        ans += first[i];
    }

    // Return the longest common prefix found
    return ans;
}

// Isomorphic String--Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
bool isomorphicString(string s, string t)
{
    int m1[256] = {0}, m2[256] = {0};
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (m1[s[i]] != m2[t[i]])
        {
            return false;
        }
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

// rotate string:Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.A shift on s consists of moving the leftmost character of s to the rightmost position.For example, if s = "abcde", then it will be "bcdea" after one shift.
bool rotateString(string &s, string &goal)
{
    // your code goes here
    if (s.length() != goal.length())
        return false;
    s = s + s;
    int res = s.find(goal);
    if (res != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// valid anagram:Given two strings s and t, return true if t is an anagram of s, and false otherwise.An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

//--brute force: sort both strigns if not equal strings then not anagram

bool anagramStrings(string &s, string t)
{
    // your code goes here
    if (s.length() != t.length())
        return false;
    int n = s.length();
    int fres[26] = {0};
    for (int i = 0; i < n; i++)
    {
        fres[s[i] - 'a']++;
    }
    for (int j = 0; j < n; j++)
    {
        fres[t[j] - 'a']--;
    }
    for (int k = 0; k < n; k++)
    {
        if (fres[s[k] - 'a'] != 0)
            return false;
    }

    return true;
}

// sort charectors by freq:You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.If two or more characters have same frequency then arrange them in alphabetic order.
static bool comparator(pair<int, char> p1, pair<int, char> p2)
{
    if (p1.first > p2.first)
        return true;
    if (p1.first < p2.first)
        return false;
    return p1.second < p2.second;
}
vector<char> frequencySort(string &s)
{
    // your code goes here
    pair<int, char> freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = {0, i + 'a'};
    }

    // Count frequency of each character
    for (char ch : s)
    {
        freq[ch - 'a'].first++;
    }

    // Sort based on custom comparator
    sort(freq, freq + 26, comparator);

    // Collect characters with non-zero frequency
    vector<char> ans;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i].first > 0)
            ans.push_back(freq[i].second);
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << largestOddNumber(str) << endl;
    return 0;
}