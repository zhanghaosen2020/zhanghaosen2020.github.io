#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//输入输出流文件,类似于C的stdio.h
using namespace std;//使用标准命名空间,(类似于打开一个大房间,房间里的一些东西我们会使用到)
//注意CPP的头文件新风格是不带.h的(对于一些自带的)
#include<math.h>
#include<cmath>

int main()
{
	//标准的输出流对象cout,配合<<,向屏幕中输出信息
	cout << "hello World!!" << 1234 << 'a' << endl;
	//之所以提倡用cout而不用printf是因为不需要记忆输出类型,只要是自带的数据类型都可以自动识别
	
	system("pause");

	return EXIT_SUCCESS;
}