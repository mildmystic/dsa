/*Approach: Brute Force
Time complexity: O(n * log n) due to iterating through each number and checking its digits
Space complexity: O(1) as we are using only a few variables to keep track of
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            int x = i;
            bool valid = true;
            bool changed = false;

            while (x > 0) {
                int d = x % 10;

                // invalid digits
                if (d == 3 || d == 4 || d == 7) {
                    valid = false;
                    break;
                }

                // digits that change
                if (d == 2 || d == 5 || d == 6 || d == 9) {
                    changed = true;
                }

                x /= 10;
            }

            if (valid && changed) {
                count++;
            }
        }

        return count;
    }
};