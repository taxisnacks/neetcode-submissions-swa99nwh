class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for (char ch : s){
            sMap[ch]++;
        }
        for (char ch : t){
            tMap[ch]++;
        }
        if (sMap == tMap){
            return true;
        }
        return false;
    }
};
