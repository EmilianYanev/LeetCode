class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int actions = 0;
        
        int head = 0;
        int tail = size - 1;

        int a = 0;
        int b = 0;

        int currentArea = -1;
        int biggestArea = -1;
        while(actions != size) {
            a = tail - head;

            if(height[head] < height[tail]) {
                b = height[head];
                currentArea = a * b;
                if(currentArea > biggestArea) {
                    biggestArea = currentArea;
                }                
                head++;
                actions++;

            } else {
                b = height[tail];
                currentArea = a * b;
                      if(currentArea > biggestArea) {
                    biggestArea = currentArea;
                }                
                tail--;
                actions++;
            }
            currentArea = 0;
        }
        return biggestArea;
    }
};