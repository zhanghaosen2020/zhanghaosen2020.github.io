#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//Java页面
//class Java
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//	void left()
//	{
//		cout << "Java,Python,C++...(公共分类列表)" << endl;
//	}
//	void content()
//	{
//		cout << "JAVA学科视频" << endl;
//	}
//};
//
//class Python
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//	void left()
//	{
//		cout << "Java,Python,C++...(公共分类列表)" << endl;
//	}
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};

//void test01()
//{
//	//Java页面
//	cout << "Java下载视频页面如下： " << endl;
//	Java ja;
//	ja.header();
//	ja.footer();
//	ja.left();
//	ja.content();
//	cout << "--------------------" << endl;
//	//Python页面
//	cout << "Python下载视频页面如下： " << endl;
//	Python py;
//	py.header();
//	py.footer();
//	py.left();
//	py.content();
//	cout << "--------------------" << endl;
//}

//用继承来实现页面

//公共页面类
class BasePage {
public:
	void header()
		{
			cout << "首页、公开课、登录、注册...（公共头部）" << endl;
		}
		void footer()
		{
			cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
		}
		void left()
		{
			cout << "Java,Python,C++...(公共分类列表)" << endl;
		}
};
//Java页面
class Java :public BasePage {
public:
	void content()
	{
		cout << "Java学科视屏" << endl;
	}
};

//继承的好处在于:减少重复的代码
//语法:class 子类 :继承方式  父类
//子类也称为派生类,父类也称为基类

class CPP :public BasePage {
public:
	void content()
	{
		cout << "CPP学科视屏" << endl;
	}
};


void test01()
{
	//Java页面
	cout << "Java下载视频页面如下： " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;
	//Python页面
	cout << "CPP下载视频页面如下： " << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
	cout << "--------------------" << endl;
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
