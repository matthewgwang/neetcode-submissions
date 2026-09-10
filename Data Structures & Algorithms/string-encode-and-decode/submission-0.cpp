class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        for (const string& s: strs) {
            encoded_string += to_string(s.length()) + "#" + s;
        }

        return encoded_string;

    }

    vector<string> decode(string s) {
        vector<string>decoded_strings;

        int i = 0;

        while (i < s.length()) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j-i));

            decoded_strings.push_back(s.substr(j+1, length));

            i = j + length+ 1;
        }
        return decoded_strings;

    }
};
