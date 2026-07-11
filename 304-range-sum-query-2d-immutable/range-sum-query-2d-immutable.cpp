class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
        : M(matrix.size()),
          N(matrix[0].size()),
          arr_(M + 1, N + 1)
    {
        for (int i = static_cast<int>(M) - 1; i >= 0; --i) {
            for (int j = static_cast<int>(N) - 1; j >= 0; --j) {
                arr_(i, j) = matrix[i][j]
                           + arr_(i, j + 1)
                           + arr_(i + 1, j)
                           - arr_(i + 1, j + 1);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return arr_(row1, col1)
             - arr_(row1, col2 + 1)
             - arr_(row2 + 1, col1)
             + arr_(row2 + 1, col2 + 1);
    }

private:
    struct FlatArray {
        FlatArray(size_t rows, size_t cols)
            : rows_(rows), cols_(cols), data_(rows * cols, 0) {}

        int& operator()(size_t r, size_t c) {
            return data_[r * cols_ + c];
        }

        const int& operator()(size_t r, size_t c) const {
            return data_[r * cols_ + c];
        }

        size_t rows_;
        size_t cols_;
        vector<int> data_;
    };

    size_t M;
    size_t N;
    FlatArray arr_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */