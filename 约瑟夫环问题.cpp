#include<iostream>
using namespace std;
int main() {
	int k, a[200], n, m, t, num = 0;
	cin >> n >> m >> k;
	m = m % n;
	if (m==0) m = n;
	
	for (int i=1; i<=n; i++) a[i]=1;
	t=0;
	while (num!=n) {
		t+=a[m];
		if (t==k) {
			cout<<m<<" ";
			t=0;
			num++;
			a[m]=0;
		}
		m++;
		if (m == n + 1) m=1;
	}
	if (m == 1) m = n;
	cout<<endl<<"winer:"<<m<<endl;
}

