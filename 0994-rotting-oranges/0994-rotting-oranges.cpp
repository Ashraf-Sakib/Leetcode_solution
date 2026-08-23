class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int n,m;
    
    bool isValid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        
        if(fresh==0) return 0;
        
        int minutes=0;
        while(!q.empty()){
            int sz=q.size();
            bool rottedThisRound=false;
            
            for(int k=0;k<sz;k++){
                auto [x,y]=q.front(); q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i], ny=y+dy[i];
                    if(isValid(nx,ny) && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                        rottedThisRound=true;
                    }
                }
            }
            if(rottedThisRound) minutes++;
        }
        
        return fresh==0 ? minutes : -1;
    }
};