class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        int size = 1;
        int len = nums.size();
        for(int i = 1; i < len; i++) {
            if(nums[j] != nums[i]) {
                j++;
                nums[j] = nums[i];
                size++;
            }
        }

        return size;
    }
};