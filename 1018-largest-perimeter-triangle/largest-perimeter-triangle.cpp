class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c = nums.size() - 1;
        int b = c - 1;
        int a = b - 1;
        while(a >= 0) {
            if(nums[a] + nums[b] > nums[c]) {
                return nums[a] + nums[b] + nums[c];
            }
            c--;
            b--;
            a--;
        }

        return 0;
    }
};