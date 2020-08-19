#include"workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在且有数据
	int num = this->get_EmpNum();
	//cout << "职工人数为" << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存在数组中
	this->init_Emp();
}

void WorkerManager::Show_Menu()
{
	cout << "**************************************" <<endl;
	cout << "******** 欢迎使用职工管理系统 ********" << endl;
	cout << "*********** 0.退出管理程序 ***********" << endl;
	cout << "*********** 1.增加职工信息 ***********" << endl;
	cout << "*********** 2.显示职工信息 ***********" << endl;
	cout << "*********** 3.删除离职职工 ***********" << endl;
	cout << "*********** 4.修改职工信息 ***********" << endl;
	cout << "*********** 5.查找职工信息 ***********" << endl;
	cout << "*********** 6.按照编号排序 ***********" << endl;
	cout << "*********** 7.清空所有文档 ***********" << endl;
	cout << "**************************************" << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp() 
{
	cout<<"请输入添加的职工数量"<<endl;

	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker* [newSize];
		//将原来的数据拷贝进新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int department;
			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理：" << endl;
			cout << "3.老板：" << endl;
			cin >> department;

			Worker* worker = NULL;
			switch (department)
			{
			case 1:
				worker = new Employee(id, name, department);
			case 2:
				worker = new Manager(id, name, department);
			case 3:
				worker = new Boss(id, name, department);
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;

		}

		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//更新职工不为空的标识
		this->m_FileIsEmpty = false;

		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存文件
		this->save();		
	}
	else {
		cout << "输入有误" << endl;
	}
	//按任意键清屏回到上一级目录
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	//写入文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_DepId << endl;
	}
	ofs.close();
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id,name,dId);
		}
		else if (dId == 2)
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

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;

	}
	else
	{
		//按照职工编号删除职工
		int id = 0;
		cout << "请输入想要删除的职工编号：" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum --;
			this->save();
			cout << "删除成功" << endl;
			
		}
		else 
		{
			cout << "删除失败，职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入修改的职工编号" << endl;
		cin >> id;
		
		int index = this->IsExist(id);
		if (index != -1)
		{
			delete this->m_EmpArray[index];
			int newId = 0;
			string newName = "";
			int newdId = 0;

			cout << "查找到" << id << "号员工，请输入新员工编号" << endl;
			cin >> newId;

			cout << "请输入新员工姓名" << endl;
			cin >> newName;

			cout << "请输入新员工职位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理：" << endl;
			cout << "3.老板：" << endl;
			cin >> newdId;

			Worker* worker = NULL;
			switch (newdId)
			{
			case 1:
				worker = new Employee(newId, newName, newdId);
				break;
			case 2:
				worker = new Manager(newId, newName, newdId);
				break;
			case 3:				
				worker = new Boss(newId, newName, newdId);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;
			cout << "修改成功" << endl;
			this->save();
		}
		else
		{
			cout << "职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int select;
		cout << "请输入查找的方式：" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;		
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入职工编号" << endl;			
			cin >> id;			
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}

		}
		else if(select == 2)
		{
			string name;
			cout << "请输入职工姓名:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，该职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;

			}
		}
		else
		{
			cout << "输入错误" << endl;
		}
		system("pause");
		system("cls");
	}

}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int select;
		cout << "请输入排序的方式：" << endl;
		cout << "1.按照职工编号升序" << endl;
		cout << "2.按照职工编号降序" << endl;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}		
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}		
		cout << "排序成功，排序后的结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
}

void WorkerManager::Clean_File()
{
	cout << "请确认是否清空：" << endl;
	cout << "1.是，我要清空" << endl;
	cout << "2.否，选错了" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}