#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

//int main()
//{
//	//FILE* pf = fopen("test.txt","r");//���·�����򿪵��ǵ�ǰ�����ļ����µ��ļ�
//	FILE* pf = fopen("C:\\Users\\Zhang\\Desktop\\test.txt", "r");//����·������ʽ����
//	//˫б����ת�嵥��б��
//	
//	//���ļ���ʧ�ܷ���NULL����Ҫ�ж�
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	//д�ļ�
//
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;//����ʧ��
//	return 0;
//}

//int main()
//{
	/*FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}*/
	//д�ļ�
	//fputc('a', pf);
	//int i = 'a';
	//for (i = 'a'; i < 'z'; i++)
	//{
	//	fputc(i, pf);//һ��дһ���ַ������д��
	//}


	//FILE* pf = fopen("test.txt", "r");
	//if (pf == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 1;
	//}
	////���ļ�
	////printf("%c\n", fgetc(pf));//˳�����ָ����Զ�����һ��λ���ƶ�����error����EOF
	//int ch = 0;
	//while ((ch = fgetc(pf))!= EOF)
	//{
	//	printf("%c ", ch);
	//}
	 
	//дһ������
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));//������ŵ��ǣ����õ����ִ�ӡ
//		perror("fopen");//���Ϊ��ӡ������Ϣ���ַ�������ʾλ��
//		return 1;
//	}
//
//	fputs("hello bit",pf);//д�ļ���ʱ�򣬻���ļ������������д���ݣ�ģʽ��Ϊa׷�ӣ�
//	//��һ������
//	char arr[20];
//	fgets(arr,10,pf);//����num-1�����ݣ���Ϊ����ĩβ����һ�� \0 
//	printf("%s\n", arr);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");//��д�ķ�ʽ���ļ�
//	if (pf == NULL)//����Ƿ񴴽��ɹ�
//	{
//		perror(fopen);
//		return 1;
//	}
//	//fputc('a',pf);//д��һ���ַ�a
//	int i = 'a';
//	for (i = 'a'; i < 'z'; i++)
//	{
//		fputc(i , pf);
//	}
//
//	fclose(pf);//�ر�ָ��
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");//��д�ķ�ʽ���ļ�
//	if (pf == NULL)//����Ƿ񴴽��ɹ�
//	{
//		perror(fopen);
//		return 1;
//	}
//	//printf("%c ", fgetc(pf));//pfָ����Զ���һ
//	//printf("%c ", fgetc(pf));
//	//printf("%c ", fgetc(pf));
//	//printf("%c ", fgetc(pf));
//	int c = 0;
//	while ((c = fgetc(pf)) != EOF)//��ȡÿһ���ַ��ķ���
//	{
//		printf("%c ", c);
//	}
//
//
//	fclose(pf);//�ر�ָ��
//	pf = NULL;
//
//	return 0;
//}

//���ļ���һ���ַ����ķ���
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");//��д�ķ�ʽ���ļ�
//	if (pf == NULL)//����Ƿ񴴽��ɹ�
//	{
//		perror(fopen);
//		return 1;
//	}
//	char str[28] = {0};//����Ŀռ�Ҫ�ȶ�ȡ�Ŀռ��
//	fgets(str, 28, pf);//����ȡʧ�ܣ��᷵��һ����ָ�롣��С-1������'\0'
//	printf("%s", str);
//
//	fclose(pf);//�ر�ָ��
//	pf = NULL;
//
//	return 0;
//}

//���ļ���д���ַ���
//int main()
//{
//	FILE* pf = fopen("test.txt", "a");//��д�ķ�ʽ���ļ�
//	if (pf == NULL)//����Ƿ񴴽��ɹ�
//	{
//		perror(fopen);
//		return 1;
//	}
//
//	fputs(" hello , haosen", pf);
//
//	fclose(pf);//�ر�ָ��
//	pf = NULL;
//
//	return 0;
//}


//fprintf���÷�
//struct Info
//{
//	char name[30];
//	int age;
//	char sex[20];
//};
//int main()
//{
//	struct Info stu = {"zhs",24,"boy"};
//	//���ļ�ָ��
//	FILE* pf = fopen("test.txt", "w");//��д�ķ�ʽ���ļ�
//	if (pf == NULL)//����Ƿ񴴽��ɹ�
//	{
//		perror("fopen");//���������һ���ַ���
//		return 1;
//	}
//	//�����ļ�
//	fprintf(pf, "%s %d %s", stu.name, stu.age, stu.sex);//pf�ǰ�����д���ļ�
//	fprintf(stdout, "%s %d %s", stu.name, stu.age, stu.sex);//stdout�ǰ����ݴ�ӡ����Ļ
//
//	fclose(pf);//�ر�ָ��
//	pf = NULL;
//
//	return 0;
//}


//�����ƵĶ���д

//struct Info
//{
//	char name[30];
//	int age;
//	char sex[20];
//};

//���İ汾
//int main()
//{
//	struct Info stu = { "zhanghaosen",50,"nan" };
//	//�������������Ϣ�Զ����Ƶ���ʽд���ļ���
//	//���ļ�
//	FILE* pf = fopen("test.txt", "wb");
//	
//	//�ж��Ƿ�򿪳ɹ�
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//�����Ƶķ�ʽд
//	fwrite(&stu, sizeof(struct Info), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//���İ汾
//int main()
//{
//	struct Info stu = { 0 };
//	//�������������Ϣ�Զ����Ƶ���ʽ���ļ���
//	//���ļ�
//	FILE* pf = fopen("test.txt", "rb");
//	
//	//�ж��Ƿ�򿪳ɹ�
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//�����Ƶķ�ʽ�Ķ�
//	fread(&stu, sizeof(struct Info), 1,  pf);
//	printf("%s %d %s", stu.name, stu.age, stu.sex);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	struct Info stu = { "zhanghaosen",23,"nan" };
//	struct Info tmp = { 0 };
//	char buff[100] = {0};
//	//��������ı����ǰѽṹ���е����ݰ���ָ����ʽ�ϲ���һ���ַ�������ŵ�����buff��
//	//��stu֮�еĸ�ʽ������ת�����ַ����ŵ�buff֮��
//	sprintf(buff, "%s %s %d", stu.name, stu.sex,stu.age);//�������Ӧ�������ʽһ�����ܴ�
//	//"zhanghaosen nan 23"
//	printf("�ַ�����%s\n", buff);//��һ����ʽ������ת�����ַ���
//
//	sscanf(buff,"%s %s %d", tmp.name, tmp.sex, &(tmp.age));
//	printf("��ʽ����%s %s %d\n", tmp.name, tmp.sex, tmp.age);
//	//���ַ���buff�л�ȡһ����ʽ�����ݵ�tmp֮��
//	return 0;
//}

int main()
{
	FILE* pf = fopen("test.txt", "r");//��д�ķ�ʽ���ļ�
	if (pf == NULL)//����Ƿ񴴽��ɹ�
	{
		perror(fopen);
		return 1;
	}
	//���ļ�
	//��λ�ļ�ָ��
	fseek(pf, 3, SEEK_SET);
	int ch = fgetc(pf);
	printf("%c", ch);

	fclose(pf);//�ر�ָ��
	pf = NULL;

	return 0;
}