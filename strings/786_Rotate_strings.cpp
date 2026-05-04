/*Approach: Concatenation and Substring Search
Time complexity: O(n) due to substring search
space complexity: O(n) for the temporary string created by concatenation*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        // length must match
        if (s.size() != goal.size()) return false;

        string temp = s + s;

        return temp.find(goal) != string::npos;
    }
};