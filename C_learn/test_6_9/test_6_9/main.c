#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
//int main()
//{
//	char arr1[] = "abcdef";//abcdef\0
//	int len = strlen(arr1);//��ʼ��ַ�� \0 ���� ����
//	
//	char arr2[] = { 'b','i','t' };//����������ʼ���Ļ���û���� \0 ��β�����������������ó����ֵ
//	
//	//int len = strlen(arr2);//������ͳ�Ƴ����ĳ�����û�������
//	return 0;
//}

//ģ��ʵ���ַ�������

//����������
//ָ��-ָ��
//�ݹ�ķ�ʽ
//size_t my_strlen(const char* str)
//{
//	size_t count = 0;
//	assert(str);
//	while ((*str) != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	size_t n = my_strlen(arr);
//	printf("%u\n", n);
//	return 0;
//}

//int main()
//{
//	char name[20] = { 0 };
//	strcpy(name, "zhangsan");
//	//�����������鷳�𣿲��� name = "zhangsan";�����ᱨ��name��һ����ַ����ַ��һ�����������ܱ���ֵ
//	printf("%s\n", name);
//	return 0;
//}

//ģ��ʵ��strcpy
//char* my_strcpy(char* dest, const char* sour)
//{
//	assert(dest);
//	assert(sour);
//	char* ret = dest;
//	/*while (*sour != '\0')*/
//	while (*sour)
//	{
//		*dest++ = *sour++;
//	}
//	*dest = *sour;
//	//*dest = '\0';
//	return ret;
//}
//char* my_strcpy(char* dest, const char* sour)
//{
//	//assert(dest);
//	//assert(sour);
//	assert(dest && sour);
//	char* ret = dest;
//	while (*dest++ = *sour++)//�ȸ�ֵ���ж�
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcedf";
//	char arr2[20] = { 0 };
//	my_strcpy(arr2,arr1);
//	printf("%s\n", arr2);
//	return 0;
//}


//�ַ���׷�Ӻ���
//char* my_strcat(char* dest, const char* sour)
//{
//	assert(dest && sour);
//	char* ret = dest;
//	//�ҵ�Ŀ��ռ��\0(ĩβ)
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//����
//	while (*dest = *sour)
//	{
//		dest++;
//		sour++;
//	}
//
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	//strcat(arr1, "world");
//	my_strcat(arr1, "world");
//	printf("%s\n", arr1);
//	return 0;
//}

//�ַ����ȽϺ���
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
///*	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;*/ //�鷳��
//	return (*str1 - *str2);//ascll��ֱֵ�ӱȽ�
//}
//int main()
//{
//	char arr1[20] = "zhaogsan";
//	char arr2[] = "zhangsanfeng";
//	//�Ƚ������ַ����Ƿ����
//	int ret = my_strcmp(arr1, arr2);
//	if (ret < 0)
//		printf("arr1 < arr2\n");
//	else if (ret > 0)
//		printf("arr1 > arr2\n");
//	else
//		printf("arr1 = arr2\n");
//
//	return 0;
//}


//�ϱ��ǳ��Ȳ������Ƶ��ַ�������
//���Կ��ǳ����������ַ�������



//�����Ӵ�����strstr
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "hello bit";
//	strncpy(arr1, arr2, 6);
//
//	char str[] = "my name is zhanghaosen";
//	char substr[] = "zhanghaosen";
//	
//	char* ret = strstr(str, substr);
//	if (ret == NULL)
//	{
//		printf("�Ӵ�������\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}	
//}


//ģ��ʵ��strstr����
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//��֤���ݵ�ָ����Ч
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	const char* p = str1;
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)p;//ֱ�ӷ��صĻ�p��char*�ģ�û��const�������Ҫǿ������ת��һ��
//		}
//		p++;
//	}
//	return NULL;
//}
//int main()
//{
//	char str[] = "my name is zhanghaosen";
//	char substr[] = "zhanghaosen";
//	char* ret = my_strstr(str, substr);
//	if (ret == NULL)
//	{
//		printf("�Ӵ�������\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}	
//}


//strtok�����и��ַ���
//int main()
//{
//	const char* sep = ".@";
//	char email[] = "zhanghaosen@chongqingyoudian.com.ney";
//	char cpemail[40] = { 0 };
//	strcpy(cpemail, email);
//	char* ret = NULL;
//
//	for (ret = strtok(cpemail, sep);ret!='\0';ret=strtok(NULL,sep))
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}


//strerror
//c���ԵĿ⺯������ִ��ʧ�ܵ�ʱ�򣬶������ô�����
//�����ǽ�������ת��Ϊ��Ӧ�Ĵ�����Ϣ
//int main()
//{
//	//printf("%s\n", strerror(0));
//	//printf("%s\n", strerror(1));
//	//printf("%s\n", strerror(2));
//	//printf("%s\n", strerror(4));
//	//	No error
//	//	Operation not permitted
//	//	No such file or directory
//	//	Interrupted function call
//
//	//errno - C�������õ�һ��ȫ�ֵĴ������ű���
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//
//	}
//	else
//	{
//		//
//	}
//
//	return 0;
//}

#include<ctype.h>

//int main()
//{
//	//int a = isspace(' ');//�ж��ǲ��ǿհ��ַ�
//	//printf("%d\n", a);
//	int a = isdigit(' ');
//	printf("%d\n", a);
//
//	printf("%c\n", tolower('W'));//��С��дת������
//	return 0;
//}


//ģ��ʵ��memcpy
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;//�����Ӵ���ʹ��������Ϊϸ������һ���ֽ�һ���ֽڵĻ�
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7 };
//	int arr2[9] = {0};
//	memcpy(arr2, arr1, sizeof(arr1));//�ڴ濽������
//
//	float arr3[] = { 1.0,2.0,3.0,4.0 };
//	float arr4[8] = { 0.0 };
//	my_memcpy(arr4, arr3, sizeof(arr3));
//
//	int arr5[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memcpy(arr5 + 2, arr5, 20);
//	memmove(arr5 + 2, arr5, 20);
//
//
//	return 0;
//}

//ģ��ʵ��memmove����
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src); 
//	void* ret = dest;
//
//	if (dest < src)
//	{
//		//��ǰ��󿽱�
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//�Ӻ���ǰ����
//		while (num--)//��һ�������
//		{
//			*((char*)dest + num) = *((char*)src + num);//�ó�β���ϵ��ֽڽ���
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1 + 2, arr1,20);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	return 0;
//}

int main()
{
	int arr1[] = { 1,2,3,4,5 };//01 00 00 00'02 00 00 00'03 00 00 00'04 00 00 00
	int arr2[] = { 1,3,2 };
	int ret = memcmp(arr1, arr2, 12);
	printf("%d\n", ret);

	char arr[] = "hello bit";
	//memset(arr, 'x', 5);
	memset(arr+6, '+', 3);

	printf("%s\n", arr);
	return 0;
}