#include<cstdio>
#include<cstring>

char a[100];
int b[100],len,sum=0;
 
int main()
{
 	scanf("%s",&a);		//�ַ����� 
 	
 	len=strlen(a);		//���ַ����� 
 	for(int i=0;i<=len-1;i++)
 	{
 		b[i]=a[i]-'0';	// 
 		sum+=b[i];
	}
	printf("%d",sum);
	return 0;
}
