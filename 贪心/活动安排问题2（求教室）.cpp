#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int Ends[10005];

struct Time {
	int begin,end;
} time[10005];

bool cmp(const Time &a, const Time &b) {
	if(a.begin==b.begin) return a.end < b.end;
	else return a.begin < b.begin;
}

int main() {
	int n, ans/*��ʾ�м�������ʱ���,���������*/;
	while(cin>>n) {
		ans = 0;
		for(int i=1; i<=n; i++)
			scanf("%d%d", &time[i].begin, &time[i].end);
		sort(time+1, time+1+n, cmp);
		Ends[++ans] = time[1].end;
		int i, j;
		for(i=2; i<=n; i++) {
			bool b = 0; // ��ʾû�ҵ�
			for(j=1; j<=ans; j++) {
				if(time[i].begin >= Ends[j]) { //��ʾ�ҵ���һ����ҿ��Խ���
					Ends[j] = time[i].end;
					b=1; // ��ʾ�ҵ�
					break;
				}
			}
			if(b==0) //�Ҳ������ң���Ҫ�ټ�һ��
				Ends[++ans] = time[i].end;
		}
		printf("%d\n",ans);
	}
	return 0;
}
