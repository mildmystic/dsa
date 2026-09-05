class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=0;
        int count = 0;
        for (int i : nums){
            if (count ==0){
                element = i;
            }
            if (element == i){
                count ++;
            }
            else{  // if (element != nums[i])
                count --;   
            }
        }
        return element;
    }
};