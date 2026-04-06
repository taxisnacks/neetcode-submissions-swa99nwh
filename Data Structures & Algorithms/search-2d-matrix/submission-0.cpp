class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first instinct is nested binary searches: one for array selection, one within each array
            // i.e, find the middle array, then find its middle value
                // if this value is equal to target, return true
                // if this value is greater than target, set right bounds to this value
                // else if this value is less than target, set left bounds to this value
        
        // the trouble: how do we know when to switch between arrays?
            // take example 1: we can find the middle array via the size of vector by using outerMid = outerLow + (outerHigh - outerLow)/2
            // that gives us our array targeting, but we then need separate pointers for searching within an array. 
            // problem suggests o(log(m*n)) complexity. bsearch averages o(log n), so i think this is actually the intended solution
        
        // Initial values
        int outerLow = 0;
        int outerHigh = matrix.size()-1;
        int innerLow = 0;
        int innerHigh; // needs to be defined within loop, as our matrix target changes, but the searchMatrix does not
        int innerMid;

        while (outerLow <= outerHigh){
            int outerMid = outerLow + (outerHigh - outerLow)/2;
            innerHigh = matrix[outerMid].size()-1;
            innerLow = 0;
            while (innerLow <= innerHigh){
                innerMid = innerLow + (innerHigh - innerLow)/2;
                if (matrix[outerMid][innerMid] == target){
                    return true;
                } else if (matrix[outerMid][innerMid] > target) {
                    innerHigh = innerMid-1;
                } else {
                    innerLow = innerMid+1;
                }
            }
            if (matrix[outerMid][innerMid] > target){
                outerHigh = outerMid-1;
            } else {
                outerLow = outerMid+1;
            }
            
        }
        return false;
    }
};
