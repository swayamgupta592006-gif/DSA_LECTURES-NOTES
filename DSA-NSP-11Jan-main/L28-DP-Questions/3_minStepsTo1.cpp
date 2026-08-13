#include <iostream>
using namespace std;

int topDown(int n,int *dp){
	if(n == 1) {
		return 0;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

	if(n%3 == 0){
		op1 = topDown(n/3, dp);
	}
	if(n%2 == 0){
		op2 = topDown(n/2, dp);
	}
	op3 = topDown(n-1,dp);

	return dp[n] = min(op1,min(op2,op3)) + 1;
}

int bottomUp(int n){
	int dp[1000];

	dp[1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
		if(i%3 == 0){
			op1 = dp[i/3];
		}
		if(i%2 == 0){
			op2 = dp[i/2];
		}
		op3 = dp[i-1];

		dp[i] = min(op1, min(op2,op3)) + 1;
	}

	return dp[n];
}

int main(){
	
	int dp[1000];
	memset(dp, -1, sizeof(dp)); // cstring header file for this

	cout << topDown(10, dp)<<endl;
	cout << bottomUp(10)<<endl;

	return 0;
}
















