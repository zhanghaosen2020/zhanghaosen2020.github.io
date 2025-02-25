#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	int flag = 1;//���������Ѿ��ź�����ˣ������ٴ��ظ�
//	//ȷ������(������Ԫ�ظ���-1)
//	for (i = 0; i < sz - 1; i++)
//	{
//		//����ÿ�����ж��ٴ������Ƚ�
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)//(ÿ�˱Ƚϴ���)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	//����bitλ����ֵ
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	int flag = 1;//���������Ѿ��ź�����ˣ������ٴ��ظ�
	//ȷ������(������Ԫ�ظ���-1)
	for (i = 0; i < sz - 1; i++)
	{
		//����ÿ�����ж��ٴ������Ƚ�
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//(ÿ�˱Ƚϴ���)
		{
			if ((cmp((char*)base + j * width, (char*)base + (j + 1) * width))>0)
			{
				//����
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}				
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int cmp(void* elme1, void* elme2)
{
	return (*(int*)elme1 - *(int*)elme2);//��Ϊ�Ƚϵ������Σ���Ҫ������
}
void test1()
{
	int arr[] = { 99,8,7,6,5,4,3,2,10,0 };
	//�������ų�����
	int sz = sizeof(arr) / sizeof(arr[0]);//��������Ԫ��
	bubble_sort(arr, sz,sizeof(arr[0]),cmp);
	//qsort(arr, sz, sizeof(arr[0]), compare_int);

	//��ӡ����������Ԫ��
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
struct Stu
{
	char name[20];
	int age;
};
int cmp_stu_by_name(const* e1, const* e2)
{
	//return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
	//���ַ����Ƚ���Ҫ�õ�strcmp()����
	return strcmp((*(struct Stu*)e1).name, (*(struct Stu*)e2).name);
	//return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);//����Ҳ�ǶԵ�

}
void test2()
{
	//ʹ��qsort������ṹ������
	struct Stu s[] = { {"zhangsan",15},{"lisi",30},{"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);

}

int main()
{
	test1();
	test2();

	return 0;
}