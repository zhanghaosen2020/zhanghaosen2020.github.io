#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>
//���������

//����negate��һԪ���㣬�������Ƕ�Ԫ����
//�º���ԭ�ͣ�
//template<class T> T plus<T> //�ӷ��º���
//template<class T> T minus<T> //�����º���
//template<class T> T multiplies<T> //�˷��º���
//template<class T> T divides<T> //�����º���
//template<class T> T modulus<T> //ȡģ�º���
//template<class T> T negate<T> //ȡ���º���
void test01()
{
	//һԪ����
	negate<int>n;//ȥ������
	cout << n(10) << endl;

	//��Ԫ����
	plus<int>p;//����<>��ֻ��Ҫдһ��int,��Ϊ��Ԫ����ʱֻ����ͬ�����͵����ݼӼ�,Ҳ�����Դӷº����ĺ���ԭ�Ϳ�����
	cout << p(10, 40) << endl;

}


//ʵ�ֹ�ϵ�Ա�
//�º���ԭ�ͣ�
//template<class T> bool equal_to<T> //����
//template<class T> bool not_equal_to<T> //������
//template<class T> bool greater<T> //����
//template<class T> bool greater_equal<T> //���ڵ���
//template<class T> bool less<T> //С��
//template<class T> bool less_equal<T> //С�ڵ���
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(8);
	v.push_back(12);
	v.push_back(5);
	v.push_back(1);
	cout << "����ǰ:" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	sort(v.begin(), v.end());

	cout << "����֮��" << endl;
	sort(v.begin(), v.end(), greater<int>());//ͨ���ڽ�������ϵ�����,����ʵ������

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

//template<class T> bool logical_and<T> //�߼���
//template<class T> bool logical_or<T> //�߼���
//template<class T> bool logical_not<T> //�߼���

void test03()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<bool>v1;
	v1.resize(v.size());
	transform(v.begin(), v.end(),v1.begin(), logical_not<bool>());


	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main() {
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
