#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

//1.����n�Ľ׳�

//int main()
//{
//	int n = 0;
//	printf("������n:>");
//	scanf("%d", &n);
//	int sum = 1;
//	int i = 0;//�����ⲿforѭ���ı���
//	int j = n;//��ѭ����ÿ�μ���1����n*(n-1)*(n-2)....*(1)
//	//
//	
///*	
//for (i = 1; i <= n; i++)
//	{
//		sum *= j;
//		j--;
//		if (0 == j)
//			break;//�˵�1ʱ����ѭ��
//	}
//*/
//	for (i = 1; i <= n; i++)
//	{
//		sum = sum * i;
//
//	}
//	printf("\nsum = %d", sum);
//	return 0;
//}


//2.���� 1!+2!+3!+����+10!

//int main()
//{
//	int sum = 1;
//	int i = 0;
//	int total = 0;//����
//	
//	for (i = 1; i <= 10; i++)
//	{
//		sum = sum * i;
//		total = total + sum ;
//	}
//	printf("%d", total);
//
//	return 0;
//}

// 3. ��һ�����������в��Ҿ����ĳ������n����������ֲ��ң�
//int main()
//{
//	//���ñ����ķ���ʵ��
//	int arr[] = {0,1,2,3,4,5,6,6,9,120};
//	int i = 0;
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//�������ķ�ʽ�����������ĳ���
//	printf("������Ҫ���ҵ�����:>");
//	scanf("%d", &k);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == k)
//		{
//			printf("�±�Ϊ:%d\n", i);
//			break;//�ҵ�֮�������ѭ�������û����һ�仰��ѭ���ͻ����ִ��,��ӡ��ÿһ��Ϊ������±�־
//		}
//	}
//	if (sz == i)//�ϱ߱������������飬��δ�ҵ�ָ�������ݣ���ʱ�±��Ϊsz��˵��δ���ҵ�������
//		printf("δ���ҵ�������");	
//	return 0;
//}

//�����ö��ַ���ʵ��
/*
int main()
{
	//int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int arr[] = { 0,4,6,9,10,22,77,88,99,100 };
	int sz = sizeof(arr) / sizeof(arr[0]);//�������鳤��
	int left = 0;
	int right = sz - 1;//���±�
	int k = 0;
	printf("������Ҫ���ҵ�����:>");
	scanf("%d", &k);

	int i = 0;//����ѭ������
	while (left <= right)//���ʱ��˵���м仹��Ԫ�أ����ɼ������֣�����ѭ��˵��
	{	
		int mid = (left + right) / 2; //��Ҫ������ѭ�����
		//Ϊ�˷�ֹleft + rightԽ�磬����������Ĳ���
		//mid = left + (right  - left) / 2; //���������
		if (arr[mid] < k)
		{
			left = mid + 1;//mid��Ӧ�Ĳ��ԣ�������Ϊmid+1
			//mid = (left + right) / 2;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
			//mid = (left + right) / 2;
		}
		else
		{
			printf("�ҵ��ˣ��±�Ϊ:%d", mid);
			break;
		}	
	}
	if (left > right)//
	{
		printf("�Ҳ�����");
	}	
	return 0;
}
*/

//4. ��д���룬��ʾ����ַ��������ƶ������м��ۡ�
//int main()
//{
//	char arr1[] = "welcome to bit!!!!";
//	char arr2[] = "##################";
//	int i = 0, j = 0;//�������±꼰ѭ�����Ʊ���
//	int sz = sizeof(arr1) / sizeof(arr1[0]);//���������strlen()�������ܻ��һЩ����Ϊ����������Ὣ\0ͳ�ƽ�ȥ�����������ݸ�������
//	for (i = 0; i < (sz - 1) / 2; i++)
//	{
//		arr2[i] = arr1[i];
//		arr2[sz - 2 - i] = arr1[sz - 2 - i];//��ȥ2��ӦΪ�ַ������͵����飬��ռ��һ���ռ��'\0'
//		printf("%s\n", arr2);
//	}
//	return 0;
//}
//�����Ƕ��ϱߵ��Ż�
/*
int main()
{
	char arr1[] = "welcome to bit!!!!";
	char arr2[] = "##################";
	int i = 0, j = 0;//�������±꼰ѭ�����Ʊ���
	//int sz = sizeof(arr1) / sizeof(arr1[0]);//���������strlen()�������ܻ��һЩ����Ϊ����������Ὣ\0ͳ�ƽ�ȥ�����������ݸ�������
	int sz = strlen(arr1);
	for (i = 0; i < sz / 2; i++)
	{
		arr2[i] = arr1[i];
		arr2[sz - 1 - i] = arr1[sz - 1 - i];//��ȥ2��ӦΪ�ַ������͵����飬��ռ��һ���ռ��'\0'
		printf("%s\n", arr2);
		Sleep(500);//���߰��룬�ú�����Windows.h�ṩ
		//������Ļ
		system("cls");//system()��һ��ϵͳ��������stdlib.h�ṩ
	}
	printf("%s\n", arr2);
	return 0;
}
*/

//5. ��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Ρ���ֻ���������������룬
//  ���������ȷ����ʾ��¼�ɣ�������ξ�����������˳�����)
/*
#include<string.h>
int main()
{
	char pwd[] = "zhanghaosen123";
	char pwd1[15];
	int i = 0;
	printf("����������:>");
	
	for (i = 0; i < 3; i++)
	{
		scanf("%s", pwd1);//����ط�����Ҫȡ��ַ����Ϊ�������������ǵ�ַ
		//if (pwd == pwd1)// C�����в����� == ���Ƚ��ַ����Ƿ����
		int t = strcmp(pwd, pwd1);
		if (strcmp(pwd , pwd1) == 0) 
		{
			printf("������ȷ��½�ɹ���");
			break;
		}
		else
		{
			printf("�����������������:>");

		}

	}
	return 0;
}
*/

//������С��Ϸ
//���Բ���һ�������(1~100)�����߲´��ˣ���С�ˣ�ֱ���¶ԣ�������

void menu()
{
	printf("******************************\n");
	printf("*********** 1.play ***********\n");
	printf("*********** 0.exit ***********\n");
	printf("******************************\n");
}

void game()
{	
	int guess = 0;
	//1.���������
	//RAND_MAX(32767);
	//time()��������ֵΪtime_t,������һ��ָ�루���ﴫ��һ����ָ�룩���õ���ǿ������ת��Ϊsrand()��Ҫ���޷�������
	//srand((unsigned int)time(NULL));//Sets a random starting point;void srand(unsigned int seed);,seed����������ɵ�rand�����������ʱ���
	//�ú�������һ�����ε����ֵ��0~RAND_MAX��The rand function returns a pseudorandom integer in the range 0 to RAND_MAX
	
	int ret = rand() % 100 + 1;//����ģ100������Ϊ0-99���ټ�һ������Ҫ��1-100
	//printf("%d\n", ret);//������

	//2.������
	while (1)
	{
		printf("�������:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("��С��\n");

		}
		else if (guess > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ��¶���\n");
			break;
		}
	}	
}
int main()
{
	srand((unsigned int)time(NULL));//��������ֻ��Ҫ����һ�ξͺ�
	//������Ҫ��ӡ�˵�
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				//printf("����Ϸ\n");
				game();//�����ǲ�������Ϸ���߼�
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("�����������������:>\n");
				break;
		}			
	}
	while (input);
	return 0;
}