class Solution {
public:

    vector<vector<string> > ans;

    bool isPalindrome(string &s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(string s, vector<string> &op){
        if(s.size() == 0){
            ans.push_back(op);
            return;
        }

        for (int len = 1; len <= s.size(); ++len)
        {
            string chotiString = s.substr(0,len);
            if(isPalindrome(chotiString) == true){
                
                op.push_back(chotiString);
                
                solve(s.substr(len), op);

                op.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> op;
        solve(s,op);   

        return ans;
    }
};