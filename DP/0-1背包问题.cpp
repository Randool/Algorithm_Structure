#include <bits/stdc++.h> 
using namespace std;

int dp[2][10005];

struct Item {
	int wi;
	int pi;
} item[105];

void Show(int W, int index) {
	for(int i=1; i<=W; i++)
		cout << setw(4) << dp[index][i];
	printf("\n");
}

int main() {
	int N, W, i, j, t;
	while(scanf("%d%d", &N, &W)==2) {

		memset(dp,0,sizeof(dp));

		for(i=1; i<=N; i++)
			scanf("%d%d", &item[i].wi, &item[i].pi);

		int x=0,y=1; //滚动数组

		for(i=1; i<=N; i++) {
			for(j=1; j<=W; j++) {
				if(j < item[i].wi)
					dp[y][j] = dp[x][j];
				else
					dp[y][j] = max(dp[x][j-item[i].wi] + item[i].pi , dp[x][j]);
			}
			Show(W,y);
			swap(x,y);
		}
		printf("%d\n", dp[x][W]);
	}
	return 0;
}
/*输入示例
3 6
2 5
3 8
4 9

输出示例
14
*/
