#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//静态版本
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;//刚创建好的通讯录人数为0
//	memset(pc->data,0,sizeof(pc->data));
//
//}

//动态版本
int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;//刚创建好的通讯录人数为0
	pc->data = (PeoInfo*)calloc(DEFAULT_SZ , sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = DEFAULT_SZ;
	return 0;
}
void DestroyContact(Contact* pc)//销毁通讯录(回收内存)
{
	aseert(pc);
	free(pc->data);
	pc->data == NULL;
}

//静态版本
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	//增加联系人的前提条件是通讯录未满
//	if (pc->count == MAX)
//	{
//		printf("通讯录已满，无法再添加\n");
//		return;//void类型可以没有返回值(表示结束该函数)
//	}
//	//
//	printf("请输入名字:>");
//	scanf("%s", pc->data[pc->count].name);//这一步要着重理解
//	//最终是把名字存入数组中，故而不取地址，数组名本来就是地址
//
//	printf("请输入年龄:>");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("请输入性别:>");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("请输入电话:>");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("请输入地址:>");
//	scanf("%s", pc->data[pc->count].addr);
//	
//	pc->count++;
//	printf("增加成功\n");
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
			printf("增容成功\n");
		}
	}
}
//动态版本
void AddContact(Contact* pc)
{
	assert(pc);
	//空间不够就增容
	CheckCapacity(pc);
	//
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->count].name);//这一步要着重理解
	//最终是把名字存入数组中，故而不取地址，数组名本来就是地址

	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("增加成功\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i=0;
	//添加表头(这个方式666)，符号左对齐
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name,
											   pc->data[i].age, 
											   pc->data[i].sex,
											   pc->data[i].tele,
											   pc->data[i].addr);
	}
}
static int FindByName(Contact* pc, char name[])//这个函数不需要暴露出去，故而不用声明
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
	int i = 0;//定义的循环变量
	if (pc->count == 0)
	{
		printf("通讯录为空，没有元素可以删除\n");
		return;
	}
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//删除
	//1.查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2.删除
	for (i = pos; i < pc->count-1; i++)// -1是为了防止越界
	{
		pc->data[i] = pc->data[i + 1];//把要删除的哪一个覆盖掉
	}
	pc->count--;//最后一个data数组不会被看到，后续新加会被覆盖
	printf("删除成功");
}

void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	//1.查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	//2.打印
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
												pc->data[pos].age,
												pc->data[pos].sex,
												pc->data[pos].tele,
												pc->data[pos].addr);
}

void ModifyContact(Contact* pc)//修改指定联系人
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	//1.查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	printf("要修改人的信息已经查找到，接下来开始修改\n");
	//2.修改（重新录入）
	printf("请输入名字:>");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pos].addr);
	
	printf("修改成功");

}


//按名字
int cmo_peo_by_name(const void* e1,const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
void SortContact(Contact* pc)//排序联系人/按名字
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmo_peo_by_name);
	printf("排序成功\n");

}