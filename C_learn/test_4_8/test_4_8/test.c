#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//�ַ������
//int main()
//{
//	//'a',�����������������ַ�����
//	//C������û���ַ������������ͣ������Խ��ַ�������һ��������
//	char arr[] = "asdfgh";//�ַ����Ľ�β�ԡ�\0��Ϊ������־Ҳ��ռ��һ���ռ� ,��ӡʱ��������ֹ��־ //7
//	char arr2[] = {'a','b','c','d','e','f'};//û����\0ռλ��ռ6���ַ��ռ�
//	//char arr2[] = { 'a','b','c','d','e','\0' };//û����\0ռλ��ռ6���ַ��ռ�
//	printf("%s\n",arr);
//	printf("%s\n", arr2);
//	int len = strlen(arr);//strlenͳ���ַ������ȵ�ʱ�����\0Ϊ�ָ��������볤��
//	printf("%d\n",len);
//	printf("%d\n", strlen(arr2));
//	return 0;
//}


//ת���ַ�(��ת���ַ�����˼)
//int main()
//{
//	printf("abc\n");
//	printf("abcn\n");
//
//	printf("abc\0df\n");
//	//printf("abc0df\n");
//
//	return 0;
//}


//����ת���ַ�
//����ĸ�� �磺??) --> ]  \   ??(  --> [ һЩ���ϵı������Ὣ������Ž�������������

//%d - ��ӡ����
//%c - ��ӡ�ַ�
//%s - ��ӡ�ַ���
//%f - ��ӡ��������float�� %lf - ��ӡdouble
//%zu - ��Ӧsizeof�ķ���ֵ
//int main()
//{	
//	printf("%c\n",'\'');//  \'������Ժ�'''���ֿ�
//	printf("%s\n", "\"");//  \"������Ժ�"""���ֿ�
//	printf("abc\\0df\n");//  \\������
//	printf("c:\test\test.c\n");//��ӡ·��ʱ��\t�����ַ��ᱻ���Ϊ�Ʊ��
//	printf("c:\\test\\test.c\n");//��˲ſ��Դ�ӡ����\td�ĵ�ַ
//	printf("\a");//ϵͳ����һ��
//	
//	
//	printf("%c\n",'\130');// \\  \ddd��ʾ��ddd����İ˽�������ת��Ϊʮ���ƶ����Ӧ��ascii�����ӡ����
//	printf("%c\n", '\x60');// \\ \xdd��ʾ��dd�����ʮ����������ת��Ϊʮ���ƺ��Ӧ��ascii�����ӡ����
//	
//	//printf("%d\n", strlen("c:\test\628\test.c"));
//	int len = strlen("c:\test\628\test.c");
//	printf("len = %d\n", len);//  len = 14
//
//	printf("c:\test\628\test.c\n");
//	return 0;
//}



//ѡ������ѭ�����
//ѡ�����
//int main()
//{
//	int input = 0;
//	printf("�������\n");
//	printf("Ҫ�ú�ѧϰ��(0/1)��\n");
//	scanf("%d",&input);
//	if (input == 1)
//	{
//		printf("��offer��\n");
//	}
//	else
//	{
//		printf("������\n");
//	}
//	return 0;
//}

//ѭ�����
//int main()
//{
//	int line = 0;
//	printf("������س���ѧϰ");
//	while (line <= 20000)
//	{
//		printf("д������%d\n", line);
//		line++;
//	}
//	if (line >= 20000)
//	{
//		printf("��ϲ���������������۷壡");
//	}
//	else
//	{
//		printf("�군��Ҫ��������Ŭ��");
//	}
//
//	return 0;
//}

////���⺯��
//Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int x, y;
//	printf("�������������ÿո������\n");
//	scanf("%d %d", &x, &y);
//	printf("sum = %d\n", Add(x, y));
//	return 0;
//}

//����
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};//������һ������   ���һ����ͬ���͵���

	printf("%d\n",arr[8]);
	int i = 0;
	while ( i < 10 )
	{
		printf("%d ", arr[i]);
		i++;
	}
	return 0;
}