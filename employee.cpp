#include"employee.h"

Employee::Employee(int id, string name, int depId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = depId;
}
void Employee::showInfo() 
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\tְ����λ��" << this->getDepName() << endl;
}
string Employee::getDepName()
{
	return string("Ա��");
}