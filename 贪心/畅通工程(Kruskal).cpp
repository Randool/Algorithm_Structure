//http://acm.hdu.edu.cn/showproblem.php pid=1863
#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 105
using namespace std;

int n, m, a, b, c;
int p[MAXN]; //���鼯
bool r[MAXN]; // �����
struct Node {
	int a, b, value;
} node[1005];

bool cmp(const Node a, const Node b) {
	return a.value < b.value;
}

int find(int n) {
	return p[n]==n ? n : find(p[n]);
}

int Kruskal() {
	int ans = 0;
	sort(node, node+n, cmp);
	for(int i=0; i<n; i++)
	{
		//r[node[i].a] = r[node[i].b] = 1;
		int e = node[i].value;
		int a = find(node[i].a);
		int b = find(node[i].b);
		if(a != b) {
			ans += e;
			p[a] = b;
		}
	}
	int flag = 1, r = find(1), s;
	for(int i=2; i<=m; i++) //����Ƿ����еĵ㶼�ڼ����� 
	{
		s = find(i);
		if(r != s) flag = 0;
	}
	
	if(flag)
		printf("%d\n", ans);
	else
		printf("?\n");
}

int main() {
	while(~scanf("%d",&n), n) { //��·��
		scanf("%d", &m); //��ׯ��
		
		for(int i=0; i<=m; i++) {
			p[i] = i;
			r[i] = 0;
		}
		
		for(int i=0; i<n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			node[i].a = a;
			node[i].b = b;
			node[i].value = c;
		}
		Kruskal();
	}
	return 0;
}
/*
5 5
1 2 3
2 1 4
3 4 1
4 3 2
4 5 4
*/
