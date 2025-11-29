#pragma once 
#include<iostream>
using namespace std;
#include<string.h>

//教职工抽象类
class Worker
{
public:

	//显示个人信息
	virtual void showinfo() = 0;
	//获取岗位名称
	virtual string getdeptname() = 0;
	//教职工编号
	int m_id;
	
	//教职工姓名
	string m_name;

	//部门编号
	int m_DeptId;
};