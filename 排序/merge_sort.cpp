#include <cstdio>
#define MAXN 505
#define MX 0x3f3f3f3f
int data[13] = {3,29,15,59,46,13,5,1,67,44,48,100,84};
int result[MAXN];

void Merge(int* data, int start, int end, int* result) {
	int left_len = (end - start + 1) / 2 +1;
	int left_index = start;
	int right_index = start + left_len;
	int result_index = start;
	
	while(left_index < start + left_len && right_index < end+1) {
		//�Էֱ��Ѿ��ź�������������������кϲ�
		if(data[left_index] < data[right_index])
			result[result_index++] = data[left_index++];
		else
			result[result_index++] = data[right_index++];
	}
	
	while(left_index < start + left_len)
		result[result_index++] = data[left_index++];
	while(right_index < end+1) //+1?
		result[result_index++] = data[right_index++];
}

void MergeSort(int* data, int start, int end, int* result) {
	if(end-start == 1){
		if(data[end] < data[start]) {
			int temp = data[start];
			data[start] = data[end];
			data[end] = temp;
		}
		return;
	}
	else if(end-start == 0)
		return;
	else {
		//�������������䣬�ֱ�������������������
		MergeSort(data, start, start+(end-start+1)/2, result);
		MergeSort(data, start+(end-start+1)/2+1, end, result);
		//��ʼ�鲢�Ѿ��ź����start��end֮�������
		Merge(data,start,end,result);
		//���������������ݸ��Ƶ�ԭʼ������ȥ
		for(int i = start; i <= end; ++i)
			data[i] = result[i];
	}
}

int main() {
	MergeSort(data,0,12,result);
	for(int i=0; i<13; i++)
		printf("%d ",data[i]);
	return 0;
}
