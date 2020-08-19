#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
constexpr auto FILENAME = "empFile.txt";

using namespace std;

class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	//显示菜单功能
	void Show_Menu();
	//退出系统功能
	void exitSystem();
	//添加职工 与 保存文件 功能
	void Add_Emp();
	void save();
	//显示职工
	void Show_Emp();
	//统计文件中人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//判断职工是否存在 与 删除员工 功能
	int IsExist(int);
	void Del_Emp();
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//排序职工
	void Sort_Emp();
	//清空文档
	void Clean_File();


	//记录职工人数
	int m_EmpNum;
	//职员数组的指针
	Worker** m_EmpArray;
	//文件是否存在标示
	bool m_FileIsEmpty;
};