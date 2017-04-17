#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Move{
	int begin, end;
} move[205];

cmp(const Move &a, const Move &b) {
	if(a.begin==b.begin) return a.end < b.end;
	else return a.begin < b.begin;
}

int main() {
	int T, N;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<+N;i++)
			scanf("%d%d", &move[i].begin, &move[i].end);
		sort(move+1,move+1+N,cmp);
		
		
	}
	
	return 0;
}
