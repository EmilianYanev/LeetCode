class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }

        for (size_t i = 0; i < len; i++) {
            for (size_t j = 0; j < len - i - 1; j++) {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }

        return nums[0];
    }
};