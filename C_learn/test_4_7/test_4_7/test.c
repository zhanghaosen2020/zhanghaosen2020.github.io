#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//C�ı�׼������д��

//������д��� ctrl+f5+fn
 
//��׼�����������stdio

//main�����ǳ�������(����Ψһ)
//int main()
//{
//	printf("hello c world!\n");
//	printf("hello c world!\n");
//	printf("hello c world!\n");
//	printf("hello c world!\n");
//
//	return 0;
//}

//int main()
//{
//	printf("%zu\n",sizeof(char));//��%zu������%d��ʾ����һ���޷��ŵ�sizeof�ĺ�������ֵ
//	printf("%zu\n", sizeof(short));
//	printf("%zu\n", sizeof(int));
//	printf("%zu\n", sizeof(long));
//	printf("%zu\n", sizeof(long long));
//	printf("%zu\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//
//
//	return 0;
//}

//int main()
//{
//	int age = 24;//�������Ϳ������ڴ�ռ�����һ���ֿռ䣬����Ÿ������͵Ŀռ�
//	double price = 666.6;//���������������������������ı��������ڴ�����ռ�
//	return 0;
//}


//1�����������䡢���أ��ͳ�����pi������
//2��������Ϊ�ֲ����������ڲ����壩��ȫ�ֱ������������ڲ����壩����
//3������һ���ֲ���ȫ�ֱ�����ͬ�ı�����������,���ǲ���������һ����ʱ���ֲ����ȵ���ԭ��

//int b = 20;//ȫ�ֱ���
//
//int main()
//{
//	short age = 24;//����
//	int high = 100;//���
//	float weight = 88.5;//����
//	int b = 1;
//	printf("b = %d\n",b);
//}


//�������������ĺ�
//int main()
//{
//	int num1 = 0;//Ҫ�Ա�����ʼ����������������ֵ
//	int num2 = 0;
//
//	//����2������
//	scanf("%d %d", &num1, &num2);
//	//���
//	int sum = num1 + num2;
//	//���
//	printf("sum = %d\n",sum);
//
//	return 0;
//}


//������������һ��������������Щ�ط�ʹ�ã���Щ�ط���������������:1���ֲ�����   2��ȫ������
//�����������ڣ�1���ֲ�����

//int a = 10;//ȫ�ֱ�������������������
//void test()
//{
//	printf("test-->%d\n", a);
//}
//int main()
//{		//int a = 10;//���˴���Ϊ�������±ߵľֲ�������Χ���󣬻����ŵĲ㼶�������÷�Χ��
//	test();
//
//	{
//		//int a = 10;//(�˴���Ϊ�ֲ�����ʹ�ã�ͬһ����������߿��Ե��ø�ֵ)
//		printf("a = %d\n",a);
//	}
//	printf("a = %d\n", a);
//	return 0;
//}
 



//1.���泣�� 3  3.14  'a'�ȵ�
//2.const���εĳ�����
//3.define����ı�ʶ������
//4.ö�ٳ���
//int main()
//{
//	const int a = 20;//const���ε�a�����Ǳ����������ܱ��޸ģ��г��������ԡ�
////	int arr[a] = {10};//�˴���������Ҫ��һ��������������a��ȴ���ԣ�֤�������Ǳ���
//	return 0;
//}
//
//#define MAX 100
//#define STR "abcdef"
//
//int main()
//{
//	printf("%d\n", MAX);
//	int a = MAX;
//	printf("%d\n",a);
//	printf("%s\n", STR);
//	return 0;
//}

//ö�ٳ���
enum Color
{
	//ö�ٳ���
	RED,
	GREEN,
	BLUE
};

enum Sex
{
	MALE,
	FEMALE,
	SECRET
};
int main()
{
	
	//��ԭɫ green red blue
	enum Color c = RED;
	//RED = 20;//����ģ�ö�����Ͳ������
	return 0;
}

