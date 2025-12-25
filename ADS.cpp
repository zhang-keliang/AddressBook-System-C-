#include<iostream>
# define MAX 1000 //通讯录储存人数上限
using namespace std;

// 显示菜单栏
void showmenu()
{
	cout << "************************\n" <<
		"***** 1、添加联系人 *****\n" <<
		"***** 2、显示联系人 *****\n" <<
		"***** 3、删除联系人 *****\n" <<
		"***** 4、查找联系人 *****\n" <<
		"***** 5、修改联系人 *****\n" <<
		"***** 6、清空联系人 *****\n" <<
		"***** 0、退出通讯录 *****\n" <<
		"************************\n" << endl;
}
// 设置通讯录联系人的储存信息内容
struct people
{
	string name;
	int sex;
	int age;
	string phonenumber;
};
//设置 通讯录类型
struct txl
{
	int number;
	people personarray[MAX];
};
// 功能1：添加联系人
void addperson(txl* txl1)
{
	if (txl1->number == MAX) {
		return ;
	}
	else{
	cout << "请输入姓名" << endl;
	string name01;
	cin >> name01;
	txl1->personarray[txl1->number].name= name01;

	cout << "请输入性别" << endl;
	cout << "男-->1" << endl;
	cout << "女-->2" << endl;
	int sss;
	while (true)

	{
		cin >> sss;
		if(sss == 1 || sss == 2)
		{
			
			txl1->personarray[txl1->number].sex = sss;
			break;
		}
		else {
			cout << "输入有误，请重新输入" << endl;
		}
	}
		
	cout << "请输入年龄" << endl;
	int age01;
	cin >> age01;
	txl1->personarray[txl1->number].age = age01;

	cout << "请输入电话号码" << endl;
	string phone01;
	cin >> phone01;

	txl1->personarray[txl1->number].phonenumber= phone01;
	cout << "成功创建" << txl1->personarray[txl1->number].name << "联系方式" << endl;
	}
	txl1->number++;
	system("pause");
	system("cls");//命令清零
};
// 功能2： 输出联系人
void printperson(txl* txl2)
{
	if (txl2->number == 0) {
		cout << "通讯录为空" << endl;
	}
	else{
	for (int i = 0; i < txl2->number; i++) {
		string sn;
		if (txl2->personarray[i].sex == 1)
		{
			sn = "男";
		}
		else {
			sn = "女";
		}
		cout << " 姓名： " << txl2->personarray[i].name
			<< " 性别： " <<sn
			<< " 年龄： " << txl2->personarray[i].age
			<< " 手机号： " << txl2->personarray[i].phonenumber << endl;
	}
	
	}
	system("pause");
	system("cls");//命令清零
};
//功能3： 删除联系人
void deletperson(txl* txl3)
{
	string name03;
	cout << "请输入删除人员姓名" << endl;
	cin >> name03;
	if (txl3->number == 0) 
	{
		cout << "通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < txl3->number; i++) 
		{
			if (name03 == txl3->personarray[i].name)
			{
				txl3->personarray[i] = {};
				cout << "成功删除联系人" << endl;
				txl3->number--;
			}
			else {
				cout << "查无此人" << endl;
			};

		}
	}
	system("pause");
	system("cls");//
};
//功能4 修改联系人
void setperson(txl* txl4)
{
	string name04;
	cout << "请输入修改人员姓名" << endl;
	cin >> name04;
	if (txl4->number == 0) {
		cout << "没有联系人" << endl;
	}
	else {
		for (int  i = 0; i < txl4->number; i++) {
			if (name04 == txl4->personarray[i].name)
			{
				cout << "请输入姓名" << endl;
				string name05;
				cin >> name05;
				txl4->personarray[i].name = name05;

				cout << "请输入性别" << endl;
				cout << "男-->1" << endl;
				cout << "女-->2" << endl;
				int sss05;
			
				while (true)
				{
					cin >> sss05;
					if (sss05 == 1 || sss05 == 2)
					{
						txl4->personarray[i].sex = sss05;
						break;
					}
					cout << "输入有误，请重新输入" << endl;

				}

				cout << "请输入年龄" << endl;
				int age05;
				cin >> age05;
				txl4->personarray[i].age = age05;
				cout << "请输入电话号码" << endl;
				string phone05;
				cin >> phone05;
				txl4->personarray[i].phonenumber = phone05;
				cout << "成功修改" << txl4->personarray[i].name << "联系方式" << endl;
				
			}
		}

	}
	system("pause");
	system("cls");//命令清零

}
//功能5：查找联系人
void seekperson(txl* txl5)
{
	string name06;
	cout << "请输入查找人员姓名" << endl;
	cin >> name06;
	if (txl5->number == 0) {
		cout << "没有联系人" << endl;
	}
	else {
		for (int i = 0; i < txl5->number; i++) {
			if (name06 == txl5->personarray[i].name)
			{
				cout << "姓名： " << txl5->personarray[i].name
					<< "性别： " << txl5->personarray[i].sex
					<< "年龄： " << txl5->personarray[i].age
					<< "手机号： " << txl5->personarray[i].phonenumber << endl;
			}
			else {
				cout << "查无此人" << endl;
			};
		}

	}
	system("pause");
	system("cls");//命令清零

}
//功能6：清空联系人
void overperson(txl* txl6)
{
	cout << "请确定是否情况（y/n）" << endl;
	string orderoo;
	cin >> orderoo;
	if(orderoo=="y")
	{ 

	
	for (int i = 1; i < txl6->number; i++) {
		txl6->personarray[i] = {};
	}
	txl6->number = 0;
	system("pause");
	system("cls");//命令清零
	}
	else{
		cout << "取消清空" << endl;
		system("pause");
		system("cls");//命令清零
	}
	
}

// 主函数合并功能模块
int main()
{

	txl tt;
	tt.number = 0;

	int start = 1;//系统为1 继续运行

	while (start)
	{
		showmenu();
		int order;// 选择操作指令
		cin >> order;


		switch (order)
		{
		case 1:
			addperson(&tt);
			break;
		case 2:
			printperson(&tt);
			break;
		case 3:
			deletperson(&tt);	 
			break;
		case 4:
			seekperson(&tt);
			break;
		case 5:
			setperson(&tt);
			break;
		case 6:
			overperson(&tt);
			break;
		case 0:
			cout << "退出通讯录系统 " << endl;
			start = 0;
			break;
			system("pause");
		}
	}
	return 0;
}
