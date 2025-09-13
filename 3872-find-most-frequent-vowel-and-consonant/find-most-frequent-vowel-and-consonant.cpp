class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }

        return false;
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> vowels;
        unordered_map<char, int> consonants;

        for (char ch : s) {
            if (isVowel(ch)) {
                if (vowels.find(ch) != nullptr) {
                    vowels.find(ch)->second++;
                } else {
                    vowels.insert({ch, 1});
                }
            } else {
                if (consonants.find(ch) != nullptr) {
                    consonants.find(ch)->second++;
                } else {
                    consonants.insert({ch, 1});
                }
            }
        }
        int biggest = 0;

        for (auto it : vowels) {
            if (it.second > biggest) {
                biggest = it.second;
            }
        }
        int biggest2 = 0;
        for (auto it : consonants) {
            if (it.second > biggest2) {
                biggest2 = it.second;
            }
        }

        return biggest + biggest2;
    }
};