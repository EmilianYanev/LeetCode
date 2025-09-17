class Solution {
public:
    bool isAlphaNumeric(char ch) {
        if((ch < 'a' || ch > 'z') && (ch < 'A' || ch > 'Z') && (ch < '0' || ch > '9')) {
            return false;
        }
        return true;
    }
    bool isUpperCase(char ch) {
        return (ch >= 'A' && ch <= 'Z');
    }
    bool isPalindrome(string s) {
        if(s.size() == 0) {
            return true;
        }
        string result;
        for (char ch : s) {
            if(!isAlphaNumeric(ch)) {
                continue;
            }
            if(isUpperCase(ch)) {
                ch += 32;
            }
            result.push_back(ch);
        }
        if(result.size() == 0) {
            return true;
        }
        int begin = 0;
        int end = result.size() - 1;

        while(begin < end) {
            if(result[begin++] != result[end--]) {
                return false;
            }
        }

        return true;
    }
};