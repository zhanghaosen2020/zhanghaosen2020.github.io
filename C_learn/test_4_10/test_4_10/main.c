#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{	
	int a = 10;//�˾�����һ�� �ڴ�ռ���Ϊa ���10�������
	&a;//�鿴a����ռ�ĵ�ַ(�����)
	printf("%p\n",&a);// %p������ӡ��ַ���Ե�ַ��ʽ��ӡ��
	int* p = &a;//*��ʾpΪָ�������intΪָ�������ָ��ı������ͣ�p��Ȼ�Ǳ��������д�ŵ���a�ĵ�ַ
	&p;//pΪ�¿��Ŀռ䣬&p�鿴p��ʱ���ڴ��ַ
	*p = 20;// �˴� * �����������p�д�ŵĵ�ַ��Ҳ���ҵ���p��ָ��Ķ���*p����pָ��Ķ���˴�Ϊa
	//�� �� *p ��������Ч�� �� a ����
	printf("%d\n", *p);
	printf("%d\n", a);
	printf("%p\n", &*p);
	printf("%p\n", &a);

	//����ʲô���͵�ָ�룬�����ڴ���ָ�����
	//ָ�������������ŵ�ַ��
	//ָ������Ĵ�Сȡ����һ����ַ�����Ҫ���ռ�
	printf("%zu\n", sizeof(char*));
	printf("%zu\n", sizeof(short*));
	printf("%zu\n", sizeof(int*));
	printf("%zu\n", sizeof(double*));
	return 0;
}