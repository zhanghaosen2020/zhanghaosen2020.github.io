#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//单例模式,通过一个类只能使用唯一的一个对象
//主席类
class Chairman {

	//1,将默认构造函数	私有化
private:
	Chairman() {}
public:
	//2,只要拿到一个对象的指针即可,这个指针可以指向唯一的对象
	static Chairman* singleMan;
};

Chairman* Chairman ::singleMan=new Chairman;

void test01()
{
	//Chairman c1;
	//Chairman c2;
	//Chairman* c3 = new Chairman;//在堆区创建

}

int main() {

	system("pause");
	return EXIT_SUCCESS;
}
