class Solution {
  public:
  
    void solve(int i , int j,int n, vector<int>& maze, vector<string>& ans, string& temp){
        if( i <0 || i >=n || j < 0 || j >=n || maze[i][j] == 0) return;
        
        if( i ==n-1 && j == n-1){
            ans.push_back(temp);
            return;
        }
        
        maze[i][j] = 0;
        temp.push_back('D');
        solve(i+1, j,n, maze, ans, temp);
        temp.pop_back();
        
        temp.push_back('L');
        solve(i, j-1,n, maze, ans, temp);
        temp.pop_back();
        
        temp.push_back('R');
        solve(i, j+1,n, maze, ans, temp);
        temp.pop_back();
        
        temp.push_back('U');
        solve(i-1, j,n, maze, ans, temp);
        temp.pop_back();
        
        maze[i][j] = 1;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string>ans;
        string temp ="";
        solve(0, 0,n, maze, ans, temp);
        return ans;
    }
};