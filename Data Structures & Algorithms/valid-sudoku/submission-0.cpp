class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // complete in a single pass by checking row, column, and square validity at each number
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++){
            for (int c = 0; c < 9; c++){
                if (board[r][c] == '.') continue; // If empty space, move on

                pair<int, int> squareKey = {r / 3, c / 3}; // Isolate 3x3 squares

                if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) 
                || squares[squareKey].count(board[r][c])){
                    return false; // Check row, column, and square validity of a space at once
                } 

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);
            }
        }
        return true;
    }
};
