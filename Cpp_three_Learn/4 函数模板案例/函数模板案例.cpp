#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//ʵ��һ��ͨ�õ�,�������������ĺ���
//����Ӵ�С,�㷨->ѡ��
//���� char����,int����

template<typename T>//����һ��ģ��,���߱�������������н����ŵ�T��Ҫ����
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//�����㷨
template<class T>
void mySort(T arr[], int len)//lenΪ���鳤��
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//�϶����ֵ���±�
		for (int j = i + 1; j < len; j++)
		{
			//�϶��������ֵ�ȱ������������ֵ�±�ҪС,˵������������j�±��Ӧ��Ԫ�ز�Ϊ���ֵ
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)//����
		{
			//������Ӧ�±��Ԫ��
			mySwap(arr[max], arr[i]);
		}
	}
}

//�ṩһ����ӡ����ģ��
template<class T>
void printArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void test01()
{
	//����char����
	char charArr[] = "dhifshiefh";
	int len = sizeof(charArr) / sizeof(charArr[1]);
	mySort(charArr, len);
	printArr(charArr, len);
}

void test02()
{
	int arrInt[] = { 1,2,42,4,21,4,234,234,234,2,232,1,2,5,643,3 };
	int len = sizeof(arrInt) / sizeof(arrInt[1]);
	mySort(arrInt, len);
	printArr(arrInt, len);
}

int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
