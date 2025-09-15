class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char, char> broken;

        for (char ch : brokenLetters) {
            if (broken.find(ch) == broken.end()) {
                broken.insert({ch, ch});
            }
        }

        vector<string> words;
        string input;
        int len = text.size();

        for (size_t i = 0; i < len; i++) {
            if (text[i] == ' ') {
                words.push_back(input);
                input.clear();
            }
            input.push_back(text[i]);
        }
        words.push_back(input);

        int result = words.size();
        for (string s : words) {
            for (char ch : s) {
                if (broken.find(ch) != broken.end()) {
                    result--;
                    break;
                }
            }
        }

        return result;
    }
};