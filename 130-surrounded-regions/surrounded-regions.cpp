class Solution {
public:
void dfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis,int dx[],int dy[]){
    vis[i][j]=1;
    int n=board.size();
    int m=board[0].size();
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<n&&y>=0&& y<m && !vis[x][y]&& board[x][y]=='O')dfs(x,y,board,vis,dx,dy);
    }
}
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int dx[4]={0,0,1,-1};
        int dy[4]={-1,1,0,0};
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'&& !vis[i][0])dfs(i,0,board,vis,dx,dy);
            if(board[i][n-1]=='O'&& !vis[i][n-1])dfs(i,n-1,board,vis,dx,dy);
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'&& !vis[0][i])dfs(0,i,board,vis,dx,dy);
            if(board[m-1][i]=='O'&& !vis[m-1][i])dfs(m-1,i,board,vis,dx,dy);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                                if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';

            }
        }
        
    }
};