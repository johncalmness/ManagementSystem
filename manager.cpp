#include"manager.h"

Manager::Manager(int id, string name, int depId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = depId;
}
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\tְ����λ��" << this->getDepName() << endl;
}
string Manager::getDepName()
{
	return string("����");
}