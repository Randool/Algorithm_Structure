#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	char a1[400], b1[400];
	int a[400], b[400], c[400], alen, blen, clen, i, x, temp;
	//��ʼ������ 
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	//���������ַ� ���ո��������� 
	gets(a1);
	gets(b1);
	//��ó��� 
	alen = strlen(a1);
	blen = strlen(b1);
	//char-->int
	for(i = 0; i < alen; i++)	a[alen-i] = a1[i]-48;
	for(i = 0; i < blen; i++)	b[blen-i] = b1[i]-48;
	//ת��c 
	x = 1; temp = 0;
	while(x <= alen || x <= blen){
		c[x] = a[x] + b[x] + temp;
		temp = c[x] / 10;
		c[x] %= 10;	
		x++;
	}
	c[x] = temp;
	//��� 
	if(c[x] == 0)	x--;
	for(i=x; i>=1; i--)
		cout<<c[i];	
	
	return 0;
}
