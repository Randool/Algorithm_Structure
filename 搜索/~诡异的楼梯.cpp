#include <cstdio>
#define MAXN 21
using namespace std;
int m,n, x,y, dx,dy, ans;
char map[MAXN][MAXN];
void Show();
void DFS() {
	if(x==dx && y==dy)
		return;
	
}
int main() {
	while(~scanf("%d%d&*c",&m,&n)) {
		getchar();
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++)
				scanf("%c",&map[i][j]);
			getchar();
		}
		ans=0;
		DFS();
		printf("%d\n",ans);
	}
	return 0;
}

void Show() {
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
}
