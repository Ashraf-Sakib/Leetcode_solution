class Solution {
public:
    bool visited[302][302];
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int n,m;
    bool isValid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    void dfs(int x,int y,vector<vector<char>>&grid){
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isValid(nx,ny)&&!visited[nx][ny]&&grid[nx][ny]=='1'){
                dfs(nx,ny,grid);
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int ans=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&& !visited[i][j]&&isValid(i,j)){
                    ans++;
                    dfs(i,j,grid);
                }
            }
         }
         return ans;
    }
};