#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//������Ƕ�׵��ú���ʽ����
//��������Ƕ�׶���
//int main()
//{
//	int len = strlen("abcdef");
//	printf("%d\n", len);
//	printf("%d\n", strlen("abcdefg"));//��һ��ʵ���Ͼ���ʽ����
//
//	//������ʽ����
//
//	//Each of these functions returns the number of characters printed,
//	// or a negative value if an error occurs
//	printf("%d", printf("%d", printf("%d", 43)));
//
//	//���Ϊ4321���ڲ��ȴ�ӡ43������һ��2���ٴ�ӡһ��2���ٷ���һ��1
//
//	//��ʽ���ʵ�ǰ���ǣ������з���ֵ
//	//������д����ֵ��ʱ��Ĭ�Ϸ���������int
//	return 0;
//}

//�����������Ͷ���
//
//int Add(int, int);//����������ǰ�������ͻ��ñ�������ǰ֪������ô��������ֻ�Ƕ����ں�߶���
#include "add.h"// ""�����Լ�д��ͷ�ļ�����仰���൱�������ˣ���add.h�е�������������
#include "sub.h"

//���뾲̬��ķ���
//#pragma comment(lib,"add.lib")

int main()
{
	int num1 = 0;
	int num2 = 0;
	printf("�����������������м��Կո����:>");
	scanf("%d %d",&num1,&num2);

	int sum = Add(num1, num2);
	printf("%d\n", sum);

	sum = Sub(num1, num2);
	printf("%d\n", sum);

	return 0;
}



