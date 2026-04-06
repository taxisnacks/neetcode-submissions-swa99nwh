class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        unordered_map<int,int> seen;
        for (i = 0; i < nums.size(); i++){
            int difference = target - nums[i];
            if (seen.count(difference)){
                return {seen[difference],i};
            }
            seen[nums[i]] = i;
        }
    return {};
    }
};
