#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include "worker.h"
#include"teacher.h"
#include"manager.h"
#include"workermanager.h"
#include"Employee.h"

#include<fstream>
#define FILENAME  "homework.txt"
class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();//声明

	//退出系统
	void exitsystem();//头文件声明 cpp文件实现

	//记录职工人数
	int Empnum;

	//职工数组指针
	Worker** m_emparray;

	//添加职工
	void add_emp();

	//保存文件
	void save();
	//判断文件是否为空 标志
	bool m_Fileisempty;

	//统计文件中的人数
	int get_Empnum();

	//初始化职工
	void init_Emp();

	//显示职工
	void Show_emp();

	//删除职工
	void Del_emp();

	//判断职工是否存在 若存在返回职工数组中的位置 不存在返回-1
	int Isexist(int id);
	//修改职工
	void Mod_emp();
	//查找职工
	void Find_emp();
	//按照编号排序
	void Sort_emp();
	//清空文件
	void Clean_file();
	
	//析构函数
	~WorkerManager();

};
