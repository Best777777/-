#include "manager.h"


//构造函数
Manager::Manager(int id, string name, int dId)

{
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

//显示个人信息
void Manager::showinfo()
{

	cout << "职工编号： " << this->m_id
		<< "\t职工姓名： " << this->m_name
		<< "\t岗位： " << this->getdeptname()
		<< "\t岗位职责：管理校园内的所有事务 " << endl;
}
//获取岗位名称
string Manager::getdeptname()
{
	return string("管理人员");
}