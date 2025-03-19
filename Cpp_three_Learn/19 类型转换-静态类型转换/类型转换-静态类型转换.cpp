#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1,静态类型转换 static_cast
//用于基本数据类型之间的转换，如把int转换成char，把char转换成int。这种转换的安全性也要开发人员来保证。
void test01() 
{
	//对于内置数据类型的转换
	//语法是:static_cast<目标类型>(原变量/对象)
	char a = 'a';
	double d = static_cast<double>(a);//static_cast<目标类型>(原变量/对象)//强制类型转换运算符 <要转换到的类型> (待转换的表达式)
	cout << d << endl;
}

/*父类引用指向子类对象：这是合法的，因为子类继承了父类的特性，所以可以用父类引用指向子类对象。
子类引用指向父类对象：这是非法的，因为子类可能有额外的属性和方法，而父类对象没有这些内容，所以不能直接用子类引用指向父类对象。*/
//2,用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换。即继承中的 父-->子(安全),反之不安全
class Base{ virtual void Print() = 0; };
class Son :public Base { virtual void Print() {} };
class Other {
	virtual void Print() = 0
	{}
};
void test02()
{
	Base* base = NULL;
	Son* son = static_cast<Son*>(base);//父类指针转换为子类指针,这是安全的
	
	Base* base1 = static_cast<Base*>(son);//子类转父类,不安全

	//将base1装换为Other*		(这类转换是无效的,因为这两个类之间是没有的关联的)

	//Other* other1 = static_cast<Other*>(base1);//会直接报错,无效类型转换
}

//父子继承关系,引用的转换
void test03()
{
	//Base base;
	Son son;
	//Base& base1 = base;
	Son& son1 = son;
	//向下(父转子)(不安全)
	//Son& son12 = static_cast<Son&>(base);
}


//dynamic_cast主要用于类层次间的上行转换和下行转换；
//在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；
//在进行下行转换时，dynamic_cast具有类型检查的功能，比static_cast更安全；
void test04()
{
	Base* base = NULL;
	Son* son = NULL;
	//上行转换（安全）
	Base* base1 = dynamic_cast<Base*>(son);
	
	//下行转换(不安全)
	//Son* son1 = dynamic_cast<Son*>(base1);//报错

	//但是如果发生了多态上边的转换关系,就总是成立的(上转下,下转上)

	/*多态的启动：虚函数的存在使得对象具有多态性，虚函数表（vtable）和虚函数指针（vptr）记录了对象的实际类型信息。
		dynamic_cast 的运行时检查：利用虚函数表中的类型信息，dynamic_cast 可以判断父类指针是否可以安全地转换为子类指针。*/
	Base* base3 = new Son;//父类指针指向了子类对象(已然发生了多态),所以就相当于自己和自己之间的转换,所以不会报错
	Son* son3 = dynamic_cast<Son*>(base3);

}


//const_cast
void test05()
{
	const int* p = NULL;
	int* pp = const_cast<int*>(p);//p是一个常量指针,指向的内容是一个常量不可更改,现在可以将其转换为一个非常量指针pp,pp指向的内容是可变的了

	const int* ppp = const_cast<const int*>(pp);//此时是将上述操作反过来,将非常量指针转化为常量指针

	int a = 10;
	int& b = a;
	const int& b_ref = const_cast<const int&>(b);

	//int& b_ref1 = const_cast<const int&>(b_ref);
}



int main() {
	test01();
	test02();
	test03();
	test04();
	test05();
	system("pause");
	return EXIT_SUCCESS;
}
