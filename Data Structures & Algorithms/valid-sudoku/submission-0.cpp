class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>rows[9];
        unordered_set<char>cols[9];
        unordered_set<char>squares[9];

        for (int i = 0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                char val = board[i][j];

                if (val == '.') {continue;}
                if (rows[i].find(val) == rows[i].end()) {
                    rows[i].insert(val);
                } else {
                    return false;
                }

                if (cols[j].find(val) == cols[j].end()) {
                    cols[j].insert(val);
                } else {
                    return false;
                }

                int k = (i / 3) * 3 + (j / 3);
                if (squares[k].find(val) == squares[k].end()) {
                    squares[k].insert(val);
                } else {
                    return false;
                }
            }
        }        
        return true;
    }
};
