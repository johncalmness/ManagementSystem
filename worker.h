#pragma once
#include<string>
#include<iostream>
using namespace std;

class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string getDepName() = 0;
	   	 
	//ְ�����
	int m_Id;
	//ְ������
	string m_Name;
	//���ű��
	int m_DepId;

};