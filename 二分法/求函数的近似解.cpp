#include <iostream>
#include <cmath>
#include <cstdio>
#define eps 0.00001
using namespace std;

double f(double x) { //f(x)����
	double y = x * x * x - x -1;
	return y;
}
bool pd(double x) { //�ж��Ƿ�Ϊ������ֵ
	if(fabs(f(x)) < eps)	return 1;
	else 					return 0;
}
int main() {
	double a,b;
	cout << "����������a��b��";
	cin >> a >> b;
	if(a > b)		swap(a,b);	//���a>b���������ǵ�ֵ
	double x, x1, x2, mid;
	for(x = a; x <= b; x += 0.1) {
		x1 = x, x2 = x + 0.1;
		if(pd(x1))
			printf("%.6lf\n",x1);
		else if(f(x1) * f(x2) < 0) {
			// ���ַ�
			while(x2 - x1 >= 0.00001) {
				mid = (x1 + x2) / 2;
				if(f(x1) * f(mid) <= 0)  //ѹ������
					x2 = mid;
				else
					x1 = mid;
			}
			printf("%.6lf\n",x1);
		}
	}
	return 0;
}
