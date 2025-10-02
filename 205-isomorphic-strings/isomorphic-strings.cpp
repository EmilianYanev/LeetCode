class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        int len = s.size();
        auto it1 = s_to_t.begin();
        auto it2 = t_to_s.begin();
        for (size_t i = 0; i < len; i++) {
            it1 = s_to_t.find(s[i]);
            it2 = t_to_s.find(t[i]);
            if (it1 == s_to_t.end() && it2 == t_to_s.end()) {
                s_to_t[s[i]] = t[i];
                t_to_s[t[i]] = s[i];
            } else if ((it1 != s_to_t.end() && it2 == t_to_s.end()) ||
                       (it1 == s_to_t.end() && it2 != t_to_s.end())) {
                        return false;
                       }
                else if (it1->second != t[i] || it2->second != s[i]) {
                    return false;
                }
        }

        return true;
    }
};