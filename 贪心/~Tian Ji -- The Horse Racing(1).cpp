#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int tj[1005],king[1005];
int main() {
	int n;
	while(cin>>n){
		for(int i=1; i<=n; i++)
			scanf("%d",&tj[i]);
		for(int i=1; i<=n; i++)
			scanf("%d",&king[i]);
		sort(tj+1,tj+1+n);
		sort(king+1,king+1+n);
		int ans=0, tj_min=1, king_min=1, tj_max=n, king_max=n;
		while(tj_min<=tj_max && king_min<=king_max)
		{
			if(tj[tj_max] > king[king_max]) {
				ans += 200;
				king_max--;
				tj_max--;
			}
			else if(tj[tj_max] < king[king_max]) {
				ans -= 200;
				tj_min++;
				king_max--;
			}
			else {
				for(int t=tj_min; t<=n; t++) {
					if(tj[t] > king[king_min]) {
						ans += 200;
						king_min++;
					}
					else {
						tj_min = t;
						if(tj[tj_min] < king[king_max]) 
							ans -= 200;
						king_max--;
						tj_min++;
						break;
					}
				}
			}
		}
		cout << ans << endl ;
	}
	return 0;
}
