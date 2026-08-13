#include <iostream>
using namespace std;

int topDown(int n,int *dp){
	if(n <= 1){
		return n;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	int ans = topDown(n-1, dp) + topDown(n-2, dp);
	return dp[n] = ans;
}

int bottomUp(int n){
	int dp[1000];
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int main(){

	int n = 10;
	int dp[1000];
	memset(dp, -1, sizeof(dp)); // cstring header file for this
	cout << topDown(n,dp) << endl;
	cout << bottomUp(n) << endl;

	return 0;
}

















	