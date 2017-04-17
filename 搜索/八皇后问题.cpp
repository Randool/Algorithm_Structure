/*�˻ʺ�����*/
#include <cmath>
#include <cstdio>
#define MAXN 10
using namespace std;

int ans=0, Q=8/*�ʺ���*/, chess[MAXN]/*������¼ÿһ�зŵ�λ��*/;

bool place(int t) {
	for(int i=1; i<t; i++)
		if(abs(chess[i]-chess[t])==abs(i-t) || chess[i]==chess[t])
			return 0;
	return 1;
}

void DFS(int i) {
	if(i>Q) { //��Ϊ���� i��ﵽ 9��������ֹ������ i>Q 
		ans++;
		for(int j=1; j<=Q; j++)
			printf("%d ",chess[j]);
		printf("\n");
	}
	else {
		for(int j=1; j<=Q; j++) {
			chess[i]=j;
			if(place(i)) //������Էţ��Ǿ͵���һ�� 
				DFS(i+1);
		}
	}
}
int main() {
	DFS(1);
	printf("%d",ans);
	return 0;
}
