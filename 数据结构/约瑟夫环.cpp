#include <iostream>
using namespace std;
int main()
{
	int n, m, i, j, k, step = 0;
	cin >> n >> m >> k;
	int a[100];
	for(i = 1; i < n; i++)  
		a[i] = i + 1;		//��������ǰһλָ���һλ 
	a[n] = 1;  				//���һλָ����е�һλ 
	a[0] = m;  				//��ʼֵ
	for(i = 1;i < n; i++)			// n - 1�κ�����ʤ�� 
	{
		for(j = 1; j < k; j++)		//�� k - 1�� 
			step = a[step];
		//�� k �Σ����stepָ�����һλ�����˳��У�stepָ������λ 
		cout << i << ": " << a[step] << "\n";
		a[step] = a[a[step]];
	}
	cout << "winner: " << a[step];
	return 0;
}
