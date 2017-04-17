#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int visit[10][10];
void DFS();
bool can_set(int x, int y);
int cnt, maxn, n;
int main() {
	while(~scanf("%d",&n))
	{
		char str[10];
		for(int i=1; i<=n; i++)
		{
			cin >> str;
			for(int j=1; j<=n; j++)
				visit[i][j] = (str[j-1] == 'X' ? 2 : 0);
		}
		DFS();
		printf("%d\n",maxn);
	}
	return 0;
}
void DFS() {
	if(cnt>maxn)
		maxn=cnt;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(visit[i][j]!=0 && can_set(i,j)==1) {
				visit[i][j]=1;
				cnt++;
				DFS();
				visit[i][j]=0;
				cnt--;
			}
}
bool can_set(int x, int y) {
	for(int i=x; i>=1; i--) {
		if(visit[i][y]==2) break;
		if(visit[i][y]==1) return 0;
	} 
	for(int i=x+1; i<=4; i++) {
		if(visit[i][y]==2) break;
		if(visit[i][y]==1) return 0;
	} 
	for(int j=y; j>=1; j--) {
		if(visit[x][j]==2) break;
		if(visit[x][j]==1) return 0;
	} 
	for(int j=y+1; j<=4; j++) {
		if(visit[x][j]==2) break;
		if(visit[x][j]==1) return 0;
	}
	return 1;
}
