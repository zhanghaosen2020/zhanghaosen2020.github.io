#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"workManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

int main() {
	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1: //添加职工
			wm.Add_Emp();
				break;
		case 2: //显示职工
			wm.Show_Emp();
			break;
		case 3: //删除职工
		{

			//测试代码
		/*	int ret = wm.IsExist(11);
			if (ret != -1)
			{
				cout << "职工存在" << endl;
			}
			else
			{
				cout << "职工不存在" << endl;
			}*/

			wm.Del_Emp();
			break;
		}
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");//输入其他,清空屏幕,再回来
			break;
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}
