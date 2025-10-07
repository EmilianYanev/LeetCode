class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> rainIndex;
        vector<int> dryDays;
        auto it = rainIndex.end();
        int len = rains.size();
        int len1 = 0;
        int check = 0;
        vector<int> ans(len, -1);
        for (int i = 0; i < len; i++) {
            if (rains[i] == 0) {
                dryDays.push_back(i);
                continue;
            }

            it = rainIndex.find(rains[i]);
            if (it == rainIndex.end()) {
                rainIndex[rains[i]] = i;
            } else {
                len1 = dryDays.size();
                if (len1 == 0) {
                    vector<int> empty;
                    return empty;
                }
                check = it->second;
                for (int j = 0; j < len1; j++) {
                    if (dryDays[j] > it->second) {
                        ans[dryDays[j]] = it->first;
                        dryDays.erase(dryDays.begin() + j);
                        rainIndex[rains[i]] = i;
                        break;
                    }
                }
                if (check == it->second) {
                    vector<int> empty;
                    return empty;
                }
            }
        }
        len1 = dryDays.size();
        for (int i = 0; i < len1; i++) {
            ans[dryDays[i]] = 1;
        }
        return ans;
    }
};