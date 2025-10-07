class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int j = len - 1;
        int i = 0;

        if (len == 1 && nums[0] == val) {
            nums[0] == val + 3;
            return 0;
        }

        for (int i = 0; i < len; i++) {
            if (i >= j) {
                break;
            }
            while (j >= 0 && nums[j] == val) {
                nums[j--];
            }
            if (i >= j) {
                break;
            }
            if (j >= 0 && nums[i] == val) {
                swap(nums[i], nums[j--]);
            }
        }
        if (j >= 0 && nums[j] == val) {
            return j;
        }
        return j + 1;
    }
};