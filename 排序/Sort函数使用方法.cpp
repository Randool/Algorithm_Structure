#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

/*Sort����������������
��1����һ����Ҫ������������ʼ��ַ��
��2���ڶ����ǽ����ĵ�ַ�����һλҪ����ĵ�ַ��
��3������������������ķ����������ǴӴ�СҲ���Ǵ�С���󣬻����Բ�д��������������ʱĬ�ϵ����򷽷��Ǵ�С��������

Sort����ʹ��ģ��:
	Sort(start,end,���򷽷�)

ͬʱ��sort��ԭ��ַ�޸� 
*/ 
	bool complare(int a , int b)
	{
		return a > b ;	// " > " ��������������� 
	}

int main()
{
	int a[10] = {9,6,3,8,5,2,7,4,1,0} ;
	for(int i = 0; i < 10; i++)
		cout<<a[i]<< " " ;
	cout << endl;

//--------------------//��С���� 
	sort(a,a+10) ;
	for(int i = 0; i < 10; i++)
		cout << a[i] << " " ;
	cout<<endl;

//--------------------//�Ӵ�С 	
	sort(a , a + 10 , complare); //������Ͳ���Ҫ��complare������������ˣ����ǹ���
	for(int i = 0; i < 10; i++)
		cout << a[i] << " " ;
	cout << endl;

//--------------------//
	//c++��׼���ṩ����ĺ��� Sortt��Ϊ����������
	//�������������������߳����������õ�����ԭ��

//--------------------//less<��������>()	��С��������
	sort( a , a+10 , less<int>() );
	for( int i = 0 ; i < 10 ; i++ )
		cout << a[i] << " " ;
	cout << endl;

//--------------------//greater<��������>()	�Ӵ�С����
	sort( a , a+10 , greater<int>() );
	for( int i = 0; i < 10; i++ )
		cout << a[i] << " " ;
	cout << endl;

//--------------------//sort�����Զ��ַ���������
	char b[15] = "asdAfghjHkZlFk";		//�ַ�����ĩλ�� \0 ����Ҫһ����λ����� a[15] 
	
	for( int i = 0 ; i < 15 ; i++ )
		cout << b[i] << " " ;
	cout << endl;
	
	sort( b , b+15 , less<char>() );
	for( int i = 0 ; i < 15 ; i++ )
		cout << b[i]<< " " ;
	cout << endl;
	
	sort( b , b + 15 , greater<char>() ); 
	for( int i = 0 ; i < 15 ; i++ )
		cout << b[i] << " " ;
	cout << endl; 
	
return 0 ;
}


