class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = l+1;
        vector<int> result;
        // start with left pointer = index 0. and right pointer = left + 1.
        while (r < numbers.size()){
            if (numbers[l]+numbers[r] == target){
                    result.push_back(l+1);
                    result.push_back(r+1);
                    return result;
            } else if (r == numbers.size()-1){
                l++;
                r = l+1;
            } else {
                r++;
            }
        }
    }
};
