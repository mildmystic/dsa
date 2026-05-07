/*Approach: Gravity Simulation + Matrix Rotation
1. Simulate gravity for each row by moving stones ('#') to the right until they hit an obstacle ('*') or the end of the row.
2. Rotate the resulting box 90 degrees clockwise by creating a new matrix and filling it accordingly.
Time complexity: O(m*n) due to traversing the box grid twice (once for gravity simulation and once for rotation)
Space complexity: O(m*n) for the resulting rotated box
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: apply gravity (stones fall to the right)
        for (int i = 0; i < m; i++) {
            int empty = n - 1; // position to place next stone

            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    empty = j - 1; // reset after obstacle
                } 
                else if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }

        // Step 2: rotate 90° clockwise
        vector<vector<char>> res(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return res;
    }
};