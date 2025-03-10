#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//基类
class Base1 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//父类中公共权限成员,在子类中依然为公共权限
		m_B = 10;//父类中保护权限成员,在子类中依然为保护权限
		//m_C = 10;//父类中的私有权限成员,子类访问不到
	}
};

class Son2 :protected Base1 {

};


int main() {

	system("pause");
	return EXIT_SUCCESS;
}
