#include"employee.h"

Employee::Employee(int id, string name, int depId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = depId;
}
void Employee::showInfo() 
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职工岗位：" << this->getDepName() << endl;
}
string Employee::getDepName()
{
	return string("员工");
}