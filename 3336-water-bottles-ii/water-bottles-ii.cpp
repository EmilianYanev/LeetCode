class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int result = 0;
        int empty = 0;
        while (numBottles) {
            result += numBottles;
            empty += numBottles;
            numBottles = 0;

            if (empty >= numExchange) {
                empty -= numExchange;
                numExchange++;
                numBottles++;
            }
        }

        return result;
    }
};