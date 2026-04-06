class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window with a hash map, maybe? keeps track of length and if a character has been seen in a given substring
        int l = 0;
        unordered_set<char> seen;
        int result = 0;

        for (int r = 0; r < s.size(); r++){
            while (seen.find(s[r]) != seen.end()){    // block executes if s[r] exists in our hash set
                seen.erase(s[l]);                     // removes s[l] and iterates l to prevent dupe 
                l++;
            } 
            seen.insert(s[r]);                      
            result = max(result, r-l+1);              // calculates substring lenth based on distance between window pointers
        }
        return result;
    }
};
