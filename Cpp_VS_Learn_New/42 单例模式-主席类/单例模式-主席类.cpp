#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//����ģʽ,ͨ��һ����ֻ��ʹ��Ψһ��һ������
//��ϯ��
class Chairman {

	//1,��Ĭ�Ϲ��캯��	˽�л�
private:
	Chairman() { cout << "Chairman���캯������" << endl; }
	//5.���������캯��˽�л�
	Chairman(const Chairman& c) {};

//public:
private: 
	//2,ֻҪ�õ�һ�������ָ�뼴��,���ָ�����ָ��Ψһ�Ķ���
	static Chairman* singleMan;//ΪʲôдΪ��̬����:1,���Թ���.2��������,�����ʼ��
	//3.�������ڽ���Աʵ��˽�л�,�����ṩһ�������ӿ��Ա������˽����ÿ�
public:
	//4.��Ψһ��ָ��˽�л�֮��,�ṩ�����ӿ�,��Ϊֻ��״̬
	static Chairman* getInstance()//�������static����Ҫ
	{
		return singleMan;
	}
};


//�������������������������,���Է���˽�еĹ��캯��,Ȼ�������ڱ���֮��,��������ǰ���Ѿ��������д�����(��main����֮ǰ)
//����׶ξͷ����ڴ�

Chairman* Chairman::singleMan = new Chairman;//���������Chairman::������(��������),"����"
//����Ҫ�ͷ�,��Ϊ����һ��,����һ��Ҳ����ռ��̫��ռ�
void test01()
{
	//���ｫ���캯��˽�л�֮��,�Ͳ��ɴ��������������,��������д���Ӧ��ʧЧ(����)
	//Chairman c1;
	//Chairman c2;
	//Chairman* c3 = new Chairman;//�ڶ�������
	//�ϱߵ���������ʵ��������ʽ�����õ����캯��,��Ӧ����Ҫ�ѹ��캯��˽�л�(��Ӧ:һ),�������ǻ�����Ҫһ������(�õ�һ��Ψһ�����ָ�뼴��)

	//Chairman* c1 = Chairman::singleMan;
	//Chairman* c2 = Chairman::singleMan;
	//
	////�ϱߵľ�̬�����ǹ��е�,�ɶ���д,�����ǲ�ϣ����,��Ϊһ�����˶����ÿ���ϯ,���Ǿ��Ҳ�����
	//Chairman::singleMan == NULL;
	Chairman* c1 = Chairman::getInstance();
	Chairman* c2 = Chairman::getInstance();

	//���ǲ��������(˽�л��������캯��������)
	//Chairman* c3 = new Chairman(*c1);//������ÿ������캯��,��ָ��������c3����,ͨ��ԭ������ϯ,��¡����һ������ϯ

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

	//������Chairman���캯��

	cout << "main��������" << endl;
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
