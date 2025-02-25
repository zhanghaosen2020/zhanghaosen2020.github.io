#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{	
	int a = 10;//此句申请一个 内存空间名为a 存放10这个数据
	&a;//查看a这个空间的地址(房间号)
	printf("%p\n",&a);// %p用来打印地址（以地址形式打印）
	int* p = &a;//*表示p为指针变量，int为指针变量所指向的变量类型，p仍然是变量，其中存放的是a的地址
	&p;//p为新开的空间，&p查看p此时的内存地址
	*p = 20;// 此处 * 代表解析引用p中存放的地址，也即找到了p所指向的对象，*p就是p指向的对象此处为a
	//即 对 *p 操作，等效于 对 a 操作
	printf("%d\n", *p);
	printf("%d\n", a);
	printf("%p\n", &*p);
	printf("%p\n", &a);

	//不管什么类型的指针，都是在创建指针变量
	//指针变量是用来存放地址的
	//指针变量的大小取决于一个地址存放需要多大空间
	printf("%zu\n", sizeof(char*));
	printf("%zu\n", sizeof(short*));
	printf("%zu\n", sizeof(int*));
	printf("%zu\n", sizeof(double*));
	return 0;
}