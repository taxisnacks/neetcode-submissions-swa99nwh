class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // lowest possible h is piles.size()
        // lowest possible k is 1
        // a pile with x bananas takes koko h=x/k hours (rounded up (std::ciel))
            // upper bound for k is largest pile

        // first, sort piles by size
        // binary search:
            // see if piles can be finished with middle value as k
            // if insufficient, move up
            // if sufficient, save value as potential solution and move down
 
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while(l<=r){
            int k = (l + r) / 2;

            int totalTime = 0;
            for (int pile : piles){
                totalTime += ceil(static_cast<double>(pile) / k);
            }
            if (totalTime <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
