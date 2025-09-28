class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int delrow[], int delcol[], int row, int col) {
        visited[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !visited[nrow][ncol]) {
                dfs(board, visited, delrow, delcol, nrow, ncol);
            }
        }
    }

    vector<vector<char>> solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, -1, 0, 1};
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && board[i][0] == 'O') {
                dfs(board, visited, delrow, delcol, i, 0);
            }
            if (!visited[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(board, visited, delrow, delcol, i, m - 1);
            }
        }
        for (int i = 0; i < m; i++) {
            if (!visited[0][i] && board[0][i] == 'O') {
                dfs(board, visited, delrow, delcol, 0, i);
            }
            if (!visited[n - 1][i] && board[n - 1][i] == 'O') {
                dfs(board, visited, delrow, delcol, n - 1, i);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 'O') 
                    board[i][j] = 'X'; 
            }
        }
        return board; 
    }
};