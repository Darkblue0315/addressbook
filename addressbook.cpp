#include<iostream>
using namespace std;
//�����˵�
void showmenu()
{
	cout << "**********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;
}
struct person//��ϵ�˽ṹ��
{
	string name;
	int sex;//1��2Ů
	int age;
	string phone;
	string address;
};
#define Max 1000
struct addressbooks//ͨѶ¼�ṹ��
{
	person personarr[Max];
	int size;//ͨѶ¼����
};
//�����ϵ��
void addperson(addressbooks* abs)
{
	if (abs->size == Max)
	{
		cout << "ͨѶ¼�����Ѵ�����" << endl;
	}
	else
	{
		string name_;
		cout << "�������û�����" << endl;
		cin >> name_;
		abs->personarr[abs->size].name = name_;
		int sex_ = 0;
		cout << "1----�У�2----Ů" << endl;
		cout << "�������Ա�" << endl;
		cin >> sex_;
		while (true)
		{
			if (sex_ == 1 || sex_ == 2)
			{
				abs->personarr[abs->size].sex = sex_;
				break;
			}
			cout << "��������" << endl;
		}
		int age = 0;
		cout << "����������" << endl;
		cin >> age;
		abs->personarr[abs->size].age = age;
		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		abs->personarr[abs->size].phone = phone;
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personarr[abs->size].address = address;
		//����ͨѶ¼����
		abs->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//����
	}
}
//��ʾ��ϵ��
void showperson(addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0;i < abs->size;i++)
		{
			cout << "������ " << abs->personarr[i].name << "\t";
			cout << "�ձ� " << (abs->personarr[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺 " << abs->personarr[i].age << "\t";
			cout << "�绰�� " << abs->personarr[i].phone << "\t";
			cout << "��ַ�� " << abs->personarr[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
//ɾ����ϵ��
//1.�����ϵ���Ƿ����
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
//2.ʵ��ɾ������
void deleteperson(addressbooks* abs)
{
	cout << "������Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;
	int ret = checkperson(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = ret;i < abs->size;i++)
		{
			//����Ǩ��
			abs->personarr[i] = abs->personarr[i + 1];
			abs->size--;
		}
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findperson(addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = checkperson(abs, name);
	if (ret != -1)
	{
		cout << "������ " << abs->personarr[ret].name << "\t";
		cout << "�Ա� " << abs->personarr[ret].sex << "\t";
		cout << "���䣺 " << abs->personarr[ret].age << "\t";
		cout << "�绰�� " << abs->personarr[ret].phone << "\t";
		cout << "��ַ�� " << abs->personarr[ret].address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void changeperson(addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = checkperson(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personarr[ret].name = name;
		cout << "�������Ա�" << endl;
		cout << "1-------��" << endl;
		cout << "2-------Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarr[ret].sex = sex;
			}
			cout << "������������������" << endl;
		}
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personarr[ret].age = age;
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->personarr[ret].phone = phone;
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->personarr[ret].address = address;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pasuse");
	system("cls");
}
//�����ϵ��
void cleanbooks(addressbooks* abs)
{
	abs->size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main()
{
	addressbooks abs;//����ͨѶ¼�ṹ�����
	abs.size = 0;
	while (true)
	{
		int select = 0;
		showmenu();//�˵�����
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addperson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://ɾ����ϵ��
		/*{
			string name;
			cout << "������Ҫɾ������ϵ�˵�����" << endl;
			cin >> name;
			if (checkperson(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ���" << endl;
			}

		}*/
		{
			deleteperson(&abs);
		}	
			break;
		case 4://������ϵ��
			findperson(&abs);
			break;
		case 5://�޸���ϵ��
			changeperson(&abs);
			break;
		case 6://�����ϵ��
			cleanbooks(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
			break;

		}
	}
	
	system("pause");
	return 0;
}