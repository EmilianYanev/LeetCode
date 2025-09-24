class Solution {
public:
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) {
            return "0";
        }
        if (numerator == denominator) {
            return "1";
        }
        string s;
        if ((numerator < 0 && denominator > 0) ||
            (numerator > 0 && denominator < 0)) {
            s.push_back('-');
        }

        long long n = llabs(numerator);
        long long d = llabs(denominator);

        s += to_string(n / d);
        long long rem = n % d;
        if (rem == 0)
            return s;

        s.push_back('.');

        unordered_map<long long, int> pos;
        while (rem != 0) {
            if (pos.count(rem)) {

                s.insert(s.begin() + pos[rem], '(');
                s.push_back(')');
                break;
            }
            pos[rem] = s.size();
            rem *= 10;
            s.push_back(char('0' + (rem / d)));
            rem %= d;
        }
        return s;
    }
};