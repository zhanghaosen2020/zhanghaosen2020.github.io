#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>




void printList(list<int>& l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}


//list�Ĺ��캯��
//list<T> lst; //list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
//list(beg, end); //���캯����[beg, end)�����е�Ԫ�ؿ���������
//list(n, elem); //���캯����n��elem����������
//list(const list& lst); //�������캯����
void test01()
{
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	printList(l);
	
	list<int>l1(l.begin(), l.end());
	printList(l1);

	list<int>l2(10, 9);
	printList(l2);

	list<int>l3(l2);
	printList(l3);
}

//assign(beg, end); //��[beg, end)�����е����ݿ�����ֵ������
//assign(n, elem); //��n��elem������ֵ������
//list& operator=(const list& lst); //���صȺŲ�����
//swap(lst); //��lst�뱾���Ԫ�ػ�����

//��ֵ����
void test02()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	printList(l);

	list<int>l1;
	l1.assign(l.begin(), l.end());
	printList(l1);

	l1.assign(10, 2);
	printList(l1);

	l.swap(l1);

	printList(l);
	l1 = l;
	printList(l1);


}

//size(); //����������Ԫ�صĸ���
//empty(); //�ж������Ƿ�Ϊ��
//resize(num); //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
////���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//resize(num, elem); //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
////���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

void test03()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	if (L1.empty())
	{
		cout << "L1Ϊ��" << endl;
	}
	else
	{
		cout << "L1Ϊ��Ϊ��" << endl;
		cout << "L1�Ĵ�С(Ԫ�ظ���)Ϊ��"<<L1.size() << endl;

	}

	L1.resize(9,0);
	cout << "L1.resize(9)֮��Ĵ�СΪ��" << L1.size() << endl;
	printList(L1);

	L1.resize(2);
	cout << "L1.resize(9)֮��Ĵ�СΪ��" << L1.size() << endl;
	printList(L1);
}

//push_back(elem);//������β������һ��Ԫ��
//pop_back();//ɾ�����������һ��Ԫ��
//push_front(elem);//��������ͷ����һ��Ԫ��
//pop_front();//��������ͷ�Ƴ���һ��Ԫ��
//insert(pos, elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�//pos��λ��,���ǵ�����
//insert(pos, n, elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
//insert(pos, beg, end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
//clear();//�Ƴ���������������
//erase(beg, end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
//erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
//remove(elem);//ɾ��������������elemֵƥ���Ԫ��

void test04()
{
	list<int>L;
	//β��
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	
	//ͷ��
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	//βɾ
	L.pop_back();

	//ͷɾ
	L.pop_front();

	//insert��ʽ����
	//L.insert(L.begin(),1000);
	list<int>::iterator it = L.begin();//�ȴ���һ��������
	L.insert(++it, 1000);

	//ɾ��
	it = L.begin();
	L.erase(++it);

	L.push_back(10000);
	L.push_back(10000);
	L.push_back(10000);
	L.push_back(10000);

	printList(L);


	//�Ƴ�ָ������
	L.remove(10000);


	printList(L);

}


//front(); //���ص�һ��Ԫ�ء�
//back(); //�������һ��Ԫ�ء�
void test05()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);


	//ͷβ�ӿ�
	cout << "L1�ĵ�һ��Ԫ��Ϊ:" << L1.front()<<endl;
	cout << "L1��ĩβ��Ԫ��Ϊ:" << L1.back()<<endl;
	/*���Ǻ�list�ĵײ�ʵ����ص�(�洢�����������Ŀռ���), ������ֻ֧��ǰ���ƶ�һλ;*/

	//��֤�������ǲ�֧��������ʵ�
	list<int>::iterator it = L1.begin();
	it++;
	//it += 5;�б�������ǲ�����Ծ���ʵ�,�������ϱ�����
}

//list�����ķ�ת������

bool myCompare(int v1,int v2)
{
	//����,���õ�һ�������ڵڶ�����
	return v1 > v2;
}

void test06()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(4);
	l.push_back(1);

	l.push_back(30);
	l.push_back(40);
	cout << "������תǰ: " << endl;
	printList(l);
	l.reverse();
	cout << "������ת��: " << endl;
	printList(l);

	cout << "��������ǰ: " << endl;
	printList(l);
	cout << "���������: " << endl;
	//���в�֧��������ʵ�����������,�������ñ�׼���㷨
	//��֧��������ʵ�����������,�ڲ����ṩһЩ��Ա����(һЩ�㷨)
	l.sort();//����
	printList(l);

	l.sort(myCompare);//����


	printList(l);


}

int main() {
	//test01();
	//test02();

	//test03();

	//test04();
	//test05();

	test06();
	system("pause");
	return EXIT_SUCCESS;
}
