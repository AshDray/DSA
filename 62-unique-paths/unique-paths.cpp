class Solution {
public:
int f(int r , int c , int m , int n, vector<vector<int>>& ways){
    if(ways[r][c]!= -1) return ways[r][c];
     if(r==m-1 || c==n-1)return 1;
    return ways[r][c] = f(r+1 , c , m , n , ways)+f(r , c+1 , m , n , ways);

}
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways (m , vector<int>(n,-1));
        return f(0 ,0 , m ,n,ways);
    }
};