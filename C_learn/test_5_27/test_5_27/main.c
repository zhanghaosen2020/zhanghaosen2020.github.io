#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//ָ�����

//int main()
//{
//	//ͨ����ַ�޸ĵ����ַ�ֵ
//	//char ch = 'W';
//	//char* pc = &ch;
//	//*pc = 'B';
//	//printf("%c\n", ch);
//	//printf("%d\n", ch);
//
//	char* p = "abcdef";//���ַ�������ĸa��ֵ����ֵ����p
//	//�ϱߵĸ�ֵ��ʽ�ǲ���ȫ�ģ���Ϊ�ұ�Ϊ�����ַ�������˸�ֵȨ�޷Ŵ��ˡ�
//	const char* pc = "abcdef";//�����Щ
//	char arr[] = "abcdef";//�����ǰ��ַ��������������ȥ��
//	
//	printf("%s", p);//%s �ǰѵ�ַp��ֵ�����ӡ��ֱ�� \0 Ϊֹ
//	return 0;
//}

//ģ��ʵ�ֶ�ά����
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };//�˴�ָ����������������ַ
//	//��ӡģ��Ķ�λ����(�ڴ��в�һ����������ŵ�)
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			//printf("%d ", *(parr[i] + j));
//			//��Ϊ*(p+i)-->*p[i]
//			printf("%d ", parr[i][j]);
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}


//int main()
//{
//	char* arr[5] = { 0 };//ָ�����飬���Ԫ�أ�ÿ��Ԫ�ص����ݶ���char*��
//	char*(*pc)[5] = &arr;//
//
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr1;
//	//��ӡ(����ָ����÷�)
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		//printf("%d ", *p);//p��ָ������ģ�*p��ʵ���൱��������������������������Ԫ�ص�ַ
//			//����*p��������������Ԫ�صĵ�ַ
//		printf("%d ", *(*p + i));//�ܱ�Ť
//	}
//
//	return 0;
//}



//����ָ����÷�
//void print1(int arr[3][5],int c,int r)
//{
//	int i = 0;
//	for (i = 0; i < c; i++)
//	{
//		int j = 0;
//		for (j = 0; j < r; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void print2(int(*p)[5], int c, int r)
//{
//	int i = 0;
//	for (i = 0; i < c; i++)
//	{
//		int j = 0;
//		for (j = 0; j < r; j++)
//		{
//			//printf("%d ", *(*(p + i) + j));
//			//p��������int*[5],p��ָ��һ����������ģ������Ԫ��int[5]
//			//p+1����5��intԪ�ص����顣
//			printf("%d ", p[i][j]);
//
//		}
//		printf("\n");
//
//	}
//}
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
//	print1(arr, 3, 5);
//	printf("\n");
//	print2(arr, 3, 5);
//
//	return 0;
//}


//����ָ��
int Add(int x, int y)
{
	return x + y;
}

//���ݵ�ʵ����Add��������Ҳ��������ַ������ú���ָ��������
void calc(int(*pf)(int, int))
{
	int a = 3;
	int b = 5;
	int ret = pf(a, b);
	printf("%d ", ret);
}
int main()
{
	int(*p)(int, int) = Add;//��˾ͽ�Add�����ĵ�ַ���ݸ���p
	//int(*p)(int, int) = &Add;//��������ϱߵ���һ����˼
	//&�������ͺ��������������ĵ�ַ

	int ret = (*p)(3, 6);
	//*��һ�����裬p�д���˺����ĵ�ַ����p�����ã����Ǻ���Add,�ٴ�������Ϳ��Ե�������ʹ����

	printf("%d\n", ret);
	
	calc(Add);
	return 0;
}