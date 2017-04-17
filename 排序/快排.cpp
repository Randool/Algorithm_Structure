#include <iostream>
using namespace std;
int a[1000];
void qsort(int a[], int p, int q) {
	int m = p + (p-q)/2;
	int l = p, h = q;
	while(l < h) {
		while(a[l] < a[m]) l++;
		while(a[m] < a[h]) h--;
		if(l<h) {
			swap(a[l],a[h]);
			l++;
			h--;
		}
	}
	if(p < h) qsort(a, p, h);
	if(l < q) qsort(a, l, q);
}

int main() {
	int N, i;
	cin >> N;
	for(i=1; i<=N; i++)
		cin >> a[i];
	qsort(a, 1, N);
	for(i=1; i<=N; i++)
		cout << a[i];
	return 0;
}
