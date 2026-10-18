class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> zero_row(row, 0);
        vector<int> zero_col(col, 0);
        for(int i = 0; i < row; i ++){
            for(int j = 0; j < col; j ++){
                if(matrix[i][j] == 0){
                    zero_row[i] = 1;
                    zero_col[j] = 1;
                }
            }
        }
        for(int i = 0; i < row; i ++){
            for(int j = 0; j < col; j ++){
                if(zero_row[i] == 1 || zero_col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};