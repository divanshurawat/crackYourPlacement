class NumMatrix {
    vector<vector<int>> matSum;
    int r,c,sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        matSum = vector<vector<int>>(r+1,vector<int>(c+1));
        //Fill sum values
        for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j)
                matSum[i][j] = matSum[i-1][j] + matSum[i][j-1] - matSum[i-1][j-1] + matrix[i-1][j-1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        sum = matSum[row2+1][col2+1] - matSum[row1][col2+1] - matSum[row2+1][col1] + matSum[row1][col1];
        return sum;
    }
};