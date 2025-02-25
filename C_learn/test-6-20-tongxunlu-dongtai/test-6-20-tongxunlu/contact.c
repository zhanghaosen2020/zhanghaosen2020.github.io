#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//��̬�汾
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;//�մ����õ�ͨѶ¼����Ϊ0
//	memset(pc->data,0,sizeof(pc->data));
//
//}

//��̬�汾
int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;//�մ����õ�ͨѶ¼����Ϊ0
	pc->data = (PeoInfo*)calloc(DEFAULT_SZ , sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = DEFAULT_SZ;
	return 0;
}
void DestroyContact(Contact* pc)//����ͨѶ¼(�����ڴ�)
{
	aseert(pc);
	free(pc->data);
	pc->data == NULL;
}

//��̬�汾
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	//������ϵ�˵�ǰ��������ͨѶ¼δ��
//	if (pc->count == MAX)
//	{
//		printf("ͨѶ¼�������޷������\n");
//		return;//void���Ϳ���û�з���ֵ(��ʾ�����ú���)
//	}
//	//
//	printf("����������:>");
//	scanf("%s", pc->data[pc->count].name);//��һ��Ҫ�������
//	//�����ǰ����ִ��������У��ʶ���ȡ��ַ���������������ǵ�ַ
//
//	printf("����������:>");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("�������Ա�:>");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("������绰:>");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("�������ַ:>");
//	scanf("%s", pc->data[pc->count].addr);
//	
//	pc->count++;
//	printf("���ӳɹ�\n");
//}

void CheckCapacity(Contact*pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("AddContact::%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
	}
}
//��̬�汾
void AddContact(Contact* pc)
{
	assert(pc);
	//�ռ䲻��������
	CheckCapacity(pc);
	//
	printf("����������:>");
	scanf("%s", pc->data[pc->count].name);//��һ��Ҫ�������
	//�����ǰ����ִ��������У��ʶ���ȡ��ַ���������������ǵ�ַ

	printf("����������:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("���ӳɹ�\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i=0;
	//��ӱ�ͷ(�����ʽ666)�����������
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name,
											   pc->data[i].age, 
											   pc->data[i].sex,
											   pc->data[i].tele,
											   pc->data[i].addr);
	}
}
static int FindByName(Contact* pc, char name[])//�����������Ҫ��¶��ȥ���ʶ���������
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	assert(pc);
	int i = 0;//�����ѭ������
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û��Ԫ�ؿ���ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//ɾ��
	//1.����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2.ɾ��
	for (i = pos; i < pc->count-1; i++)// -1��Ϊ�˷�ֹԽ��
	{
		pc->data[i] = pc->data[i + 1];//��Ҫɾ������һ�����ǵ�
	}
	pc->count--;//���һ��data���鲻�ᱻ�����������¼ӻᱻ����
	printf("ɾ���ɹ�");
}

void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	//1.����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	//2.��ӡ
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
												pc->data[pos].age,
												pc->data[pos].sex,
												pc->data[pos].tele,
												pc->data[pos].addr);
}

void ModifyContact(Contact* pc)//�޸�ָ����ϵ��
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	//1.����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	printf("Ҫ�޸��˵���Ϣ�Ѿ����ҵ�����������ʼ�޸�\n");
	//2.�޸ģ�����¼�룩
	printf("����������:>");
	scanf("%s", pc->data[pos].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pos].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pos].addr);
	
	printf("�޸ĳɹ�");

}


//������
int cmo_peo_by_name(const void* e1,const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
void SortContact(Contact* pc)//������ϵ��/������
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmo_peo_by_name);
	printf("����ɹ�\n");

}