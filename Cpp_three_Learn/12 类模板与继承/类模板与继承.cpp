#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��ģ����̳еĹ�ϵ
//������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
//�����ָ�����������޷�����������ڴ�
//��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��

template<class T>
class Base {//����
public:
	T m;
};

//class Son1 :public Base//�˴��ᱨ��,ȱ����ģ��Ĳ����б�,���ұ������޷�֪���ø��������������ڴ�
//{
//
//};

class Son2 :public Base<int>//������ָ�������б�֮��,����������֪��,���������������Ŀռ���
{

};

//���ϱ�����ָ������Ĳ�������֮��,�����ʹ�����ļ̳б�þִ�,������ǿ��Լ���ʹ��ģ��
template<class T1,class T2>
class Son3 :public Base<T2> {
public:
	Son3()
	{
		cout << "T1������Ϊ: " << typeid(T1).name() << endl;
		cout << "T2������Ϊ: " << typeid(T2).name() << endl;
	}
	T1 m;
};

void test01()
{
	Son3<int,char> s;//char-->T2(Son3�е�)-->T(Base�е�)
}

int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}
