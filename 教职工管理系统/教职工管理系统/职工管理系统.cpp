#include<iostream>
using namespace std;
#include "workermanager.h"//包含自定义头文件

//#include "worker.h"
//#include "employee.h"
//#include "manager.h"
//#include "teacher.h"

int main()

{
	////测试代码
	//Worker* worker = NULL;//创建空指针
	//worker = new Employee(1, "张三",1);//new在堆区创建 需要手动删除
	//	worker->showinfo();
	//	delete worker;

	//	worker = new Teacher(2, "李四", 2);
	//	worker->showinfo();
	//	delete worker;

	//	worker = new Manager(3, "王五", 3);
	//	worker->showinfo();
	//	delete worker;

	//实例化管理者对象
	WorkerManager wm;

	int choice = 0;//用来存储用户的选项
	//这样既可以接受任何输入，又可以判断输入是否合理

	while (true)
	{
		//调用展示菜单成员函数
		wm.Show_Menu();

		cout << "请输入您的选择： " << endl;
		cin >> choice;//接受用户的选项

		switch (choice)
		{
		case 0://退出系统
			wm.exitsystem();
			break;
		case 1://增加职工
			wm.add_emp();
			break;
		case 2://显示职工
			wm.Show_emp();
			break;
		case 3://删除职工
			/*{*/

				//测试
				//int ret = wm.Isexist(1);//输入需要测试职工的编号
				//if (ret != -1)
				//{
				//	cout << "职工存在" << endl;
				//}
				//else
				//{
				//	cout << "职工不存在" << endl;
				//}
			break;
			/*}*///case整体需要用大括号括起来 不然代码块过长
			wm.Del_emp();
		case 4://修改职工
			wm.Mod_emp();
			break;
		case 5://查找职工
			wm.Find_emp();
			break;
		case 6://排序职工
			wm.Sort_emp();
			break;
		case 7://清空文档
			wm.Clean_file();
			break;
		default:
			system("cls");//如果输入的不是0~7的有效数字 则清屏
			break;

		}
		
	}
}