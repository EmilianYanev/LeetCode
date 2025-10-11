class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;

        int current = 0;
        for (int n : nums) {
            current = max(n + rob1, rob2);
            rob1 = rob2;
            rob2 = current;
        }

        return rob2;
    }
};