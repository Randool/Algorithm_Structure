//n������ʯ��д�ϷǸ���
//�ȰѸ�����ʯ�Ӵ�С���У�Ȼ��ش�q������
//�Ƿ��д���ʯ��д��x������ǣ��ش��ĸ�λ����д��x 
#include<iostream>
#include<cstdio>
#include<algorithm>		//����sort������Ҫͷ�ļ�algorithm���㷨�� 
using namespace std;
const int maxn = 10000;

int main()
{
	int n, q, x, a[maxn], kase=0;
	while(scanf("%d%d", &n, &q) == 2 && n)	//&& n ��Ϊ�˷�ֹ n Ϊ 0 
	{
		printf("CASE# %d:\n", ++kase);
		for(int i = 0 ; i < n ; i++)
			scanf("%d", &a[i]);
		
		sort(a, a+n);		//���� 
		
		while(q--)
		{
			scanf("%d", &x);
			int p = lower_bound(a,a+n,x) - a;	//lower_bound �������ǲ��ҡ����ڻ���� x �ĵ�һ��λ�á� 
			
			if(a[p] == x)
				printf("%d found at %d\n", x, p+1);
			else
				printf("%d not found\n", x);
		}
	}
	return 0;
}
