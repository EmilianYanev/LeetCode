class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int len = nums.size();

        int i = 0;
        int j = 0;

        for (int k = len - 1; k > 1; k--) {
            j = k - 1;
            i = 0;

            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    result += j - i;
                    j--;
                    continue;
                } 
                i++;
            }
        }

        return result;
    }
};