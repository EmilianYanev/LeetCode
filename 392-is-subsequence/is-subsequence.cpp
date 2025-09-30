class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t len = t.size();
        size_t index = 0;
        size_t sLen = s.size() - 1;

        if (sLen == -1) {
            return true;
        }
        if (sLen == 0) {
            for (size_t i = 0; i < len; i++) {
                if (s[index] == t[i]) {
                    return true;
                }
            }
            return false;
        }
        if (sLen == 1) {
            bool one = false;
            bool two = false;

            for (size_t i = 0; i < len; i++) {
                if(t[i] == s[0]) {
                    one = true;
                    continue;
                }

                if(t[i] == s[1]) {
                    two = true;
                }
            }

            return one && two;
        }

        for (size_t i = 0; i < len; i++) {
            if (index == sLen) {
                return true;
            }
            if (s[index] == t[i]) {
                index++;
            }
        }

        return false;
    }
};