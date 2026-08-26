class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s =(n*(n+1))/2;
        for (int i: nums){
            s -=i;
        }
        return (s);
    }
};
// time= O(n)
// space = O(1)