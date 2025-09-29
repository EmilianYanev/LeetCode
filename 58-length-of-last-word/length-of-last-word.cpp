class Solution {
public:
    int lengthOfLastWord(string s) {
        string delim = " ";
        while (s[s.size() - 1] == ' ') {
            s.erase(s.size() - 1, 1);
        }
        int current = s.find(delim);

        if (current == string::npos) {
            return s.size();
        }
        string result;
        while (current != string::npos) {
            s.erase(0, current + 1);
            current = s.find(delim);
        }

        return s.size();
    }
};