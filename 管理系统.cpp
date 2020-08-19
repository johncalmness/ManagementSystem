#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

int main()
{
	//测试代码
	/*Worker* worker = NULL;
	worker = new Employee(1,"张三",1);
	worker->showInfo();
	delete worker;*/


	//初始化选择
	int choice = 0 ;
	//实例化管理器对象
	WorkerManager wm;
	while (true)
	{
		//调用显示菜单
		wm.Show_Menu();						
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			wm.exitSystem();
			break;
		case 1:	//增加职工
			wm.Add_Emp();
			break;
		case 2:	//显示职工
			wm.Show_Emp();
			break;
		case 3:	//删除职工
			wm.Del_Emp();
			break;
		case 4:	//修改职工
			wm.Mod_Emp();
			break;
		case 5:	//查找职工
			wm.Find_Emp();
			break;
		case 6:	//排序职工
			wm.Sort_Emp();
			break;
		case 7:	//清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");   //清屏
			break;
		}
	}
	system("pause");
	return 0;
}