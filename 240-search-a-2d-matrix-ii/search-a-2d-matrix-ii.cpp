#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int row = 0;
        int col = cols - 1; // Start at top-right corner
        
        while (row < rows && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--; // Target must be in a smaller column
            } else {
                row++; // Target must be in a larger row
            }
        }
        
        return false;
    }
};