#include <iostream>
using namespace std;

int topDown(int amount, int *deno,int n,int *dp){
	if(amount == 0){
		return 0;
	}

	if(dp[amount] != -1){
		return dp[amount];
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if(amount>=deno[i]){
			int ca = topDown(amount-deno[i],deno,n, dp);
			if(ca != INT_MAX){
				ans = min(ans, ca+1);
			}
		}
	}
	return dp[amount] = ans;
}

int bottomUp(int amount,int *deno,int n){
	// int dp[10000];
	// for (int i = 0; i <= amount; ++i)
	// {
	// 	dp[i] = INT_MAX;
	// }
	vector<int> dp(amount+1, INT_MAX);
	
	dp[0] = 0;
	for (int i = 1; i <= amount; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(i >= deno[j]){
				int chotiAmount = i-deno[j];
				if(dp[chotiAmount] != INT_MAX){
					dp[i] = min(dp[i], dp[chotiAmount]+1);
				}
			}
		}
	}

	return dp[amount];
}

int main(){

	int deno[] = {1,7,10};
	int n = sizeof(deno)/sizeof(int);

	int dp[1000];
	memset(dp, -1, sizeof(dp));

	cout << topDown(15, deno, n, dp) << endl;
	cout << bottomUp(15, deno, n) << endl;

	return 0;
}
















