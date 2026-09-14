class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>count;

        int max_freq = 0;
        int length = s.length();
        int longest_window = 0;
        int left = 0;

        for (int right = 0; right<length; right++) {
            count[s[right]] += 1;
            max_freq = max(max_freq, count[s[right]]);

            while ((right - left + 1) - max_freq > k) {
                count[s[left]]--;
                left++;
            }


            longest_window = max(longest_window, (right-left+1));
            


        }

        return longest_window;
    }
};
