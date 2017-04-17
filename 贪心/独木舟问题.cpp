#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int mass[10005];
int main() {
	int N,V;
	while(~scanf("%d%d",&N,&V)) {
		for(int i=1; i<=N; i++)
			scanf("%d",&mass[i]);
		sort(mass+1, mass+1+N, less<int>());
		int p=1, q=N, ans=0;
		while(p<=q) {
			if(mass[p]+mass[q]<=V) {
				ans++;
				p++;
				q--;
			} else {
				ans++;
				q--;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
