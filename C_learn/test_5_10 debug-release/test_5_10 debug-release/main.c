#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = {0};
////	��ֵ
//	for (i = 0; i < 10; i++)
//	{
//		arr[i]=i;
//	}
//
////	��ӡ
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//1!+2!+3!+...+n!//n�Ľ׳�
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//
//	for (int j = 1; j <= n; j++)
//	{
//		int ret = 1;//ret��λΪ1
//		for (int i = 1; i <= j; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//} 

//������һ����ȱ�ݵĴ���

//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}//�������ѭ��
//	return 0;
//}
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;//�˴���Ϊ�˰� \0 Ҳ����
//}


//�ǳ�����д��
//#include<assert.h>
//void my_strcpy(char* dest, const char* src)
//{
//	//����
//	assert(src != NULL);
//	assert(dest != NULL);//�����������˼�ǵ���������ָ��Ϊ��ָ���ʱ����ֹ����
//
//	//���� h ��ֵ�� *dest ֵΪh��ascii��ֵ����Ϊ0�������ѭ��ֱ������ \0
//	while (*dest++ = *src++)//�����Ǹ�ֵ��䣬' \0 'asciiֵΪ0
//	{
//		;
//	}
//}

//Ϊʲô����߷��ص���char*�������ϱߵ�void����Ϊ�����Ϳ���ʵ����ʽ���ʣ�����ֵ���µĺ����Ĳ���
//strcpy���ص���Ŀ��ռ����ʼ��ַ
char* my_strcpy(char* dest, const char* src)
{
	//����
	assert(src != NULL);
	assert(dest != NULL);//�����������˼�ǵ���������ָ��Ϊ��ָ���ʱ����ֹ����
	char* ret = dest;
	//���� h ��ֵ�� *dest ֵΪh��ascii��ֵ����Ϊ0�������ѭ��ֱ������ \0
	while (*dest++ = *src++)//�����Ǹ�ֵ��䣬' \0 'asciiֵΪ0
	{
		;
	}

	return ret;
}

//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxxx";//{ 0 };
//	char arr2[] =   "hello bit";
//	my_strcpy(arr1, arr2);
//	//strcpy�ڿ����ַ�����ʱ�򣬻��Դ�ַ����е� \0 Ҳ������ȥ
//
//	printf("%s\n", arr1);
//	
//	return 0;
//}


int main()
{

	//int num = 10;
	//num = 20;
	//printf("%d\n", num);
	//���������޸�num��ֵ

	//const int num = 10;
	//num = 20;//�������num���ܱ��޸�
	//�����ƹ�const�޸�numֵ
	
	//int* p = &num;
	//*p = 20;//�����ţ�����������

	//const int* p = &num;
	//*p = 20;//���ܸ���

	//const����ָ�����
	//1��const���� * �����
	//��˼�ǣ�pָ��Ķ�����ͨ��p���ı��ˣ�����p�����ֵ(ĳ��������ĵ�ַ)�ǿ��Ըı��
//	const int num = 10;
//	const int* p = &num;
//	//*p = 20;//err
//	p = 222;//��ȷ����Ϊp����ĵ�ַ�ǿ��Ըı��

	//2��const���� * ���ұ�
	//��˼�ǣ�pָ��Ķ������ͨ��p���ı�ģ����ǲ����޸�p���������ֵ
	const num = 10;
	int* const p = &num;
	*p = 100;//���Ըı�pָ���ֵ
	//p = 99;//���ǲ������޸�p�����ֵ

	//3��*����ߺ��ұߣ�����const���ͼ���ϱ���������

	printf("%d\n", num);

	return 0;
}