#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//ָ�뽲��
//X86 - 32λ�Ļ���
//X64 - 64λ�Ļ���
//int main()
//{
//	int a = 0x11223344;
//	char* pc = NULL;
//	short* ps = NULL;
//	int* pi = NULL;
//	double* pd = NULL;
//
//	//sizeof �ķ���ֵ�������޷�������  zu����ӡ
//	printf("%u\n", sizeof(pc));
//	printf("%u\n", sizeof(short*));
//	printf("%u\n", sizeof(ps));
//	printf("%u\n", sizeof(pi));
//	printf("%u\n", sizeof(pd));
//
//	//��Ȼָ��������ռ�ռ����4\8��ôΪʲô��ֱ�ӹ涨һ��������������ŵ�ַ��
//	//������̽��ָ�����͵�����
//
//
//	return 0;
//}

//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	//Ұָ����ǣ�ָ��ָ���λ���ǲ���֪��
//	int* p;//�˴�pû�г�ʼ��������ζ��û����ȷ��ָ��
//	//һ���ֲ���������ʼ�������ŵ������ֵ
//	*p = 10;//�Ƿ������ڴ��ˣ������p����Ұָ��
//
//	//�ڴ�ռ��ͷŵ��µ�Ұָ��
//	int* pa = test();//�������꺯��֮��a�����ʱ�ռ�ͱ��ͷ��ˣ������㻹�ǵ�
//	//ǰŮ�ѵ绰������Ȼ����ϵ����������������������������ˣ���Ҳ��Ұָ�������
//	return 0;
//}



//ָ��Ӽ�����
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//ͨ�������±�ķ�ʽ��ֵ
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 1;
//	}
//
//	int* p = arr;//ָ�������ߴ����arr������Ԫ�ص�ַ
//	for (i = 0; i < sz; i++)
//	{
//		//*(p+i)=2,ʵ�ֵ�Ч���ͺ��һ��
//		*p = 1;
//		p++;
//	}
//	return 0;
//}


//ָ��Ӽ�ָ��
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", &arr[9] - &arr[0]);//���Ϊ 9 ������Ÿ�Ԫ�ظ���
//	//ָ���ָ��ľ���ֵ�õ�����ָ���ָ��֮��Ԫ�صĸ���
//	//��������ָ�붼�������ָ��ͬһ��ռ��2��ָ��������
//	return 0;
//}

//���ַ�������
//1��
//int MyStrlen(char* str)//���Ҫ��char*���͵ı�������
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//2���ݹ�

//3���õ�ַ��ȥ��ַ�ķ�ʽ
//int MyStrlen(char* str)
//{
//	char* start = str;//��Ԫ�ص�ַ
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return (str - start);//�˴�strΪ \0 �ĵ�ַ
//}
//int main()
//{
//	int len = MyStrlen("abcdefg");//�ַ������δ������ַ�����Ԫ�ص�ַ
//	printf("%d\n", len);
//
//	return 0;
//}


//#define N_VALUES 5
//float values[N_VALUES];
//float* vp = NULL;
//
//int main()
//{
//	for (vp = &values[0]; vp < &values[N_VALUES];)
//	{
//		*vp++ = 12;
//	}
//	return 0;
//}


//����ָ��

//int main()
//{
//	int a = 10;
//	//int * pa����� *˵��pa��ָ�������int˵��paָ���������int����
//	int* pa = &a;//pa��һ��ָ�������һ��ָ�����
//	*pa = 20;//a��Ϊ��20
//	printf("%d\n", a);
//
//	//int* * ppa,�ڶ�����˵��ppa��ָ�������int*˵��ppa��ָ��Ķ�����������Ϊint*
//	int** ppa = &pa;//��ʱ��ppa��һ������ָ�룬�����pa�ĵ�ַ
//	
//	**ppa = 30;//*ppaָ����pa���������*ppa���ǽ�����a
//	
//	printf("%d\n", a);
//
//
//
//	return 0;
//}

//ָ�����飺���ָ����������ָ������
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	int arr[10] = { 0 };
//
//	int* pa = &a;
//	int* pb = &b;
//	int* pc = &c;
//
//	int* parr[10] = { &a,&b,&c };
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", *(parr[i]));
//	}
//
//	
//	return 0;
//}

//ָ��������ģ���ά����

int main()
{
	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


	int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 2,3,4,5 };
	int arr3[4] = { 3,4,5,6 };
	int* parr[3] = { arr1,arr2,arr3 };//��ŵ�����Ԫ�ص�ַ

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", parr[i][j]);
			//printf("%d ", *(parr[i]+j));//Ч��ͬ��
//parr[i][j]==*(parr[i]+j)==*(*(parr+i)+j)			
//parr��һ��ָ�����飬��ŵ���arr1����(��Ԫ�ص�ַ)��parr[i]�����˵�ַ
//parr[i]�����Ԫ�ص�ַ��parr[i][j],���Ƕ����������
//arr[1]=*(arr+1);
		}
		printf("\n");
	}

	return 0;
}