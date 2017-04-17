#include <cstdio>
#include <iostream>
#include <algorithm> 
using namespace std;
int tj[1005], king[1005];
int main() {
	int n;
	while(~scanf("%d",&n) && n) {
		for(int i=1; i<=n; ++i)
			scanf("%d", &tj[i]);
		for(int i=1; i<=n; ++i)
			scanf("%d", &king[i]);
		sort(tj+1,tj+n+1);
		sort(king+1,king+n+1);
		int p=1, q=1, ans;
		int c1=0, c2=0; //c2ÊÇÆ½¾Ö 
		while(p<=n && q<=n) {
			if(tj[p]>king[q]) {
				c1++;
				p++;
				q++;
			}
			else if(tj[p]<king[q]) {
				p++;
			}
			else if(tj[p]=king[q]) {
				p++;
				q++;
				c2++;
			}
		}
		ans = c1-(n-c1-c2);
		printf("%d\n",ans*200);
	}
	return 0;
}
