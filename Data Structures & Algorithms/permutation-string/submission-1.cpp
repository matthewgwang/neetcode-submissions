class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length()> s2.length()) {return false;}

        vector<int> s1_count(26,0);
        vector<int> window_count(26,0);
        int left = 0;

        for (int i = 0; i < s1.length(); i++) {
            s1_count[s1[i]-'a']++;
            window_count[s2[i]-'a']++;
        }

        if (s1_count == window_count) {
            return true;
        }

        for (int right = s1.length(); right<s2.length(); right++) {
            window_count[s2[right]-'a']++;
            window_count[s2[left]-'a']--;
            left++;
            if (window_count == s1_count) {
                return true;
            }
        }

        return false;
    }
};
