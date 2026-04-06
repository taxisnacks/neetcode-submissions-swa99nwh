class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int, int> count;
        int result = 0;

        for (int num : nums)
        {
            if(!count[num])
            {
                count[num] = count[num-1] + count[num+1] +1;
                count[num - count[num-1]] = count[num];
                count[num + count[num+1]] = count[num];
                result = max(result, count[num]);
            }
        }
        return result;
    }
};
