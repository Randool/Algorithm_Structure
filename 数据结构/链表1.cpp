//
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[500001];
bool b[302000];

int main()
{
 	memset(a,0,sizeof(b));
	memset(b,0,sizeof(b));
	
	for(int i=1;i<500001;i++)
 	{
 		a[i]=a[i-1]-i;
 		if(a[i]<=0 || b[a[i]]==1 )
 			a[i]=a[i-1]+i;
 		b[a[i]]=1;
	}
 	while(scanf("%d",&n),n+1)
 		printf("%d\n",a[n]);
 	
	return 0;
}
