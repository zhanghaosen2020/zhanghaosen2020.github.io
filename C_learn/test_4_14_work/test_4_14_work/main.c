#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//дһ�������ж�һ���ǲ�������
//�ܱ�4�����������ܱ�100����
//�����ܱ�400����
//int Is_LeapYear(int x)
//{
//	if (((x % 4 == 0) && (x % 100 != 0)) || (x % 400) == 0)
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int year = 0;
//	printf("������Ҫ�жϵ����:>");
//	scanf("%d", &year);
//
//	if (Is_LeapYear(year))
//	{
//		printf("year = %d ������", year);
//	}
//	else
//	{
//		printf("year = %d ��������", year);
//	}
//	return 0;
//}

//��ӡ1000-2000֮�������
//Ϊʲô��ͬʱ��ӡ�أ� ���������᲻����һ��ģ�黯�̶Ȳ�������������ԣ�
//int Is_LeapYear(int x)
//{
//	if (((x % 4 == 0) && (x % 100 != 0)) || (x % 400) == 0)//�������˴���
//	{
//		return 1;//���귵��1�����򷵻�0��
//	}
//	return 0;
//}
//int main()
//{
//	int year = 0;
//	printf("1000-2000��֮���������:>\n");
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (Is_LeapYear(year))
//		{
//			printf("%d\t ", year);//\t���Ʊ��
//		}
//	}
//	return 0;
//}

//3. дһ��������ʵ��һ��������������Ķ��ֲ��ҡ�

//��һ������ int arr[],ʵ���ϣ����������ݸ�������������Ԫ�ص�ַ����ߵĵ��ö�����
//�����������е�arr[],���鴫�Σ�����һ����ʱ��������ָ������ڵ���ԭ����
//�����ں����ڲ�����һ�������������ֵ�����Ԫ�ظ����벻���׵�
//�β� arr ����ȥ�����飬��������һ��ָ�����
//int BinarySearch(int arr[],int num,int sz)//��ô��������������������
//{
//	//�������
//	int left = 0;//���±�
//	int right = sz - 1;//���±�
//
//	//�۰����ʵ��
//	while (left <= right)
//	{
//		//int mid = (right + left) / 2;//�۰�
//		int mid = left + (right - left) / 2;//��������mid�������
//
//		if (arr[mid] < num)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > num)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;//�ҵ�֮�󷵻��±�
//			break;
//		}
//	}
//	if (left > right)
//	{
//		return -1;
//	}
//}
//int main()
//{
//	int arr[] = { 1,3,5,7,9,10,12,13,15,19 };//�ȶ���һ��������������
//	int num = 0;//Ҫ���ҵ�����
//	int sz = sizeof(arr) / sizeof(arr[0]);//Ԫ�ظ���
//	//����
//	printf("������Ҫ���ҵ�����:>");
//	scanf("%d", &num);
//
//	//����
//	//�ҵ������±꣬δ�ҵ����� -1��
//	int ret = BinarySearch(arr, num, sz);
//	if (ret == -1)
//	{
//		printf("δ�ҵ�!");
//	}
//	else
//	{
//		printf("�ҵ���,�±�Ϊ:%d",ret);
//	}
//
//	return 0;
//}
//��ϰһ�¶��ַ�   BinarySearch 
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,11 };//����һ��������������
//	int left = 0;//�������±�
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;//Ԫ�ظ���-1�����±�
//	int num = 0;
//	
//	printf("������Ҫ���ҵ�����:>");
//	scanf("%d", &num);
//
//		while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < num)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > num )
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±�Ϊ��%d\n", mid);
//			break;
//		}
//	}		
//	if (left > right)
//	{
//		printf("�Ҳ�������!\n");
//	}
//	return 0;
//}

//4. дһ��������ÿ����һ������������ͻὫ num ��ֵ����1��
void Add(int* p)//�޷���ֵ��void
{
	*p += 1;
}

int main()
{
	int num = 0;
	Add(&num);//Add()����һ��num���1���ô�ַ���ñȽϷ���
	printf("num = %d\n", num);
	Add(&num);
	printf("num = %d\n", num);
	return 0;
}