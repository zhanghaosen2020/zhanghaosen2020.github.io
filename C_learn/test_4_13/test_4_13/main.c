#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//goto���
//int main()
//{
//	//������ɵĹ����൱��һ����ѭ���ˣ�������ʹ��
//again:
//	printf("haha\n");
//	printf("hehe\n");
//	goto again;
//	return 0;
//}

//�ػ�����
//1����������������1min�ڹػ�
//2��������룺������   ��ȡ���ػ�
//int main()
//{
//	char input[20] = {0};
//	system("shutdown -a -t 60");
//again:
//	printf("��ע�⣬��ĵ��Խ���60���ڹػ���������룺��������ȡ���ػ���\n");
//	scanf("%s", input);
//	
//	if (strcmp(input, "������") == 0)
//	{
//		system("shutdown -a");
//		printf("�ػ�ȡ��!");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


//д�����������������ֵ
//�������ͺͷ��ص�ֵ��һ�µģ�int char ...
//int get_max(int x,int y)
//{
//	return(x > y ? x : y);
//}
//void test()//�޷���ֵ
//{
//	printf("hehe\n");
//}
////�Զ��庯��
//int main()
//{
//	int a = 0, b = 0;
//	int max = 0;
//	scanf("%d %d", &a, &b);
//	//���ú���
//	max = get_max(a, b);
//
//	printf("%d\n", max);
//	return 0;
//}

//дһ���������Խ����������α�����ֵ

//void Swap(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}

int Swap(int* px, int* py)
{
	int z = *px;
	*px = *py;
	*py = z;
}

int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	printf("����ǰ:a = %d b = %d\n", a, b);
	//a b��ʵ�����������ú������x y���βΣ��β���ʵ�ε���ʱ�������ı��βε�ֵ����ı�ʵ�ε�ֵ
	//���βε��޸Ĳ���Ӱ��ʵ��
	//Swap(a, b);//����a��b
	Swap(&a, &b);//��a��b�ĵ�ַ���ݸ�ָ�����px��py������*px =a *py=b��ӽ������ߵ�ֵ
	printf("������:a = %d b = %d\n", a, b);
	return 0;
}