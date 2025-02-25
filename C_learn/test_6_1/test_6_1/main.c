#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	//一维数组
//	int a[] = { 1,2,3,4 };

	printf("%d\n", sizeof(a));//4*4=16
	//sizeof(数组名)，数组名表示整个数组，计算的是整个数组的大小，单位是字节

	printf("%d\n", sizeof(a + 0));//	4/8
	//此处的 a+0 表示首元素地址 ，a不是单独放在sizeof内部，也没有取地址，所以a就是首元素地址 //和上边的区分开哟
	
	printf("%d\n", sizeof(*a));//4
	//a是首元素地址再解引用，就是计算第一个元素的大小，因而是四个字节
	
	printf("%d\n", sizeof(a + 1));//4/8
	//a+1 <==> &a[1]即数组第二个元素的地址

	printf("%d\n", sizeof(a[1]));//4
	//第二个元素的大小(这里的大小是指元素类型所占空间的大小)

	printf("%d\n", sizeof(&a));//4/8
	//&a取出了数组的地址，数组的地址也就是个地址罢了
	
	printf("%d\n", sizeof(*&a));//16
	//1、*和&相消，不就只剩下了个a，就同第一问一样了
	//2、&a取出了整个数组的地址，类型是int(*)[4]，再解引用不就是整个数组的大小了

	printf("%d\n", sizeof(&a + 1));//4
	//&a+1，类型是int(*)[4]，跳过了整个数组，指向末尾元素再后一个的地址，本质是地址
	// &a+1从数组a的地址向后跳过了一个（四个整形元素的）数组的大小
	
	printf("%d\n", sizeof(&a[0]));//4
	//&a[0]第一个元素的地址 的 大小

	printf("%d\n", sizeof(&a[0] + 1));//4
	//&a[0] + 1是第二个元素的地址大小是四个字节
	//&a[0] + 1-->&a[1]
	
	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };//6个元素,这样赋值不会在后边加 \0
	printf("%d\n", sizeof(arr));// 6
	//arr数组名，表示首元素地址，但在sizeof(数组名)中，计算的就是整个数组的空间大小

	printf("%d\n", sizeof(arr + 0));// 4/8
	//arr+0首元素地址

	printf("%d\n", sizeof(*arr));// 1
	//*arr就是数组的首元素，大小是一个字节
	//*arr --> arr[0],*(arr+0) -->arr[0]

	printf("%d\n", sizeof(arr[1]));// 1
	//第一个元素

	printf("%d\n", sizeof(&arr));//4/8 
	//&arr数组的地址，是地址就是4/8

	printf("%d\n", sizeof(&arr + 1));// 4/8
	//&arr+1是数组后的地址

	printf("%d\n", sizeof(&arr[0] + 1));// 4/8
	//&arr[0]+1是第二个元素地址

	//strlen是库函数，只针对字符串
	// sizeof是操作符，范围会更广阔一点
	//size_t strlen(const char* str);
	//strlen()，求的时字符串长度关注字符串中的 \0 （从指定元素位置开始，往后直到 \0）
	printf("%d\n", strlen(arr));//随机值>=6  (只有当在内存中遇到 00 值时才截至计算)
	printf("%d\n", strlen(arr + 0)); //随机值 

	printf("%d\n", strlen(*arr)); //strlen()参数应当传递地址，此处有问题strlen('a');-->strlen(97);不正确的
	//随便给了个地址，是野指针呢

	printf("%d\n", strlen(arr[1]));//strlen('b')-->strlen(98)//这是和上边一样的有问题
	
	printf("%d\n", strlen(&arr));//随机值

	printf("%d\n", strlen(&arr + 1));//随机值，比上边的随机值 小6 （-6）

	printf("%d\n", strlen(&arr[0] + 1));//随机值 - 1，从b开始数


	//char arr[] = "abcdef";//这样定义字符串系统会在末尾自动添加 \0
	printf("%d\n", sizeof(arr));// 7 
	//sizeof中单独加数组名，计算整个数组所占空间的大小(单位字节)

	printf("%d\n", sizeof(arr + 0));// 4\8

	printf("%d\n", sizeof(*arr));// 1 
	//相当于计算数组第一个元素所占空间的大小

	printf("%d\n", sizeof(arr[1]));// 1

	printf("%d\n", sizeof(&arr));// 4\8
	
	printf("%d\n", sizeof(&arr + 1));// 4\8

	printf("%d\n", sizeof(&arr[0] + 1));//4\8

	printf("%d\n", strlen(arr));//6

	printf("%d\n", strlen(arr + 0));//6

	printf("%d\n", strlen(*arr));//有问题

	printf("%d\n", strlen(arr[1]));//有问题

	printf("%d\n", strlen(&arr));//6

	printf("%d\n", strlen(&arr + 1));//这里把整个数组都给跳过去了，随机值

	printf("%d\n", strlen(&arr[0] + 1));//4


	char* p = "abcdef";//这样写是把字符串首元素a的地址传递给了p(中是a的地址)
	printf("%d\n", sizeof(p));// 4\8
	//p是一个指针变量，其长度就是4\8

	printf("%d\n", sizeof(p + 1));// 4\8

	printf("%d\n", sizeof(*p));// 1
	//

	printf("%d\n", sizeof(p[0]));// 1
	//p[0]-->*(p+0)-->*p

	printf("%d\n", sizeof(&p));// 4\8 二级指针
	//

	printf("%d\n", sizeof(&p + 1));// 4\8
	//&p+1,跳过的是整个字符串，指向最后一个之后的地址

	printf("%d\n", sizeof(&p[0] + 1));//4 \ 8

	printf("%d\n", strlen(p));//6

	printf("%d\n", strlen(p + 1));//5
	
	printf("%d\n", strlen(*p));//err
	
	printf("%d\n", strlen(p[0]));//err
	
	printf("%d\n", strlen(&p));//(随机值)


	printf("%d\n", strlen(&p + 1));//(随机值与上无必然联系)err
	

	printf("%d\n", strlen(&p[0] + 1));//5


	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	//单独首元素地址，在sizeof中计算的是整个数组的大小 3*4*4=48

	printf("%d\n", sizeof(a[0][0]));//4
	//二维数组中第一个元素的大小
	
	printf("%d\n", sizeof(a[0]));//16
	//二维数组中a[0]表示第一行的数组名，这里表示计算第一行数组的大小
	//单独放a[0],表示第一行这整个数组

	printf("%d\n", sizeof(a[0] + 1));// 4/8
	//	a[0]+1  -->  &a[0][0]+1,表示的是第一行第二个元素的地址
	//没有单独放，a[0]就代表首个元的地址

	printf("%d\n", sizeof(*(a[0] + 1)));// 4
	//即对第一行第二个元素的地址解引用

	printf("%d\n", sizeof(a + 1));//  4/8
	//a虽然是二维数组的地址但并未单独放在sizeof内，
	//此处的a表示首元素地址，二维数组的首元素就是他的第一行，a在这里表示第一行的地址
	//a+1就是跳过第一行，表示第二行的地址
	//&a+1表示跳过整个二维数组

	printf("%d\n", sizeof(*(a + 1)));// 16
	//即对第二行数组地址解引用
	//*(a+1) -->  a[1],即表示单独把第二行数组名放入sizeof内

	printf("%d\n", sizeof(&a[0] + 1));// 4/8
	//&a[0] -- 对第一行的数组名取地址，拿出的是第一行的地址
	//&a[0]+1 -- 得到的是第二行的地址

	printf("%d\n", sizeof(*(&a[0] + 1)));//16
	//对第二行的地址解引用

	printf("%d\n", sizeof(*a));//16
	//a表示首元素的地址，就是第一行的地址
	//*a就是对第一行地址的解引用，拿到的就是第一行

	printf("%d\n", sizeof(a[3]));// 16,只关注类型
	//
	return 0;
}