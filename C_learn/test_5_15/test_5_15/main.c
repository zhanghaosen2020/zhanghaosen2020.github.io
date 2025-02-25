#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

//模拟实现求字符串长度的函数strlen
int my_strlen(const char* str)//我们无需修改原字符串的值，因而加上const做一个修饰
{
	int count = 0;
	assert(str);//防止str传递归来时是空指针
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