#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�ṹ��	��һЩ��һ���������һ�������

//����һ��ѧ��
struct Stu
{
	//������ǽṹ��ĳ�Ա
	char name[20];
	int age;
	char sex[10];
	char tele[12];
};

//ps�д�ŵ��ǽṹ�����s1�ĵ�ַ
void print(struct Stu* ps)//����±ߣ�����s1�ĵ�ַ��psָ�������s1��һ���ṹ�����ͱ���
{
	//���ִ�ӡ��ʽ
	// *ps������ psָ����� ����Ӧ�ı�������struct Stu ����s1   ����ָ��s1��ע�����Ų���ʡ��
	printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).tele);//

	//ps->,ָ����ps��ָ������Ǹ���Աname
	//  �ṹ���ָ����� -> ��Ա��
	printf("%s %d %s %s\n", ps->name ,ps->age,ps->sex ,ps->tele);
}
int main()
{
	struct Stu s1 = {"zhangsan",24,"nan","123456789"};
	//�ṹ������������ߵĳ�Ա�õ��� .������
	//�ṹ�����.��Ա��
	printf("%s %d %s %s\n", s1.name, s1.age, s1.sex, s1.tele);//��ӡ����Ҫһһ��Ӧ
	print(&s1);
	return 0;
}