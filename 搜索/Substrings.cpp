#include <cstdio>
#include <cstring>
char str[101][101];
int n;
int find_str(int len,int index) {
	char s[101],pos[101],inv[101];
	bool flag;
	int i,j,l;
	//���ַ�����������
	strcpy(s,str[index]);
	l=len;
	// ���������
	while(l>0) {
		flag = 0;
		for(i = 0; i <= len-l; ++i) {
			flag=1;//flag��ʼ��Ϊ1
			//�����ַ�������str�е�i��λ�ã�ȡl���ȣ�����ǰ��ģ�
			strncpy(pos,s+i,l);
			//inv Ϊpos������
			for(j=0; j<l; j++)
				inv[j]=pos[l-j-1];
			// �ַ����飬���\0����ֹĳЩ����Ҫ�ĳ�ͻ
			pos[l]=inv[l] ='\0';
			for(j=0; j<n; j++) {
				if(strstr(str[j],pos)==NULL&&strstr(str[j],inv)==NULL) {
					flag=0;
					break;
				}
			}
			if(flag)    break;
		}
		if(flag)    break;
		--l;
	}
	return l;
}

int main() {
	int i,t,min_len,index;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		min_len = 101;
		for(i = 0; i < n; i++) {
			scanf("%s",str[i]);
			//�ҵ���̵��ַ���
			if(strlen(str[i])<min_len) {
				min_len = strlen(str[i]);//��¼����ִ��ĳ���
				index = i;//��¼����ִ���λ��
			}
		}
		printf("%d\n",find_str(min_len,index));
	}
	return 0;
}
