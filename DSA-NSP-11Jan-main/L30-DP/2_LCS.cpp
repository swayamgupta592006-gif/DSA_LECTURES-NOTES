#include <iostream>
using namespace std;

int lcs(string &s1, string &s2,int n,int m, int dp[][100]){
	if(n == 0 or m == 0){
		return 0;
	}	

	if(dp[n][m] != -1){
		return dp[n][m];
	}

	if(s1[n-1] == s2[m-1]){
		return dp[n][m]= 1 + lcs(s1,s2,n-1,m-1, dp);
	}
	else{
		return dp[n][m]=max(
			lcs(s1,s2,n,m-1, dp),
			lcs(s1,s2,n-1,m, dp)
		);
	}
}

int bottomUp(string &s1, string &s2){
	int dp[100][100] = {};
	int m = s1.size(), n = s2.size();

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n ; ++j)
		{
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n ; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	// Find the LCS
	int i = m, j = n;
	string ans = "";

	while (i>0 or j > 0){
		if(s1[i-1] == s2[j-1]){
			ans.push_back(s1[i-1]);
			i--;
			j--;
		}
		else{
			if(dp[i][j] == dp[i-1][j]) i--;
			else j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << "LCS : "<<ans <<endl;
	return dp[m][n];
}

int main(){
	string s1 = "abcde";
	string s2 = "adce";

	int dp[100][100];
	memset(dp, -1, sizeof dp);
	cout << lcs(s1,s2,s1.size(),s2.size(), dp) << endl;
	cout << bottomUp(s1,s2) << endl;

	return 0;
}
















