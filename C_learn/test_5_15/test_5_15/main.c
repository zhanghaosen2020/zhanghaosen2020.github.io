#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

//ģ��ʵ�����ַ������ȵĺ���strlen
int my_strlen(const char* str)//���������޸�ԭ�ַ�����ֵ���������const��һ������
{
	int count = 0;
	assert(str);//��ֹstr���ݹ���ʱ�ǿ�ָ��
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	char arr[] = "hellow hellow";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}