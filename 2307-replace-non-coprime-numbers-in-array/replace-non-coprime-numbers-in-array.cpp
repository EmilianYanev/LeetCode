class Solution {
public:
    long long gcd(long long a, long long b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }

    long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }
        vector<int> result;
        long long current = 0;
        for (int n : nums) {
            current = n;
            while (!result.empty()) {
                if(result.back() == current && current == 1) {
                    break;
                }
                if(result.back() == current) {
                    result.pop_back();
                    break;
                }
                if (gcd(result.back(), current) == 1) {
                    break;
                } else {
                    current = lcm(current, result.back());
                    result.pop_back();
                }
            }
            result.push_back(current);
        }
        return result;
    }
};