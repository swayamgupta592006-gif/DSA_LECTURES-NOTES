#include <iostream>
using namespace std;

int topDown(string &s1, string &s2,int n,int m,int dp[100][100]){
	if(n == 0){
		return m;
	}
	if(m == 0){
		return n;
	}

	if( dp[n][m]!= -1){
		return  dp[n][m];
	}

	if(s1[n-1] == s2[m-1]){
		return dp[n][m]=topDown(s1,s2,n-1,m-1,dp);
	}
	else{
		// Insertion
		int op1 = topDown(s1,s2,n,m-1,dp);
		// Replace
		int op2 = topDown(s1,s2,n-1,m-1,dp);
		// Deletion
		int op3 = topDown(s1,s2,n-1,m,dp);

		return  dp[n][m]= min(op1,min(op2,op3)) + 1;
	}
}

int bottomUp(string &s1, string &s2){
	int dp[100][100];
	int n = s1.size(), m = s2.size();
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m ; ++j)
		{
			if(i == 0) dp[i][j] = j;
			else if(j == 0) dp[i][j] = i;
			else{
				if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
				else{
					// Insertion
					int op1 = dp[i][j-1];
					// Replace
					int op2 = dp[i-1][j-1];
					// Deletion
					int op3 = dp[i-1][j];
					dp[i][j]= min(op1,min(op2,op3)) + 1;
				}
			}
		}
	}

	return dp[n][m];
}


int main(){

	string s1 = "sunday", s2 = "saturday";
	int dp[100][100];
	memset(dp,-1,sizeof dp);
	cout << topDown(s1,s2,s1.size(),s2.size(),dp)<<endl;
	cout << bottomUp(s1,s2)<<endl;

	return 0;
}
















