#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//函数默认参数
//如果传入参数就用传递的参数,否则就用默认值
int func(int a, int b = 20, int c = 30) 
{
	return a + b + c;
}


//注意事项
//1,如果某个位置已经有了默认参数,那么从这个位置往后从左往右,都必须有默认参数func1
//int func1(int a, int b = 1, int c)//报错,默认实参不在形参列表的结尾
//{
//	return a + b + c;
//}

//2,如果函数声明有了默认参数,函数实现就不能有默认参数
int func2(int a = 10, int b = 30);
int func2(int a, int b)
{
	return a + b;
}




int main() {

	cout << func(10, 40) << endl;
	//func1(1,2,3);
	system("pause");
	return EXIT_SUCCESS;
}
