#include <iostream>
#include <cstring>
const int rec = 501;
using namespace std;
int r[rec][rec], sum[500], temp[501];
int maxn(int a[],int x) {	//求一维数组最大子串
	int best, i, j;
	memset(sum, 0, sizeof(a));
	best = sum[1] = a[1];
	for(i = 2; i <= x; i++)
		sum[i] = a[i] + sum[i-1];
	for(i = 1; i <= x; i++)
		for(j = i; j <= x; j++)
			best = max(best, sum[j] - sum[i]);
	return best;
}

int main()
{
	int x, y, i, j, max, Max;
	cin >> x >> y;
	bool all_neg = 1;
	memset(r, 0, sizeof(r));
	for(i = 1; i <= y; i++)
		for(j = 1; j <= x; j++) {
			cin >> r[j][i];
			if(r[j][i]>=0) all_neg = 0;
		}
	if(all_neg==1)
		cout << "0" << endl;
	else {
		Max = r[1][1];
		//将二维转位多个一维数组，取其中最大子串
		for(i = 1; i <= y; i++)
			for(j = i; j <= y; j++) {
				memset(temp, 0, sizeof(temp));
				for(int p = 1; p <= x; p++)
					for(int q = i; q<=j; q++)
						temp[p] = (q==i) ? r[p][q] : (temp[p] + r[p][q]);
				max = maxn(temp,x);
				/*for(int z=1; z<=x; z++)
					cout<<temp[z]<<" ";
				cout<<"     "<<max; system("pause");*/
				if(Max < max) Max = max;
			}
		cout << Max;
	}
	return 0;
}
