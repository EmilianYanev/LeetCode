class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = 0;
        int surplus = 0;
        while(numBottles) {
            result += numBottles;// - numBottles % numExchange;
            surplus += numBottles % numExchange;
            numBottles = numBottles / numExchange + (surplus / numExchange);
            if(surplus / numExchange == 1) {
                surplus = 0;
            }
        }

        return result;
    }
};