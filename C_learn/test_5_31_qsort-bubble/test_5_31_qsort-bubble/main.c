#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//��дһ���򵥵�ð������
void qbubble_sort(int arr[], int sz)
{
	//ð�ݵ�����
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;//ÿһ����Ҫcompare���ٴ�
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//����
				int tmp = 0;
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = tmp;
			}
		}
	}
}


//������һ��qsort�������԰�
int compare(const void* elem1, const void* elem2)
{
	return (*(int*)elem1) - (*(int*)elem2);
}

//����һ���ø�д��ð������ģ��ʵ��qsort����(�ŵ��ǿ���ʵ�ֲ�ͬ�������ݵ�����)
void Swap(char* buf1, char* buf2,int width)
{
	int i = 0;
	for (i = 0; i < width;i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void*base,int sz,int width,int compare(const void*elem1,const void*elem2))
{
	//ð�ݵ�����
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;//ÿһ����Ҫcompare���ٴ�
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (compare(((char*)base) + j * width, ((char*)base) + (j + 1) * width) > 0)
			{
				//����
				Swap(((char*)base) + j * width, ((char*)base) + (j + 1) * width,width);
			}
			//if (arr[j] > arr[j + 1])
			//{
			//	//����
			//	int tmp = 0;
			//	tmp = arr[j];
			//	arr[j] = arr[j + 1];
			//	arr[j + 1] = tmp;
			//}
		}
	}
}

int main()
{
	//�������顢���鳤��
	int arr[10] = { 9,100,7,6,5,4,3,2,1,0 };
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	
	//ð������
	//bubble_sort(arr, sz);
	
	//qsort��������
	//qsort(arr,sz,sizeof(arr[0]),compare);
	
	//�����ð������
	qbubble_sort(arr, sz, sizeof(arr[0]), compare);
	//��ӡ�����������
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}