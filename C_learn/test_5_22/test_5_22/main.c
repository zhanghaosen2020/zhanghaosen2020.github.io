#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//���ｲ��debug��release�汾�ĳ�ȥ�ļ���С�������
//���5-23���飬release�汾�� i �� arr ������ջ���Ŀ���˳���debug�汾���ǲ�ͬ��
//int main()//x86�����¿��ٿռ�����
//{
//	int i=0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//printf("%p\n", arr);//����������ջ���Ŀ���˳��
//	//printf("%p\n", &i);
//	for (i = 0; i <= 12; i++)
//	{  
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//}

//�����ڿ��ٵĿռ�������δ��ڵģ�
//Vs�༭����С�˴洢��ʽ����λ�ڵ͵�ַ����λ�ڸߵ�ַ
//int main()
//{
//	int a = 20;
//	//00000000000000000000000000010100ԭ��
//	//0x00 00 00 14 -->16����
//	//00000000000000000000000000010100����
//	//00000000000000000000000000010100����
//	int b = -10;
//	//10000000000000000000000000001010-ԭ��
//	//0x80 00 00 0a
//	//11111111111111111111111111110101-����
//	//0xff ff ff f5
//	//11111111111111111111111111110110-����
//	//0xff ff ff f6
//	return 0;
//}


//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d\n", a, b, c);//a=-1,b=-1,c=255
//	//
//
//	char x = -128;
//	printf("x = %u\n", x);
//	printf("x = %d\n", x);
//	return 0;
//}
#include<windows.h>
//int main()
//{
//	unsigned int i;//�˴�iΪ��ʼ��
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(1000);//����1000����
//	}//�˴������Ľ������ѭ������ i = -1ʱ���������޷������͵�i֮�У�ͨ��������������Ǹ��ǳ������ 
//	return 0;
//}

//unsigned char i = 0;
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("hello world\n");
//	}
//	return 0;
//}

//int main()
//{	//size_t��strlen�ķ���ֵ���ͣ��޷�������
//	if (strlen("abc") - strlen("abcdef") >= 0)
//		printf(">\n");
//	else
//		printf("<\n");
//	return 0;
//}

//int main()
//{
//	float f = 5.5;
//	//5.5(float) = 101.1(������) = 1.011 * 2^2
//	// S=0 , M=1.011 , E=2
//	//�洢��������ʱ���ڴ� S + E + M
//	//0(S) 10000001(E+127=129) 01100000000000000000000(����1����011�������0��λ)
//	//0100  0000  1011  0000  0000  0000  0000  0000
//	//4		0	  b		0	  0     0     0     0	
//	return 0;
//}


//����ˮ����
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	int total = 0;
//	int empty = 0;
//
//	empty = money;
//	total = money;
//
//	while (empty >= 2)
//	{
//		total+= empty / 2 ;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//	return 0;
//}
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);

	total = money;
	empty = money;


	//�û�
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;//��ƿ��Ϊ��������ˮ����ʣ�µĵ�����ˮƿ��
	}

	printf("%d", total);
	return 0;
}
