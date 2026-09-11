class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>seen_chars;
        int longest = 0;
        int length = s.length();
        int left = 0;

        for (int right = 0; right < length; right++) {
            
            while (seen_chars.contains(s[right])) {
                seen_chars.erase(s[left]);
                left++;
            }
            
            seen_chars.insert(s[right]);
            longest = max(longest, right-left+1);
            
        }
        return longest;


    }
};
