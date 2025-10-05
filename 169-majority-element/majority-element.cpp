class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> m;
        int len = nums.size();
        auto it = m.end();

        for (int i = 0; i < len; i++) {
            it = m.find(nums[i]);
            if (it == m.end()) {
                m[nums[i]] = 1;
            } else {
                m[nums[i]]++;
            }
            if (m[nums[i]] > len / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};