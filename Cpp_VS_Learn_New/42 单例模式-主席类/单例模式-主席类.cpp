#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//单例模式,通过一个类只能使用唯一的一个对象
//主席类
class Chairman {

	//1,将默认构造函数	私有化
private:
	Chairman() { cout << "Chairman构造函数调用" << endl; }
	//5.将拷贝构造函数私有化
	Chairman(const Chairman& c) {};

//public:
private: 
	//2,只要拿到一个对象的指针即可,这个指针可以指向唯一的对象
	static Chairman* singleMan;//为什么写为静态的呢:1,可以共享.2类内声明,类外初始化
	//3.我们现在将成员实行私有化,对外提供一个公共接口以避免有人将其置空
public:
	//4.将唯一的指针私有化之后,提供公共接口,变为只读状态
	static Chairman* getInstance()//这里这个static很重要
	{
		return singleMan;
	}
};


//首先这里加了作用域属于类内,可以访问私有的构造函数,然后这里在编译之后,程序运行前就已经走了这行代码了(在main函数之前)
//编译阶段就分配内存

Chairman* Chairman::singleMan = new Chairman;//理解清楚这个Chairman::的作用(堆区创建),"类内"
//不需要释放,因为仅有一个,并且一个也不会占用太多空间
void test01()
{
	//这里将构造函数私有化之后,就不可创建出多个对象了,下面的三行代码应此失效(报错)
	//Chairman c1;
	//Chairman c2;
	//Chairman* c3 = new Chairman;//在堆区创建
	//上边的三个创建实例创建方式都会用到构造函数,对应我们要把构造函数私有化(对应:一),但是我们还是需要一个对象(拿到一个唯一对象的指针即可)

	//Chairman* c1 = Chairman::singleMan;
	//Chairman* c2 = Chairman::singleMan;
	//
	////上边的静态变量是共有的,可读可写,是我们不希望的,因为一旦有人恶意置空主席,我们就找不到了
	//Chairman::singleMan == NULL;
	Chairman* c1 = Chairman::getInstance();
	Chairman* c2 = Chairman::getInstance();

	//这是不被允许的(私有化拷贝构造函数的理由)
	//Chairman* c3 = new Chairman(*c1);//这里调用拷贝构造函数,用指针来创建c3对象,通过原本的主席,克隆出了一个新主席

	if (c1 == c2)
	{
		cout << "c1 == c2" << endl;
	}
	else
	{
		cout << "c1! = c2" << endl;
	}
}

int main() {

	//会先走Chairman构造函数

	cout << "main函数调用" << endl;
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
