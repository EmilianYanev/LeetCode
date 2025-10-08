class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
             vector<int> result;

     //sort(spells.begin(), spells.end());
     sort(potions.begin(), potions.end());

     int len = spells.size();
     int l = 0;
     int len1 = potions.size() - 1;
     int r = len1;
     int m = 0;
     int current = 0;
     long long multiple = 0;
     long long a = 0;
     long long b = 0;
     bool hit = false;
     for (size_t i = 0; i < len; i++) {
         while (r >= l) {
             m = l + (r - l) / 2;
             a = potions[m];
             b = spells[i];
             multiple = a * b;
             if (multiple >= success) {
                 current = m;
                 hit = true;
                 r = m - 1;
             }
             else {
                 l = m + 1;
             }
         }
         if (current == 0 && !hit) {
             result.push_back(current);
         }
         else {
             result.push_back(len1 - current + 1);
         }
         hit = false;
         l = 0;
         r = len1;
         current = 0;
     }


     return result;
    }
};