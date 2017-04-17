/*����P365-----�����־�֢*/
#include <cstdio>
#define MX 505
#define INF 999999
using namespace std;

int d[MX][MX];
int min(int a, int b){
	return a>b ? b:a;
}
int max(int a, int b){
	return a<b ? b:a;
}
int main() {
	int C,S;
	printf("�ֱ���������ͱ�����\n");
	while(~scanf("%d%d",&C,&S))
	{
		for(int i=1; i<=C; i++)
			for(int j=1; j<=C; j++)
				d[i][j] = (i==j ? 0 : INF);
		printf("����߼���Ȩ��\n");
		for(int i=1; i<=S; i++) {
			int s,e,t;
			scanf("%d%d%d",&s,&e,&t);
			d[s][e] = d[e][s] = t;
		}
		for(int k=1; k<=C; k++)
			for(int i=1; i<=C; i++)
				for(int j=1; j<=C; j++)
					d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
		int start, end;
		printf("��㼰�յ㣺");
		scanf("%d%d", &start, &end);
		printf("������С�ǣ�%d\n", d[start][end]);
	}
}
