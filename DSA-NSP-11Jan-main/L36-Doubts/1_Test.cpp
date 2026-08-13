#include <iostream>
#include <cstring>
using namespace std;

int dp[200005];

// int solve(int n){
// 	if(n == 1){
// 		return 0;
// 	}
// 	if(n == 3){
// 		return 2;
// 	}

// 	if(n%2 == 0){
// 		return dp[n]= 1 + solve(n/2);
// 	}
// 	else{
// 		return dp[n]= min(1 + solve(n+1), 1 + solve(n-1));
// 	}
// }

int solve(int n){
	if(n == 1){
		return 0;
	}
	if(n == 3){
		return 2;
	}

	if(n%2 == 0){
		return dp[n]= 1 + solve(n/2);
	}
	else{
		if((n+1)%4 == 0){
			return 1 + solve(n+1);
		}
		return 1 + solve(n-1);
	}
}

int main(){

	int n;
	cin>>n;
	memset(dp,-1,sizeof dp);

	cout << solve(n) << endl; 

	return 0;
}
















