/*Approach: Prefix and Suffix Arrays
1. Create a prefix maximum array (prefMax) where prefMax[i] is the maximum value from the start of the array to index i.
2. Create a suffix minimum array (suffMin) where suffMin[i] is the  minimum value from index i to the end of the array.
3. Iterate through the array and identify segments where prefMax[i] <= suffMin[i + 1]. This indicates that the segment can be assigned the maximum value found in that segment.
4. Update the answer array with the maximum value for each segment. 
Time complexity: O(n) due to single pass for prefix and suffix arrays and another pass for constructing the answer
Space complexity: O(n) for the prefix and suffix arrays and the answer array        
*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n), suffMin(n);

        // prefix maximum
        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        // suffix minimum
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        vector<int> ans(n);

        int start = 0;
        int segmentMax = nums[0];

        for (int i = 0; i < n; i++) {
            segmentMax = max(segmentMax, nums[i]);

            // component ends
            if (i == n - 1 || prefMax[i] <= suffMin[i + 1]) {

                for (int j = start; j <= i; j++) {
                    ans[j] = segmentMax;
                }

                start = i + 1;

                if (start < n)
                    segmentMax = nums[start];
            }
        }

        return ans;
    }
};