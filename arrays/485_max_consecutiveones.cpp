class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxcount=0;
        int n = nums.size();

        for (int i=0;i<n;i++){
            if (nums[i]==1){
                count +=1;
                maxcount = max(count,maxcount);

            }
            if (nums[i]==0){
                count = 0;
            }
        }
        return maxcount;
    }
};
// time = O(n)
// space = O(1)