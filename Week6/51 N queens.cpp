#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<int> columns(n, 0);  // Track if a column is occupied
        vector<int> diag1(2 * n - 1, 0);  // Major diagonals (row - col), 左上到右下
        vector<int> diag2(2 * n - 1, 0);  // Minor diagonals (row + col), 右上到左下
        solveBacktracking(0, columns, diag1, diag2,n,board, result);   
        return result;
    }

    private:
    void solveBacktracking(int row, vector<int>& columns,vector<int>& diag1, \
            vector<int>& diag2, int n, vector<string>& board, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col + (n - 1);  // Major diagonal index
            int d2 = row + col;            // Minor diagonal index

            // Check if the column or diagonals are already occupied
            if (columns[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            // Place queen
            columns[col] = 1;
            diag1[d1] = 1;
            diag2[d2] = 1;
            board[row][col] = 'Q';

            // Recur to place queen in next row
            solveBacktracking(row+1, columns, diag1, diag2,n,board,result);

            // Backtrack
            columns[col] = 0;
            diag1[d1] = 0;
            diag2[d2] = 0;
            board[row][col] = '.';
        }
    }
};


int main() {
    int n = 4;
    
    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(n);

    for (int i=0; i<result.size(); i++) {
        for (const auto& j : result[i]) {
            cout << j << endl;
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}