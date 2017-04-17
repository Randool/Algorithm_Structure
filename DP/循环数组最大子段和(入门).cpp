#include <iostream>
#include <cstring>
using namespace std;
const int n = 50001;
long long circle[n];
//��ѭ�����������Ӷκ͡����⣬���԰ѻ�������λ�öϿ�
//Ȼ��������Ž� = max(��ͨ������Ӷκͣ��ܺ� �C��ͨ�� "��С�Ӷκ͡�)
long long find_min(long long a[], long long x) {
	long long ans = 0;
	long long min_sum = a[1];
	for(int i = 1; i <= x; i++)
	{
		if(ans > 0)
			ans = a[i];
		else
			ans += a[i];
		min_sum = min(ans, min_sum);
	}
	if(min_sum>0) min_sum=0;
	return min_sum;
}

long long find_max(long long a[], long long x) {
	long long ans = 0;
	long long Max_sum = a[1];
	for(int i = 1; i <= x; i++)
	{
		if(ans < 0)
			ans = a[i];
		else
			ans += a[i];
		Max_sum = max(ans, Max_sum);
	}
	return Max_sum;
}

int main() {
	long long N, i, j;
	long long SUM, sum;
	while(cin>>N)
	{
		memset(circle, 0, sizeof(circle));
		SUM = 0;
		for(i=1; i<=N; i++)
		{
			cin >> circle[i];
			SUM += circle[i];
		}
		long long ans = max(SUM - find_min(circle, N), find_max(circle, N));
		cout << ans << endl;
	}
	return 0;
}
//6 -2 11 -4 13 -5 -2
