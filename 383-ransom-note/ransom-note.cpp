class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
             unordered_map<char, int> rN;
     unordered_map<char, int> mag;

     for (char ch : ransomNote) {
         if (rN.find(ch) == rN.end()) {
             rN[ch] = 1;
         }
         else {
             rN[ch]++;
         }
     }
     for (char ch : magazine) {
         if (mag.find(ch) == mag.end()) {
             mag[ch] = 1;
         }
         else {
             mag[ch]++;
         }
     }

     for (auto it : rN)
     {
        if (mag.find(it.first) == mag.end()) {
             return false;
        }
        else {
            if (it.second > mag.find(it.first)->second) {
                return false;
            }
        }
     }

     return true;
    }
};