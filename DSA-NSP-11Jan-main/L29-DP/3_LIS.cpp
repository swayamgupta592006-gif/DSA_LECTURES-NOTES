#include <iostream>
using namespace std;

int main(){

	int a[] = {10, 9, 3, 5, 4, 11, 7, 8};
	int n = sizeof(a)/sizeof(int);

	int dp[100];
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = i-1; j >=0 ; --j)
		{
			if(a[j] < a[i]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}

	int lis_len = 1;

	for (int i = 0; i < n; ++i)
	{
		lis_len = max(lis_len, dp[i]);
	}
	cout << "LIS len: "<<lis_len<<endl;


	return 0;
}
















