#define _CRT_SECURE_NO_WARNINGS
#include "workManager.h"


WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	//文件不存在情况
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsempty = true;
		ifs.close();
		return;
	}

	//文件存在,但没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())//eof()这个成员函数,当读到文件末尾的时候返回非0值,没有到文件末尾则返回0值
	{
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsempty = true;
		ifs.close();
		return;
	}
	
	//文件存在,并且记录了数据
	int num = this->get_EmpNum();
	//cout << "职工人数为: " << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//初始化职工
	init_Emp();
	//测试代码
	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "职工号： " << this->m_EmpArray[i]->m_Id
	//		<< " 职工姓名： " << this->m_EmpArray[i]->m_Name
	//		<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	//}

}

void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "********* 欢迎使用职工管理系统！ **********" << endl;
	cout << "************* 0.退出管理程序 *************" << endl;
	cout << "************* 1.增加职工信息 *************" << endl;
	cout << "************* 2.显示职工信息 *************" << endl;
	cout << "************* 3.删除离职职工 *************" << endl;
	cout << "************* 4.修改职工信息 *************" << endl;
	cout << "************* 5.查找职工信息 *************" << endl;
	cout << "************* 6.按照编号排序 *************" << endl;
	cout << "************* 7.清空所有文档 *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量: " << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		//添加员工
		//开辟新空间
		Worker** newSpace = new Worker * [this->m_EmpNum + addNum];
		//这里调换一下定义的先后,就可以避免缓冲区溢出的警告了

		//计算添加的新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间人数 = 原来记录人数+新增人数
	
	
		
		//将原来空加下的数据,拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择
			cout << "请输入第" << i + 1 << " 个新职工编号:" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << " 个新职工姓名:" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将上边创建的职工指针,保存到数组中
			newSpace[this->m_EmpNum + i] = worker;//这里的m_EmpNum+i蛮重要
		}
		
		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;

		//我们发现文件不存在或者为空清空 m_FileIsEmpty 判断文件是否为空的标志都为真，那何时为假？
		//成功添加职工后，应该更改文件不为空的标志!
		//更新职工不为空的标志
		this->m_FileIsempty = false;

		//成功添加后应该保存到文件中
		this->Save();

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工!" << endl;

	}
	else
	{
		cout << "输入有误" << endl;
	}

	//按任意键后,清屏回到上级目录
	system("pause");
	system("cls");
}

void WorkerManager::Save()
{
	ofstream ofs;//写文件
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件 -- 写文件

	//将每个人的数据写入文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件  读文件
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) 
	{
		//统计人数变量
		num++;
	}
	return num;
}

//初始化职工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsempty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用函数接口
			this->m_EmpArray[i]->showInfo();//该数组中的元素是父类指针,指向子类对象,此处发生了多态
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");

}

int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		/*if (id == this->m_EmpArray[i]->m_Id)
		{
			index = i;
			return index;
		}
		else
		{
			return -1;
		}*/

		if (id == this->m_EmpArray[i]->m_Id)
		{
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileIsempty)
	{
		cout << "文件不存在或者记录为空!" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入要删除的职工编号: " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//职工存在执行删除操作
		{
			

			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				//数据迁移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组中的人员个数

			//删除完成之后,需要同步到文件中
			this->Save();
			cout << "删除成功!" << endl;
		}
		else//要删除的职工不存在
		{
			cout << "删除失败,未找到该员工!" << endl;
		}
	}
	system("pause");
	system("cls");


}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else 
	{
		cout << "请输入要修改职工信息的编号: " << endl;
		int id = -1;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到该编号的职工
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname = "";
			int dSelect = 0;
			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newid;

			cout << "请输入新姓名: " << endl;
			cin >> newname;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newid, newname, dSelect);
				break;
			case 2:
				worker = new Manager(newid, newname, dSelect);
				break;
			case 3:
				worker = new Boss(newid, newname, dSelect);
				break;
			default:
				break;
			}

			this->m_EmpArray[ret] = worker;
			cout << "修改成功!" << endl;

			this->Save();
		}
		else
		{
			cout << "修改失败,查无此人!" << endl;
		}
	}
	//按任意键 清屏
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}
