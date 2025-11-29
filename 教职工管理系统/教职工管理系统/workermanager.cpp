#include"workermanager.h"


WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);// 读文件

		if (!ifs.is_open())
		{
			cout << "文件不存在" << endl;
			//初始化属性
			//初始化记录人数
			this->Empnum = 0;//职工数
			//初始化数组指针
			this->m_emparray = NULL;
			//初始化文件是否为空
			this->m_Fileisempty = true;
			ifs.close();
			return;
		}
	
		//2.文件存在 数据为空
		char ch;
		ifs >> ch;//从文件中读取一个字符 判断所读取的字符是否是文件尾
		if (ifs.eof())
		{
			//文件为空
			cout << "文件为空" << endl;
			//初始化记录人数
			this->Empnum = 0;//职工数
			//初始化数组指针
			this->m_emparray = NULL;
			//初始化文件是否为空
			this->m_Fileisempty = true;
			ifs.close();
			return;
		}
		//3.文件存在 且记录数聚
		int num = this->get_Empnum();
		cout << "职工人数为： " << num << endl;
		this->Empnum = num;
		this->m_emparray = new Worker * [this->Empnum];

	//将文件中的数据存放到数组中
		this->init_Emp();

		//测试代码
	/*	for (int i = 0; i < this->Empnum; i++)
		{
			cout << "职工编号： " << this->m_emparray[i]->m_id
				<<"姓名： " << this->m_emparray[i]->m_name
				<< "部门编号：" << this->m_emparray[i]->m_DeptId << endl;
		}*/
}

//展示菜单
void WorkerManager::Show_Menu()//实现 成员函数故加上作用域
{
	cout << "****************************************************" << endl;
	cout << "******************* 欢迎使用职工管理系统！**************" << endl;
	cout << "******************* 0.退出管理系统 **************" << endl;
	cout << "******************* 1.增加职工信息 **************" << endl;
	cout << "******************* 2.显示职工信息 **************" << endl;
	cout << "******************* 3.删除离职职工 **************" << endl;
	cout << "******************* 4.修改职工信息 **************" << endl;
	cout << "******************* 5.查找职工信息 **************" << endl;
	cout << "******************* 6.按照编号排序 **************" << endl;
	cout << "******************* 7.清空所有文档 **************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::exitsystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);//退出程序
}

//添加职工
void  WorkerManager::add_emp()
{
	cout << "请输入添加职工的数量：" << endl;

	int addnum = 0;//保存用户输入数量
	cin >> addnum;
	if (addnum > 0)
	{
		//计算添加新空间的大小
		int newsize = this->Empnum + addnum;//新空间大小为原来记录人数+新增人数

		//开辟新空间
		Worker** newspace = new Worker * [newsize];

		//将原来空间下的数据 拷贝到新空间下
		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->Empnum; i++)
			{
				newspace[i] = this->m_emparray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addnum; i++)
		{
			int id; string name; int dselect;//部门
			cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
			cin >> name;
			cout << "请输入第 " << i + 1 << " 个新职工岗位： " << endl;
			cout << "1.工人" << endl;
			cout << "2.教师" << endl;
			cout << "3.管理人员" << endl;
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, 1);//1是部门编号
				break;
			case 2:
				worker = new Employee(id, name, 2);
				break;
			case 3:
				worker = new Employee(id, name, 3);
				break;
			default:
				break;
			}
			//将创建职工保存到数组中
			newspace[this->Empnum + i] = worker;

		}
		//释放原有空间 
		delete[] this->m_emparray;

		//更改新空间的指向
		this->m_emparray = newspace;

		//更新新的职工人数
		this->Empnum = newsize;
		//提示添加成功

		//更新职工不为空
		this->m_Fileisempty = false;

		cout << "成功添加" << addnum << "名新职工" << endl;

		//保存数据到文件中
		this->save();

	}


	else
	{
		cout << "输入数据有误" << endl;
	}
	//按任意键清屏 回到上级目录
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//文件名和打开模式 输出的方式打开 即写文件

	//将每个人的数据写到文件中
	for (int i = 0; i < this->Empnum; i++)
	{
		ofs << this->m_emparray[i]->m_id << " "
			<< this->m_emparray[i]->m_name << " "
			<< this->m_emparray[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

//统计文件中的人数
int WorkerManager::get_Empnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读文件
	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数变量
		num++;
	}
	return num;
}
//初始化职工
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
		if (dId == 1)//工人
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//老师
		{
			worker = new Teacher(id, name, dId);
		}
		else //管理人员
		{

			worker = new Manager(id, name, dId);
		}
		this->m_emparray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();

}


//显示职工
void WorkerManager::Show_emp()
{
	//判断文件是否为空
	if (this->m_Fileisempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < Empnum; i++)
		{
			//用多态调用程序接口
			this->m_emparray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}
//删除职工
void WorkerManager::Del_emp()
{
	if (this->m_Fileisempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除的职工编号： " << endl;
		int id = 0;
		cin >> id;

		int index = this->Isexist(id);

		if (index != -1)//删除index位置上的职工
		{
			
			for (int i = index; i < this->Empnum - 1; i++)
			{
				//数据前移
				this->m_emparray[i] = this->m_emparray[i + 1];

			}
			this->Empnum--;//更新数组中记录人员个数
			//数据同步更新到文件中
			this->save();

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败 未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在 若存在返回职工数组中的位置 不存在返回-1
int WorkerManager::Isexist(int id)
{
	int index = -1;//先假设不存在
	for (int i = 0; i < this->Empnum; i++)
	{
		if (this->m_emparray[i] ->m_id == id)
		{
			//找到职工
			index = i;

			break;
		}
	}
	return index;
}
void WorkerManager::Mod_emp()
{
	if (this->m_Fileisempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{

		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >>id;

		int ret = this->Isexist(id);
		if (ret != -1)
		{
			//查到此人

			delete this->m_emparray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;
			cout << "请输入新姓名：" << endl;
			cin >> newName;
			cout << "请输入新岗位：" << endl;
			cout << "1.工人" << endl;
			cout << "2.教师" << endl;
			cout << "3.管理人员" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Teacher(newId, newName, dSelect);
				break;
			case 3:
				worker = new Manager(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//更新数据到数组中
			this->m_emparray[ret] = worker;

			cout << "修改成功" << endl;

			//保存到文件中
			this->save();
		}
		else
			cout << "修改失败 查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//查找职工
void WorkerManager::Find_emp()
{
	if (this->m_Fileisempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按编号茶
			int id;
			cout << "请输入查找的职工编号: " << endl;
			cin >> id;

			int ret = Isexist(id);
			if (ret != -1)
			{
				cout << "查找成功 该职工信息如下： " << endl;
				this->m_emparray[ret]->showinfo();
			}
			else
				cout << "查找失败 查无此人" << endl;
		}
		else if (select = 2)
		{
			//按姓名查
			string name;
			cout << "请输入查找姓名： " << endl;
			cin >> name;
			//加入判断是否查到的标志
			bool flag = false;//默认未找到职工

			for (int i = 0; i < Empnum; i++)
			{
				if (this->m_emparray[i]->m_name == name)
				{
					cout << "查找成功 职工编号为： " << this->m_emparray[i]->m_id
						<< "号职工信息如下： " << endl;
					flag = true;

					this->m_emparray[i]->showinfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败 查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}
//按照编号排序
void WorkerManager::Sort_emp()
{
	if (this->m_emparray)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工编号升序：" << endl;
		cout << "2.按职工编号降序：" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < Empnum; i++)
		{
			int minormax = i;//声明最小值或最大值下标
			for (int j = i + 1; j < this->Empnum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_emparray[minormax]->m_id > this->m_emparray[j]->m_id)
					{
						minormax = j;
					}
				}

				else//降序
				{
					if (this->m_emparray[minormax]->m_id < this->m_emparray[j]->m_id)
					{
						minormax = j;
					}
				}
			}
			//判断
			if (i != minormax)
			{
				Worker* temp = this->m_emparray[i];
				this->m_emparray[i] = this->m_emparray[minormax];
				this->m_emparray[minormax] = temp;
			}
		}
		cout << "排序成功 排序后的结果为： " << endl;
		this->save();
		this->Show_emp();
	}
}
//清空文件
void WorkerManager::Clean_file()
{
	cout << "确认清空吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->Empnum; i++)
			{
				//删除堆区的每个职工对象
				delete[] this->m_emparray[i];//清空堆区数据
				this->m_emparray = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->Empnum = 0;
			this->m_Fileisempty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
	

	WorkerManager::~WorkerManager()
{
	if (this->m_emparray != NULL)
	{
		for (int i = 0; i < this->Empnum; i++)
		{
			if (this->m_emparray[i] != NULL)
			{
				delete[] this->m_emparray[i];
			}
		}
		delete[] this->m_emparray;
		this->m_emparray = NULL;
	}

}