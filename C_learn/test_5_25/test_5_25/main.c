#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
//ģ��ʵ��strlen����
//int my_strlen(const char* p)
//{
//	int count = 0;
//	assert(p != NULL);//��ֹ���ݹ����ĵ�ַ�ǿ�ָ��
//	while (*p++)
//	{
//		count++;
//	}
//	return count;
//}
//
////����ģ��ʵ����strcpy����
//void my_strcpy(char* dst, const char* res)
//{
//	assert(res != NULL);
//	while (*res)
//	{
//		*dst++ = *res++;
//	}
//}
//
//int main()
//{
//	char arr[100] = "i am ironman!";
//	char arr1[100] = "";
//	int len = my_strlen(arr);
//	my_strcpy(arr1, arr);
//	printf("%s����Ϊ = %d\n",arr,len);
//	printf("%s", arr1);
//	return 0;
//}

//��������ż��˳��
//ʹ������ȫ��λ��ż��֮ǰ
void move_odd_even(int arr[], int sz)
{
	int left = 0;
	int right = sz;
	while (left < right)
	{
		//��������Ѱ��ż��

		//�±�Ѱ����ż���ķ�ʽ���������������ȫ��Ϊ��������ż����������ܷɵģ�����Ҫ�޶�����
		while ((arr[left] % 2 == 1)&&(left<right))//��������ѭ��˵������Ϊ������Ȼ��left++�ٴ��ж��Ƿ�Ϊ�������������ǣ�left�±����ż��
		{							//���±��ҳ������������н������ﵽĿ��
			left++;
		}
		//��������Ѱ������
		while ((arr[right] % 2 == 0)&&(left<right))
		{
			right--;
		}
		//����
		if (left < right)
		{
			int tmp = 0;
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;

			left++;//����һ��Ԫ��
			right--;
		}
	}
}
int main()
{
	//����
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		scanf("%d", arr + i);//����&arr[i]
	}
	
	//����
	move_odd_even(arr,sz-1);
	//���
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}