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
	//01,using����,˵����������Ҫ�õ������ռ�LOL�е�sunWuKongId,�����ӱ������Ͳ��ᱨ����
	using LOL::sunWuKongId;
	//�ͽ�ԭ��������ռ�ͬʱ����ʱ,���������Ӧ������,����ɶ�����,��������ע�͵�
	//����C2874using �������¶��������sunWuKongId��

	cout << sunWuKongId << endl;
}

namespace kingGlory
{
	int sunWuKongId = 4;
}
void test02()
{
	//int sunWuKongId = 3;
	//2,using����ָ��
	using namespace LOL;//������˼���ϱ���Щ����,���÷�Χ���ӹ���,ֻҪ�����������Id,�Ϳ���ʹ��
	using namespace kingGlory;
	//test01�ϱߵ�using LOL::sunWuKongId;������ʽ���������С,ֻ��������LOL����������Id
	//��ʹ�ö������ָ��,���ҳ���ͬ�����,ʹ��������Ҫ��������,�����������ֻ֪������һ���������Id
	cout << LOL::sunWuKongId << endl;
	cout << kingGlory::sunWuKongId << endl;
	//���������Ϊ��ֻ�ܴ��˾ͽ�ԭ��?   ֱ�ӿ��ú�ȥ���������,ǰ�߸��Ӽ�
}



int main() {

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
