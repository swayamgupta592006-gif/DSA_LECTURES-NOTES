#include <iostream>
using namespace std;

int main(){

	int a[] = {10, 9, 3, 5, 4, 11, 7, 8};
	int n = sizeof(a)/sizeof(int);

	vector<int> v;
	v.push_back(a[0]);
	
	for(int i = 1 ; i < n ; i++){
		if(v.back() < a[i]){
			v.push_back(a[i]);
		}
		else{
			int indx = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
			v[indx] = a[i];
		}	
	}

	cout << "LIS : "<<v.size() << endl;

	// int a[] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8};
	// int n = sizeof(a)/sizeof(int);

	// // Sorted array mei hi lag skta hai upper_bound and lower_bound
	// int key = 5;

	// int i = lower_bound(a, a + n, 5) - a;
	// int ui = upper_bound(a, a + n, 5) - a;

	// cout << i << endl;
	// cout << ui << endl;

	return 0;
}
















