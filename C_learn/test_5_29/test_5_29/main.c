#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//int test(const char* str)
//{
//	printf("test()\n");
//	return 0;
//}
//int main()
//{
//	//����ָ��--Ҳ��һ��ָ�룬��ָ������ָ��
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	//&�������ͺ��������Ǵ���ú����ĵ�ַ
//
//	//���ڳ��԰Ѻ�����ַ�����������Ҫ�õ�����ָ��
//	int(*pf)(const char*) = test;//pfָ��ĺ����Ĳ��������� const char*
//	(*pf)("abc");//�˴���*���Բ�д������д�˾ͱ����������pf��һ��
//	//������pf��test��һ������
//	pf("abcd");//����дҲ����ȷ�ģ����ϱߵĸ���࣬�����ϱߵĸ��������(�����������)
//
//	//int len = sizeof(&test);
//	//printf("%d", len);//x86�£�lenΪ4
//	return 0;
//}


//����ָ�����;

//дһ��������
//�ӷ����������˷�������
//����ʵ�ַ�ʽ�����ص�����(����)
//����ָ��ǳ���ţŶ��������
//void menu()
//{
//	printf("****************************\n");
//	printf("****	1.add	2.sub	****\n");
//	printf("****	3.mul	4.div	****\n");
//	printf("****	0.exit		****\n");
//	printf("****************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
// int Div(int x, int y)
//{
//	return x / y;
//}
//
// void calc(int(*pf)(int, int))
// {
//	 int x = 0;
//	 int y = 0;
//	 int ret = 0;
//	 printf("������2��������:>");
//	 scanf("%d %d", &x, &y);
//	 ret = pf(x, y);
//	 printf("%d\n",ret);
// }
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 0:
//			printf("�˳�������\n");
//			break;
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//
////int main()
////{
////	int input = 0;
////	int x = 0;
////	int y = 0;
////	int ret = 0;
////	do 
////	{
////		menu();
////		printf("��ѡ��:>");
////		scanf("%d", &input);
////
////		switch (input)
////		{
////		case 0:
////			printf("�˳�������\n");
////			break;
////		case 1:
////			printf("������2��������:");
////			scanf("%d %d", &x, &y);
////			ret = Add(x, y);
////			printf("%d\n", ret);
////			break;
////		case 2:
////			printf("������2��������:");
////			scanf("%d %d", &x, &y);
////			ret = Sub(x, y);
////			printf("%d\n", ret);
////			break;
////		case 3:
////			printf("������2��������:");
////			scanf("%d %d", &x, &y);
////			ret = Mul(x, y);
////			printf("%d\n", ret);
////			break;
////		case 4:
////			printf("������2��������:");
////			scanf("%d %d", &x, &y);//�кܶ������
////			ret = Div(x, y);
////			printf("%.2f\n", ret);
////			break;
////		default:
////			printf("ѡ�����\n");
////			break;
////		}
////	} while (input);
////	return 0;
////}




//����ָ�����飬��ʵ���Ǵ�ź���ָ�������
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
// int Div(int x, int y)
//{
//	return x / y;
//}
//
// int main()
// {
//	 int(*pf)(int, int) = Add;//pf�Ǻ���ָ��
//	 //����ָ������
//	 //����һ������arr[4],ÿ������Ԫ������Ϊ����ָ������
//	 int(*arr[4])(int, int) = { Add,Sub,Mul,Div };//arr���Ǻ���ָ�������
//	 int i = 0;
//	 for (i = 0; i < 4; i++)
//	 {
//		int ret = arr[i](8, 4);
//		printf("%d\n", ret);
//	 }
//
//	return 0;
// }

//x&y,x^y,x|y,x||y,x&&y,x>>y,x<<y;

//void menu()
//{
//	printf("****************************\n");
//	printf("****	1.add	2.sub	****\n");
//	printf("****	3.mul	4.div	****\n");
//	printf("****	0.exit		****\n");
//	printf("****************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
// int Div(int x, int y)
//{
//	return x / y;
//}
//
// int main()
// {
// 	int input = 0;
// 	int x = 0;
// 	int y = 0;
// 	int ret = 0;
//
//    //��Ϊ�˴�ʹ���˺���ָ������飬����ļ��˴��룬�������˺����Ż�
//    //ת�Ʊ�(����ָ�������)
//    int(*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
// 	do 
// 	{
// 		menu();
// 		printf("��ѡ��:>");
// 		scanf("%d", &input);
//        if (input == 0)
//        {
//            printf("�˳�������\n");
//        }
//        else if (input >= 1 && input <= 4)
//        {
//            printf("������2��������:");
//            scanf("%d %d", &x, &y);
//            ret = pfArr[input](x, y);
//            printf("%d\n", ret);
//        }
//        else
//        {
//            printf("ѡ�����\n");
//        }		
// 	} while (input);
// 	return 0;
// }



//�ع�һ��ð������
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	int flag = 1;//���������Ѿ��ź�����ˣ������ٴ��ظ�
	//ȷ������(������Ԫ�ظ���-1)
	for (i = 0; i < sz - 1; i++)
	{
		//����ÿ�����ж��ٴ������Ƚ�
		int j = 0;
		for(j=0;j<sz-1-i;j++)//(ÿ�˱Ƚϴ���)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}

}

//C���Կ���ߵĿ���������(�ص�����)
//qsort-�����������������͵�����
//void qsort(void* base,//��Ҫ��������ݵ���ʼλ�ã����������������Ԫ�ص�ַ
//		   size_t num,//�����������Ԫ�ظ���
//		   size_t width,//�����������Ԫ�صĴ�С(��λ���ֽ�)
//		   int(__cdecl* compare)(const void* elem1, const void* elem2)// -��һ���ȽϺ������ĸ����������һ���Ǻ���ָ��
//		  );
//__cdecl��cdecl����Լ����ζ�ţ�
//������������ѹ���ջ
//�����߸��������ջ
//C����Լ���������Ĳ����ĸ����ǲ��̶��ģ���Ҳ��C���Ե�һ����ɫ��
//���ں�����ǰ����һ���»���ǰ׺����ʽΪ_functionname��

//void*���͵�ָ��Ϊ���ͣ���û��ȷ�������ͣ�ʲô���Ͷ��������ɣ����Ե���ʱӦ��ǿ������ת���ٽ�����
int compare_int(void* elme1, void* elme2)
{
	return (*(int*)elme1 - *(int*)elme2);//��Ϊ�Ƚϵ������Σ���Ҫ������
}
void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	//�������ų�����
	int sz = sizeof(arr) / sizeof(arr[0]);//��������Ԫ��
	//bubble_sort(arr, sz);
	qsort(arr, sz, sizeof(arr[0]), compare_int);

	//��ӡ����������Ԫ��
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
struct Stu
{
	char name[20];
	int age;
};
int cmp_stu_by_name(const* e1, const* e2)
{
	//return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
	//���ַ����Ƚ���Ҫ�õ�strcmp()����
	return strcmp((*(struct Stu*)e1).name , (*(struct Stu*)e2).name);
	//return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);//����Ҳ�ǶԵ�

}
void test2()
{
	//ʹ��qsort������ṹ������
	struct Stu s[] = { {"zhangsan",15},{"lisi",30},{"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);

}
int main()
{
	//test1();
	test2();
	return 0;
}