#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//��֧if-else��switch  ��  ѭ�����while   for   do while
//int main()
//{
//	//if-else���ע�⣬Ĭ������ִֻ��һ�������Ҫִ�ж�����䣬��Ҫ{}������
//	//���ɹ淶�Ĵ�����д��ʽ
////������δ��벻�����κε�ִ�н����elseֻ�������ifƥ�� ����{}���������Ķ�
////    int a = 0;
////    int b = 2;
////    if (a == 1)
////    {
////        if (b == 2)
////            printf("hehe\n");
////        else
////            printf("haha\n");
////    }
////
//////1������������(�����塢�淶)
////    char frist_name[20];
////    char FristName[20];
//////2���ո񡢿��С�����
////    int a = 10;// = �����пո�
//
//
//	// ��ϰ 2.1.3
//	//int i = 1;
//	//while (i <= 100)
//	//{
//	//	if (0 != (i % 2))
//	//	{
//	//		printf("%d ", i);
//	//	}
//	//	i++;
//	//}
//
//
//	//switch���ڶ���֧���
//	int day = 0;
//	scanf("%d", &day);
//
///*	switch (day)//switch��Ҫ�����α���(����������)��������α���֮����case����ڣ������caseҲ��ִ��
//	{
//	case 1://case����������ͳ������ʽ 1��2��3��
//		printf("����1\n");
//		break;
//	case 2://�Ÿ��ַ�Ҳ���ԣ���Ϊ�ַ���������һ��ascii��ֵΪ���γ���
//		printf("����2\n");
//		break;
//	case 3:
//		printf("����3\n");
//		break;
//	case 4:
//		printf("����4\n");
//		break;
//	case 5:
//		printf("����5\n");
//		break;
//	case 6:
//		printf("����6\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	}
//*/
//
//	//����������ˣ�����1~5��weekday6~7weekend
//	switch (day)//���˴��룬break���߼�Ҫ��ʹ�ø��ӷ���
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;//������ϣ��߼��Ͽ��Բ���
//	default:
//		printf("ѡ�����");
//		break;
//	}
//	return 0;
//}


//ѭ�����
//int main()
//{
//	//1.whileѭ�� //continue ����������������ѭ����ߵĴ��룬ֱ��ȥ�жϽ�����һ��ѭ�����ж�
//	//��ӡ1~10
//	int i = 1;
//	while (i <= 10)
//	{
//		if (5 == i)
//			break;//�����仰����˼�ǵ�i==5��ʱ������ѭ������ӡ��1~4
//				//break�����������
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

int main()
{
	//int ch = 0;
	//ch = getchar();//getchar()�����õ����Ǽ��������ascii��ֵ������ֵ��int���͵ģ������ô�ӡ������ӡ����
	//printf("%c\n", ch);//%c��ӡ��ch��ֵ��Ӧ���ַ�(ascii)

	//int ch = 0;
	//while ((ch = getchar()) != EOF)
	//{
	//	putchar(ch);//����һ���ַ���һ���س������뻺��������������ַ���getcharһ��ֻ��һ����a != EOF putchar��һ����
	//	//��һ��ѭ���� \n ,�Ž�����һ�ΰ��ַ��ӻس����ѭ��
	//}


	//�ٸ�����(���뻺�����е�\n���ո�)
	//����������һ���ַ���
	char password[20] = { 0 };
	printf("����������:>");
	scanf("%s", password);//�������������һ����ַ��������ﲻ��ȡ��ַ��

	//getchar();//�˴���ȡ�� \n   �򵥵�������һ���ֻ���
	int ch = 0;
	while ((ch = getchar()) != '\n')//����һ������
	{
		;
	}


	printf("��ȷ������(Y/N):>");
	int ret = getchar();
	if ('Y' == ret)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}



	return 0;
}