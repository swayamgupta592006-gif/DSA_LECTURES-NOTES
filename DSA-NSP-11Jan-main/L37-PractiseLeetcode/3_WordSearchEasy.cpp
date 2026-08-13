class Solution {
public:

    bool isValid(int i,int j,int n,int m){
        if(i < n and i >=0 and j<m and j>=0) return true;

        return false;
    }

    bool solve(vector<vector<char>>& board, string &word,int i,int j,
                int k,int n, int m, bool visited[][1000]){
        if(k == word.size()) return true;

        if(!isValid(i,j,n,m) or board[i][j] != word[k] or visited[i][j]){
            return false;
        }

        visited[i][j] = true;
        bool up = solve(board,word,i-1,j,k+1,n,m,visited);
        bool down = solve(board,word,i+1,j,k+1,n,m,visited);
        bool left = solve(board,word,i,j-1,k+1,n,m,visited);
        bool right = solve(board,word,i,j+1,k+1,n,m,visited);
        visited[i][j] = false;


        return up or down or left or right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool visited[1000][1000] = {0};
        int n = board.size();
        int m = board[0].size();
        if(n == 1 and m == 1 and word.size() == 1){
            return board[0][0] == word[0];
        }
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m;j++){
                if(word[0] == board[i][j]){
                    bool ans = solve(board, word, i,j,0,n,m,visited);
                    if(ans == true) return true;
                }
            }
        }
        return false;
    }
};













    