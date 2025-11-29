#include "teacher.h"


//构造函数
Teacher::Teacher(int id, string name, int dId)

{
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

//显示个人信息
 void Teacher::showinfo()
{

	 cout << "职工编号： " << this->m_id
		 << "\t职工姓名： " << this->m_name
		 << "\t岗位： " << this->getdeptname()
		 << "\t岗位职责： 完成教学任务以及学术研究" << endl;
}
//获取岗位名称
 string Teacher::getdeptname()
{
	 return string("教师");
}