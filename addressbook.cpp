#include<iostream>
using namespace std;
//描述菜单
void showmenu()
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
}
struct person//联系人结构体
{
	string name;
	int sex;//1男2女
	int age;
	string phone;
	string address;
};
#define Max 1000
struct addressbooks//通讯录结构体
{
	person personarr[Max];
	int size;//通讯录人数
};
//添加联系人
void addperson(addressbooks* abs)
{
	if (abs->size == Max)
	{
		cout << "通讯录人数已达上限" << endl;
	}
	else
	{
		string name_;
		cout << "请输入用户姓名" << endl;
		cin >> name_;
		abs->personarr[abs->size].name = name_;
		int sex_ = 0;
		cout << "1----男，2----女" << endl;
		cout << "请输入性别" << endl;
		cin >> sex_;
		while (true)
		{
			if (sex_ == 1 || sex_ == 2)
			{
				abs->personarr[abs->size].sex = sex_;
				break;
			}
			cout << "输入有误" << endl;
		}
		int age = 0;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personarr[abs->size].age = age;
		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personarr[abs->size].phone = phone;
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personarr[abs->size].address = address;
		//更新通讯录人数
		abs->size++;
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏
	}
}
//显示联系人
void showperson(addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0;i < abs->size;i++)
		{
			cout << "姓名： " << abs->personarr[i].name << "\t";
			cout << "姓别： " << (abs->personarr[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personarr[i].age << "\t";
			cout << "电话： " << abs->personarr[i].phone << "\t";
			cout << "地址： " << abs->personarr[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
//删除联系人
//1.检测联系人是否存在
int checkperson(addressbooks* abs,string name)
{
	for (int i = 0;i < abs->size;i++)
	{
		if (abs->personarr[i].name == name)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}
//2.实现删除功能
void deleteperson(addressbooks* abs)
{
	cout << "请输入要删除的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = checkperson(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = ret;i < abs->size;i++)
		{
			//数据迁移
			abs->personarr[i] = abs->personarr[i + 1];
			abs->size--;
		}
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findperson(addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = checkperson(abs, name);
	if (ret != -1)
	{
		cout << "姓名： " << abs->personarr[ret].name << "\t";
		cout << "性别： " << abs->personarr[ret].sex << "\t";
		cout << "年龄： " << abs->personarr[ret].age << "\t";
		cout << "电话： " << abs->personarr[ret].phone << "\t";
		cout << "地址： " << abs->personarr[ret].address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void changeperson(addressbooks* abs)
{
	cout << "请输入要修改的联系人的姓名" << endl;
	string name;
	cin >> name;
	int ret = checkperson(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personarr[ret].name = name;
		cout << "请输入性别" << endl;
		cout << "1-------男" << endl;
		cout << "2-------女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarr[ret].sex = sex;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personarr[ret].age = age;
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		abs->personarr[ret].phone = phone;
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personarr[ret].address = address;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pasuse");
	system("cls");
}
//清空联系人
void cleanbooks(addressbooks* abs)
{
	abs->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main()
{
	addressbooks abs;//创建通讯录结构体变量
	abs.size = 0;
	while (true)
	{
		int select = 0;
		showmenu();//菜单调用
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addperson(&abs);
			break;
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
		/*{
			string name;
			cout << "请输入要删除的联系人的姓名" << endl;
			cin >> name;
			if (checkperson(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到了" << endl;
			}

		}*/
		{
			deleteperson(&abs);
		}	
			break;
		case 4://查找联系人
			findperson(&abs);
			break;
		case 5://修改联系人
			changeperson(&abs);
			break;
		case 6://清空联系人
			cleanbooks(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			break;

		}
	}
	
	system("pause");
	return 0;
}