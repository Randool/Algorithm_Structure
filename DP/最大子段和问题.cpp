#include <iostream>
#include <cstring>
using namespace std;
const int N = 50005;
long long dp[N];
int a[N];
int main() {
	int n;
	while(cin >> n) {
		long long maxn=-999999999;
		int i,j;
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		dp[0] = a[0] = 0;
		for(i=1; i<=n; i++) {
			cin >> a[i];
			dp[i] = max(dp[i-1] + a[i], a[i]);
			if(dp[i] > maxn) maxn = dp[i];
		}
		cout << maxn << endl;
	}
	return 0;
}
