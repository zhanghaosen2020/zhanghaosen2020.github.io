#define _CRT_SECURE_NO_WARNINGS
/*
ʵ��һ��ͨѶ¼���˵���Ϣ���������֣����䣬�Ա𣬵绰����ַ
Ҫ�󣺴��100���˵���Ϣ����ɾ�����ϵ�ˣ�������ʾ��ϵ��
test.c    ���Թ���
contact.c ͨѶ¼���ʵ��
contact.h ͨ��¼�������
*/
#include "contact.h"
enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
	//Ĭ������ֵ�ģ��Ż��˴���
};
void menu()
{
	printf("*************************************\n");
	printf("******  1.add         2.del    ******\n");
	printf("******  3.search      4.modify ******\n");
	printf("******  5.show        6.sort   ******\n");
	printf("******  0.exit                 ******\n");
	printf("*************************************\n");


}
int main()
{
	int input = 0;

	Contact con;//ͨѶ¼
	//��ʼ��ͨѶ¼
	InitContact(&con);//�ṹ�崫�Σ���ַ����
	do
	{
		menu();//���ײ˵�
		printf("��ѡ��:>");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}