#include <cstdio>
using namespace std;

int Go[201], ans, N, A, B, t;
bool can;

void dfs(int num) {
	if(num<1 || num>N) return;
	if(num==B) {
		can=1;
		return;
	}
	t++;
	dfs(num + Go[t]);
	t--;
	dfs(num - Go[t]);
}

int main() {
	while(~scanf("%d%d%d", &N, &A, &B)) {
		if(N==0) break;
		for(int i=1; i<=N; i++)
			scanf("%d",Go[i]);
		t = 0;
		ans = 0;
		can = 0;
		dfs(A);
		if(can==1)
			printf("%d\n",ans);
		else
			printf("-1\n");
	}
	return 0;
}
