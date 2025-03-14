#define _CRT_SECURE_NO_WARNINGS
#include "workManager.h"


WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	//�ļ����������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsempty = true;
		ifs.close();
		return;
	}

	//�ļ�����,��û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())//eof()�����Ա����,�������ļ�ĩβ��ʱ�򷵻ط�0ֵ,û�е��ļ�ĩβ�򷵻�0ֵ
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsempty = true;
		ifs.close();
		return;
	}
	
	//�ļ�����,���Ҽ�¼������
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ: " << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//��ʼ��ְ��
	init_Emp();
	//���Դ���
	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "ְ���ţ� " << this->m_EmpArray[i]->m_Id
	//		<< " ְ�������� " << this->m_EmpArray[i]->m_Name
	//		<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	//}

}

void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "********* ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "************* 0.�˳�������� *************" << endl;
	cout << "************* 1.����ְ����Ϣ *************" << endl;
	cout << "************* 2.��ʾְ����Ϣ *************" << endl;
	cout << "************* 3.ɾ����ְְ�� *************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ *************" << endl;
	cout << "************* 5.����ְ����Ϣ *************" << endl;
	cout << "************* 6.���ձ������ *************" << endl;
	cout << "************* 7.��������ĵ� *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������: " << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;
	if (addNum > 0)
	{
		//���Ա��
		//�����¿ռ�
		Worker** newSpace = new Worker * [this->m_EmpNum + addNum];
		//�������һ�¶�����Ⱥ�,�Ϳ��Ա��⻺��������ľ�����

		//������ӵ��¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ����� = ԭ����¼����+��������
	
	
		
		//��ԭ���ռ��µ�����,�������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��
			cout << "�������" << i + 1 << " ����ְ�����:" << endl;
			cin >> id;

			cout << "�������" << i + 1 << " ����ְ������:" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//���ϱߴ�����ְ��ָ��,���浽������
			newSpace[this->m_EmpNum + i] = worker;//�����m_EmpNum+i����Ҫ
		}
		
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//���Ƿ����ļ������ڻ���Ϊ����� m_FileIsEmpty �ж��ļ��Ƿ�Ϊ�յı�־��Ϊ�棬�Ǻ�ʱΪ�٣�
		//�ɹ����ְ����Ӧ�ø����ļ���Ϊ�յı�־!
		//����ְ����Ϊ�յı�־
		this->m_FileIsempty = false;

		//�ɹ���Ӻ�Ӧ�ñ��浽�ļ���
		this->Save();

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��!" << endl;

	}
	else
	{
		cout << "��������" << endl;
	}

	//���������,�����ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

void WorkerManager::Save()
{
	ofstream ofs;//д�ļ�
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ� -- д�ļ�

	//��ÿ���˵�����д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�  ���ļ�
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) 
	{
		//ͳ����������
		num++;
	}
	return num;
}

//��ʼ��ְ��
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
		if (dId == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
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
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ú����ӿ�
			this->m_EmpArray[i]->showInfo();//�������е�Ԫ���Ǹ���ָ��,ָ���������,�˴������˶�̬
		}
	}
	//�������������
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
			//�ҵ�ְ��
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
		cout << "�ļ������ڻ��߼�¼Ϊ��!" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "������Ҫɾ����ְ�����: " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//ְ������ִ��ɾ������
		{
			

			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				//����Ǩ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������е���Ա����

			//ɾ�����֮��,��Ҫͬ�����ļ���
			this->Save();
			cout << "ɾ���ɹ�!" << endl;
		}
		else//Ҫɾ����ְ��������
		{
			cout << "ɾ��ʧ��,δ�ҵ���Ա��!" << endl;
		}
	}
	system("pause");
	system("cls");


}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else 
	{
		cout << "������Ҫ�޸�ְ����Ϣ�ı��: " << endl;
		int id = -1;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ��ñ�ŵ�ְ��
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname = "";
			int dSelect = 0;
			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newid;

			cout << "������������: " << endl;
			cin >> newname;

			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			cout << "�޸ĳɹ�!" << endl;

			this->Save();
		}
		else
		{
			cout << "�޸�ʧ��,���޴���!" << endl;
		}
	}
	//������� ����
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
