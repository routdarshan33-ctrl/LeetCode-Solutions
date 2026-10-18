class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> zero_row;
        vector<int> zero_col;
        for(int i = 0; i < row; i ++){
            for(int j = 0; j < col; j ++){
                if(matrix[i][j] == 0){
                    zero_row.push_back(i);
                    zero_col.push_back(j);
                }
            }
        }
        for(int i = 0; i < zero_row.size(); i ++){
            int p = zero_row[i];
            int q = zero_col[i];
            for(int j = 0; j < col; j ++){
                matrix[p][j] = 0;
            }
            for(int j = 0; j < row; j ++){
                matrix[j][q] = 0;
            }
        }
    }
};