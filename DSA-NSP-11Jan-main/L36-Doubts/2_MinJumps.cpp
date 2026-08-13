#include <iostream>
#include <climits>
using namespace std;
int a[1005], dp[1005];

int solve(int *a, int n, int i){
	if(i == n-1){
		return 0;
	}

	if(dp[i]!=-1){
		return dp[i];
	}

	int ans = INT_MAX;
	for (int j = i+1; j <= i+a[i]; ++j)
	{
		if(j<n){
			int chotaAns = solve(a,n,j);
			if(chotaAns != INT_MAX){
				ans = min(ans, chotaAns+1);
			}
		}
	}

	return dp[i]=ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(dp,-1,sizeof dp);

		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}

		cout << solve(a,n,0) << endl;

	}

	return 0;
}
















