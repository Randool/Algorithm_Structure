#include <iostream>
using namespace std;
void merge_sort(int *A, int x, int y, int *T) {
	if(y > x+1) {
		int m = x + (y-x)/2;	//�����м�ֵ 
		int p = x, q = m, i = x;
		merge_sort(A, x, m, T);	//�ݹ����, ����벿������ 
		merge_sort(A, m, y, T);	//�ݹ���⣬���Ұ벿������ 
		while(p < m || q < y) {
			if(q >= y || (p < m && A[p] <= A[q]))
				T[i++] = A[p++];	//���������ȡһ��С���� 
			else
				T[i++] = A[q++];	//���Ұ�����ȡһ��С���� 
		}
		for(i = x; i < y; i++)
			A[i] = T[i];	//�Ӹ������鸴�ƻ�ԭ���� 
	}
}
int main()
{
	int N, i, A[100], T[100];
	cin >> N;
	for(i=1; i<=N; i++)
		cin >> A[i];
	merge_sort(A, 1, N, T);
	for(i=1; i<=N; i++)
		cout << A[i] << " ";
	return 0;
}
