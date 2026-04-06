class Solution {
public:
    int maxArea(vector<int>& heights) {
        // find two bars with greatest area (smallest height of the two * distance)
            // to do this:
            // 1. find min of two target bars (containerHeight=min(heights[l],heights[r]))
            // 2. multiply min by distance 
                // distance = r-l
        int l = 0, r = heights.size()-1;
        int result = 0;

        while (l < r){
            int volume = (r-l) * min(heights[l], heights[r]); // 7*1 | 6*6 | 7*3 |  
            result = max(volume, result);
            if (heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }
        return result;
    }
};
