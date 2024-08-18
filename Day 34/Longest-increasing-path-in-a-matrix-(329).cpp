class Solution {
public:
    // lip: longest increasing path
    int lip(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        if (memo[i][j] >= 0) return memo[i][j];
        
        int currentmax = 1;

        // down neighbor (i+1, j)
        if (i + 1 < n && matrix[i + 1][j] > matrix[i][j]) {
            currentmax = max(currentmax, 1 + lip(matrix, i + 1, j, memo, n, m));
        }
        // right neighbor (i, j+1)
        if (j + 1 < m && matrix[i][j + 1] > matrix[i][j]) {
            currentmax = max(currentmax, 1 + lip(matrix, i, j + 1, memo, n, m));
        }
        // up neighbor (i-1, j)
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            currentmax = max(currentmax, 1 + lip(matrix, i - 1, j, memo, n, m));
        }
        // left neighbor (i, j-1)
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            currentmax = max(currentmax, 1 + lip(matrix, i, j - 1, memo, n, m));
        }

        return memo[i][j] = currentmax;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));  // Initialize memo with -1
        int Max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Max = max(Max, lip(matrix, i, j, memo, n, m));
            }
        }
        return Max;
    }
};
