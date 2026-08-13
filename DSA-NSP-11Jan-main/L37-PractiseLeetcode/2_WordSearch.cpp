class Solution {
public:

    bool isValid(int i,int j,int n,int m){
        if(i < n and i >=0 and j<m and j>=0) return true;

        return false;
    }

    bool solve(vector<vector<char>>& board, string &word,int i,int j,
                int k,int n, int m, bool visited[][1000]){
        if(k == word.size()) return true;

        if(board[i][j] != word[k]){
            return false;
        }

        // Character match ho gaya
        if(board[i][j] == word[k] and !visited[i][j]){
            int x[] = { 0, 0, 1, -1};
            int y[] = {-1, 1, 0,  0};
            visited[i][j] = true;
            for (int l = 0; l < 4; ++l)
            {
                int new_i = i+x[l];
                int new_j = j+y[l];

                if(!isValid(new_i, new_j,n,m)) continue;

                bool chotaAns = solve(board,word, new_i, new_j,k+1, n, m, visited);
                if(chotaAns == true){
                    return true;
                }
            }

            visited[i][j] = false;
        }
        

        return false;
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













    