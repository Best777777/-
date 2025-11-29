#include "employee.h"

//构造函数
Employee::Employee(int id, string name, int dId)//加上作用域
{
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}
//显示个人信息
void Employee::showinfo()//声明
{
	cout << "职工编号： " << this->m_id
		<< "\t职工姓名： " << this->m_name
		<< "\t岗位： " << this->getdeptname()
		<< "\t岗位职责： 完成管理人员交给的任务" << endl;
 }

//获取岗位名称
string Employee::getdeptname()
 {
	return string("员工");
 }