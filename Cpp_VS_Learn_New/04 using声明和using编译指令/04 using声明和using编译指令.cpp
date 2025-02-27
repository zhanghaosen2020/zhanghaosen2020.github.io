#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

namespace LOL
{
	int sunWuKongId = 1;
}

void test01()
{
	//int sunWuKongId = 2;
	//01,using声明,说明下面我需要用到命名空间LOL中的sunWuKongId,这样子编译器就不会报错了
	using LOL::sunWuKongId;
	//就近原则和命名空间同时出现时,这样的情况应当避免,会造成二义性,所以我们注释掉
	//错误C2874using 声明导致多次声明“sunWuKongId”

	cout << sunWuKongId << endl;
}

namespace kingGlory
{
	int sunWuKongId = 4;
}
void test02()
{
	//int sunWuKongId = 3;
	//2,using编译指令
	using namespace LOL;//这句的意思和上边有些许差别,作用范围更加广了,只要这个房间里有Id,就可以使用
	using namespace kingGlory;
	//test01上边的using LOL::sunWuKongId;声明方式让作用域变小,只允许你用LOL房间里的这个Id
	//当使用多个编译指令,并且出现同名情况,使用数据需要加作用域,否则编译器不只知道用哪一个房间里的Id
	cout << LOL::sunWuKongId << endl;
	cout << kingGlory::sunWuKongId << endl;
	//这种情况下为何只能从了就近原则?   直接可用和去房间里边找,前者更加简单
}



int main() {

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
