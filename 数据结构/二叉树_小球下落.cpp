#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 20;
int s[1<<maxn];
int main() {
	int D, I;
	while(scanf("%d%d", &D, &I) == 2) {
		memset(s, 0, sizeof(s));//����
		int k, n = (1<<D)-1;	//n�����ڵ�ı��
		for(int i = 0; i < I; i++) {
			k = 1;
			for(;;) {
				s[k] = !s[k];	//�ı俪��״̬ 
				k = (s[k] ? k*2 : k*2+1);	//���ݿ���״̬ѡ���� 
				//printf("%d\n", k);
				if(k > n) break;
			}
		}
		printf("%d\n", k/2);
	}
	return 0;
}
