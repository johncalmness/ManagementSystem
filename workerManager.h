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

	//��ʾ�˵�����
	void Show_Menu();
	//�˳�ϵͳ����
	void exitSystem();
	//���ְ�� �� �����ļ� ����
	void Add_Emp();
	void save();
	//��ʾְ��
	void Show_Emp();
	//ͳ���ļ�������
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//�ж�ְ���Ƿ���� �� ɾ��Ա�� ����
	int IsExist(int);
	void Del_Emp();
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����ְ��
	void Sort_Emp();
	//����ĵ�
	void Clean_File();


	//��¼ְ������
	int m_EmpNum;
	//ְԱ�����ָ��
	Worker** m_EmpArray;
	//�ļ��Ƿ���ڱ�ʾ
	bool m_FileIsEmpty;
};