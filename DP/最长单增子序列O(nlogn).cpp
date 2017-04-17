/*logn������ʹ���˶��ֲ���*/
#include <cstdio>
#include <algorithm>
#define inf 0x3f3f3f3f
const int MAXN = 50005;
using namespace std;

int s[MAXN];
int new_s[MAXN];
int main() {
	int N, ans=1;
	scanf("%d",&N);
	fill(new_s,new_s+N+5,inf); //STL�е� fill���������� memset
	for(int i=0; i<N; i++) scanf("%d",&s[i]);
	for(int i=0; i<N; i++) {
		//upper_bound��������һ���ǵݼ�����[first, last)�е�һ������val��λ��
		int pos = upper_bound(new_s, new_s+N+1, s[i]) - new_s;
		new_s[pos] = s[i];
		if(pos > ans) ans = pos;
	}
//	for(int i=0; i<N; i++)
//		printf("%d ",new_s[i]);
	printf("\n%d\n", ans+1);
	return 0;
}
