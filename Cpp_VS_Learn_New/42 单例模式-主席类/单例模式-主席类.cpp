#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//����ģʽ,ͨ��һ����ֻ��ʹ��Ψһ��һ������
//��ϯ��
class Chairman {

	//1,��Ĭ�Ϲ��캯��	˽�л�
private:
	Chairman() {}
public:
	//2,ֻҪ�õ�һ�������ָ�뼴��,���ָ�����ָ��Ψһ�Ķ���
	static Chairman* singleMan;
};

Chairman* Chairman ::singleMan=new Chairman;

void test01()
{
	//Chairman c1;
	//Chairman c2;
	//Chairman* c3 = new Chairman;//�ڶ�������

}

int main() {

	system("pause");
	return EXIT_SUCCESS;
}
