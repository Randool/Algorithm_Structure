#include <cstdio>
#include <cstring>
#include <iostream>
const int maxn = 10;
using namespace std;

int n, k;
int cnt, num;	//ans�����մ𰸣�num���ѷŵ�������Ŀ 
int placed[maxn]; // ��¼�����Ƿ�Ź����� 
char board[maxn][maxn];

void DFS(int i) {
	if(k==num) { //��ֹ����1����û�ﵽ��Ե�ͷ���������  
		cnt++;
		return;
	}
	if(i>=n) //��ֹ����2��������Ե 
		return;
	for(int j=0; j<n; j++) {
		if(placed[j]==0 && board[i][j]=='#') {
			// ���ѡ���� j ������ 
			placed[j]=1;
			num++;
			DFS(i+1);
			// ���ѡ���� j ��������
			placed[j]=0;
			num--; 
		}
	}
	DFS(i+1); //��һ��  
}

int main() {
	while(~scanf("%d%d",&n,&k)) {
		getchar(); //�Իس� 
		if(n==-1 && k==-1) break;		
		for(int i=0; i < n; i++){
			for(int j=0; j < n; j++)
				scanf("%c",&board[i][j]);
				getchar(); //�Իس� 
		}
		memset(placed,0,sizeof(placed));
		cnt = 0; num = 0;
		DFS(0);
		printf("%d\n",cnt);
	}
	return 0;
}

