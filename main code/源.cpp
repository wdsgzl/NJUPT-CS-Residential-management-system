#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include <sstream> 
#include<conio.h>
#include <iomanip>
using namespace std;
void Login();
void Menu();
void MenuB(string zhuhu);
char HidenWrite();
int n;
class Household
{
	string housenumber;//��-��Ԫ-����
	string name;//����
	string hname;//��������
	string identity;//���
	string relationship;//�뻧����ϵ
	string job;//ְҵ
	string workplace;//�����ص�
	string phonenumber;//�ֻ�����
	string workphonenumber;//�����绰
	string QQ;//QQ
	string car_number;//�������
	double fee;//Ӧ����ҵ����
	double shiji;//ʵ�ʽ���
	double owe;//Ƿ��
public:
	Household()
	{
		housenumber = "0";
		name = "����������";
		hname = "�����뻧������";
		identity = "���������";
		relationship = "��������";
		job = "������ְҵ";
		workplace = "�����뵥λ";
		phonenumber = "0";
		workphonenumber = "0";
		QQ = "0";
		car_number = "0";
		fee = 0.0;
		shiji = 0.0;
		owe = 0.0;
	}
	Household(string hn, string na, string hna, string id, string re, string jo, string wp, string pn, string wpn, string qq, string cn)
	{
		housenumber = hn;
		name = na;
		hname = hna;
		identity = id;
		relationship = re;
		job = jo;
		workplace = wp;
		phonenumber = pn;
		workphonenumber = wpn;
		QQ = qq;
		car_number = cn;
		fee = 0.0;
		shiji = 0.0;
		owe = 0.0;
	}
	friend void CreateHousehold();//����Ա����/���ס��
	friend void InputHousehold(Household& hs);//������Ϣ
	friend void Openfile(string fname, Household& hs);//��Ŀ���ļ�����д������
	friend string fpath(Household& hs);//���ַ���ת��Ϊ�ļ�·��
	friend void OpenFeefile(Household& hs);//����Ƿ���ļ���
	friend void Fee();//��ѯǷ��
	friend void Show();//��ѯ����ס����Ϣ
	friend void Delete();//����Աɾ��
	friend void Jiaona(string zhuhu);//ס������Ƿ��
	friend void car_search();//����Ա��ѯ����
	friend void change();//����Ա�޸�ס����Ϣ
	friend void  showsingle();//����Ա��ѯ����ס����Ϣ
	friend void showsingle(string zhuhu);//ס����ѯ�Ը�������Ϣ
	friend void change(string zhuhu);//ס���޸��Ը�������Ϣ
	friend void carp(string zhuhu);
};
class Administrators
{
private:
	string communityname;//С������
	string total_buildings;//��������
	string green_square;//�̻����
	string  supportingfacilities;//������ʩ
	string building_square;//�������
public:
	Administrators()
	{

		communityname = "С������";
		total_buildings = "0";
		green_square = "0";
		supportingfacilities = "������ʩ";
		building_square = "0";
	}
	Administrators(string cn, string tb, string bg, string gs, string suf, string hsn, string hs, string bs, string car, string f)
	{
		communityname = cn;
		total_buildings = tb;
		green_square = gs;
		supportingfacilities = suf;
		building_square = bs;

	}

	friend void CreateCommunity();//����/��С���ļ���
	friend  void Openfile_a(string fname1, Administrators ad[]);//��С����Ϣд���ļ�
	friend void InputCommuinty(Administrators ad[]);//����С����Ϣ

};
void CreateHousehold();
void CreateCommunity();
void InputHousehold(Household& hs);
void InputCommuinty(Administrators ad[]);
void Search();
void Show();//չʾ������Ϣ
//void Show(string zhuhu);
void Show_s();
void Openfile(string fname, Household& hs);
void Openfile_a(string fname1, Administrators ad[]);
string fpath(Household& hs);
void Delete();
void Fee();
void OpenFeefile(Household& hs);
void repair_complain(string zhuhu);//Ͷ�ߺͱ���
void Jiaona(string zhuhu);
void car_search();
void Display_car();//ͨ����λ��ѯ����
void carp(string zhuhu);//����ͣ��λ
void change();
void showsingle();//����Ա��ѯ
void showsingle(string zhuhu);//ס����ѯ
void change(string zhuhu);
void shoubaoxiu();
int main()
{
	Login();
}
void Menu()
{
	cout << "��������������������������" << endl;
	cout << "|С����ҵ����ϵͳ(����Ա)|" << endl;
	cout << "��������������������������" << endl;
	cout << "|     1�����ס����Ϣ    |" << endl;
	cout << "|   2����ѯ����ס����Ϣ  |" << endl;
	cout << "|   3����ѯ����ס����Ϣ  |" << endl;
	cout << "|     4��ɾ��ס����Ϣ    |" << endl;
	cout << "|     5���޸�ס����Ϣ    |" << endl;
	cout << "|     6����ѯ������Ϣ    |" << endl;
	cout << "|     7���޸�������Ϣ    |" << endl;
	cout << "|     8����ѯ���ƺ�      |" << endl;
	cout << "|     9����ѯ��ҵ��      |" << endl;
	cout << "|     10����ѯͣ��λ     |" << endl;
	cout << "|   11����ѯ������Ͷ��   |" << endl;
	cout << "|      12���˳���¼      |" << endl;
	cout << "|      13���˳�ϵͳ      |" << endl;
	cout << "��������������������������" << endl;
	int c;
	cout << "���������ָ��" << endl;
	cin >> c;
	if (!(c >= 1 && c <= 13))
	{
		cout << "��Чָ��" << endl;
		Menu();
	}
	switch (c)//����ִ��1~7��ָ�� ��Ŀǰ�����1��7���� 
	{
	case(1):
	{
		system("cls");
		CreateHousehold();//����ʵ�ִ������û�
		break;
	}
	case(2):
	{system("cls");
	Show();
	break;
	}
	case(3):
	{system("cls");
	showsingle();
	}
	case(4):
	{system("cls");//����ʵ��ɾ���û�����
	Delete();
	break;
	}
	case(6):
	{system("cls");
	Show_s();
	}
	case(7):
	{system("cls");//����ʵ����������Ϣ������޸�
	cout << "����������ʩ����Ŀ" << endl;
	cin >> ::n;
	CreateCommunity();
	break;
	}
	case(12): {system("cls");
		cout << "�ɹ��˳���¼";
		Login();
	}
	case(13):
	{system("cls");//����ʵ���˳�ϵͳ 
	exit(1);
	}
	case(9):
	{system("cls");
	Fee();//��ѯ��ҵ�����
	break;
	}
	case(8):
	{system("cls");
	car_search();//��ѯ����
	Menu();
	break;
	}
	case(10):
	{system("cls");
	Display_car();//ͨ����λ��ѯ����
	}
	case(5):
	{system("cls");
	change();

	}
	case(11):
	{
		shoubaoxiu();
	}
	}
}
void MenuB(string zhuhu)
{
	int c;
	do
	{
		cout << "��������������������������" << endl;
		cout << "| С����ҵ����ϵͳ(ס��) |" << endl;
		cout << "��������������������������" << endl;
		cout << "|     1���޸�ס����Ϣ    |" << endl;
		cout << "|     2����ѯס����Ϣ    |" << endl;
		cout << "|      3��������Ͷ��     |" << endl;
		cout << "|      4��������ҵ��     |" << endl;
		cout << "|      5������ͣ��λ     |" << endl;
		cout << "|      6���˳���¼       |" << endl;
		cout << "|      7���˳�ϵͳ       |" << endl;
		cout << "��������������������������" << endl;

		cout << "���������ָ��" << endl;
		cin >> c;
		if (!(c >= 1 && c <= 7))
		{
			cout << "��Чָ��,������1~7" << endl;
		}
		switch (c)//����ִ��1~7��ָ�� ��Ŀǰ�����1��7���� 
		{
		case(2):
		{
			system("cls");
			showsingle(zhuhu);
			break;
		}
		case(1):
		{
			system("cls");
			change(zhuhu);
			break;
		}
		case(3):
		{
			system("cls");
			repair_complain(zhuhu);
			break;
		}
		case(4):
		{
			system("cls");
			Jiaona(zhuhu);
		}
		case(6):
		{
			system("cls");
			cout << "�ɹ��˳���¼";
			Login();
		}
		case(7):
		{//����ʵ���˳�ϵͳ 
			exit(1);
		}
		case(5):
		{
			system("cls");
			carp(zhuhu);
		}
		}
	} while (1);

}
string HidenWrite(char character)//�β���������д�ɵ��ַ� 
{
	string s;
	char ch;
	ch = _getch();
	while (ch != '\n' && ch != '\r')//ֱ�����ֻس���ֹͣ 
	{
		_putch(character);//��������ַ� 
		s += ch;//��������ַ�����s�� 
		ch = _getch();
	}
	cout << endl;
	return s;//����s���� 

}

void Login()//��¼
{
	string account;//�˺�
	string account1;//�û�������Ա�˺Ź���
	string password;//����
	string temp = "0";//��Ϊ����Ĺ��ɣ�����ʵ��ס�������Զ���λ����
	stringstream password_s;//ʵ���Ǻ�����Ĺؼ�����
	stringstream account_s;
	int count = 0;//�����������Զ��˳�
	string getpassword;//����Ĺ��ɣ����ļ��л�ȡ����
	password_s.clear();//������Ĺ�����գ�ʹ��������
	cout << "�������˺�" << endl;
	cin >> account;
	account1 = account;//��Ϊ������Ҫaccount��Ϊ·���βΣ�������Ҫԭʼ����
	account_s << "d:\\" << account << ".txt";
	account_s >> account;
	fstream in(account, ios::in);
	if (account1 != "administer" && !fstream(account))//�ж��˺��Ƿ���ȷ
		do
		{
			account_s.clear();
			account.clear();

			cout << "�˺Ŵ��������������˺�" << endl;
			cin >> account;//�����˺�
			account1 = account;
			account_s << "d:\\" << account << ".txt";
			account_s >> account;
			fstream in(account);
		} while (account1 != "administer" && !fstream(account));//����ȷ��һֱѭ��
		if (account1 == "administer")//����Ա�˻����������ļ���Ԥ���
		{
			ifstream ifile("d:\\password.txt");
			ifile >> getpassword;//���ļ����ݱ��浽�ַ���
			cout << "����������" << endl;
			password = HidenWrite('*');//�Ǻ����
			if (!password.compare(getpassword) == 0)//������ļ���Ԥ��Ĳ�ͬ�����¼ʧ��
				do {
					if (count >= 4)
						exit(1);
					cout << "���������������������(" << 4 - count << "�λ��ᣩ" << endl;
					password = HidenWrite('*');//password��ȡд���ַ��� 
					count++;
				} while (!password.compare(getpassword) == 0);//�жϣ���������ļ���Ԥ���һ��ʱ���Խ���ϵͳ 
				//cout<<"���ļ��ж�ȡ��������"<<getpassword<<endl<<"�����������"<<password<<endl;
				cout << "������ȷ������Աϵͳ��½�ɹ�" << endl;
				Menu();
		}
		if (fstream(account))//�����˻����������ֻ���
		{
			ifstream In(account, ios::in);
			//cout << account;
			cout << "����������" << endl;
			password = HidenWrite('*');//password��ȡд���ַ��� 
			//temp = password;//���Ȼ�ȡ��������ס��ϵͳ�Ķ�λ����
			In >> getpassword;
			//cout << getpassword;
			//cout << getpassword << endl;
			if (!password.compare(getpassword) == 0)//������ļ���Ԥ��Ĳ�ͬ�����¼ʧ��
				do {
					if (count >= 4)
						exit(1);
					cout << "���������������������(" << 4 - count << "�λ��ᣩ" << endl;
					password = HidenWrite('*');//password��ȡд���ַ��� 
					count++;
				} while (!password.compare(getpassword) == 0);//�жϣ���������ļ���Ԥ���һ��ʱ���Խ���ϵͳ 
				//cout<<"���ļ��ж�ȡ��������"<<getpassword<<endl<<"�����������"<<password<<endl;
				cout << "������ȷ��ס��" << account1 << "��¼�ɹ�" << endl;
				MenuB(account);

		}
}
void InputHousehold(Household& hs)//����ס����Ϣ
{
	cout << "�����뷿��" << endl;
	cin >> hs.housenumber;
	cout << "������ס������" << endl;
	cin >> hs.name;
	cout << "�����뻧������" << endl;
	cin >> hs.hname;
	cout << "�������뻧����ϵ" << endl;
	cin >> hs.relationship;
	cout << "���������" << endl;
	cin >> hs.identity;
	cout << "������ְҵ" << endl;
	cin >> hs.job;
	cout << "�����뵥λλ��" << endl;
	cin >> hs.workplace;
	cout << "�������ֻ�����" << endl;
	cin >> hs.phonenumber;
	cout << "�����빤���绰" << endl;
	cin >> hs.workphonenumber;
	cout << "������QQ����" << endl;
	cin >> hs.QQ;
	cout << "�����복�ƺ�" << endl;
	cin >> hs.car_number;
	if (hs.relationship == "��������")
	{
		cout << "������Ӧ������ҵ��" << endl;
		cin >> hs.fee;
		cout << "������ʵ�ʽ�����ҵ��" << endl;
		cin >> hs.shiji;
	}

}
void InputCommuinty(Administrators  ad[])
{
	int i;
	cout << "������С������" << endl;
	cin >> ad[0].communityname;
	cout << "������¥����" << endl;
	cin >> ad[0].total_buildings;
	cout << "�������̻����" << endl;
	cin >> ad[0].green_square;
	cout << "������������ʩ" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> ad[i].supportingfacilities;
	}
	cout << "�����뽨�����" << endl;
	cin >> ad[0].building_square;
}
void Openfile(string fname, Household& hs)//���ļ���д���ļ�һ�廯����ǿ�ɶ��Ժͱ��Ч��
{
	if (fname == "d:\\househole.txt")
	{
		ofstream ofile(fname, ios::in | ios::app);
		ofile << hs.housenumber << " " << hs.name << " " << hs.hname << " " << hs.relationship << " " << hs.identity << " " << hs.job << " " << hs.workplace << "\t" << hs.phonenumber << " " << hs.workphonenumber << " " << hs.QQ << " " << hs.car_number;
		ofile << endl;
		ofile.close();
	}


}
void OpenFeefile(Household& hs)
{
	ofstream out("d:\\Fee.txt", ios::app);

	if (hs.relationship == "��������")
		out << hs.housenumber << " " << hs.hname << " " << hs.phonenumber << " " << hs.fee << " " << hs.shiji << endl;
}
void Openfile_a(string fname1, Administrators ad[])
{
	int i;
	ofstream ofile(fname1, ios::out);
	if (!ofile)
	{
		cout << "�������" << endl;
		exit(0);
	}
	ofile << "С�����ƣ�" << ad[0].communityname << endl;
	ofile << "¥������" << ad[0].total_buildings << endl;
	ofile << "�̻������" << ad[0].green_square << endl;
	ofile << "������ʩ��" << endl;
	for (i = 0; i <= n; i++)
	{

		ofile << ad[i].supportingfacilities << endl;

	}
	ofile << "���������" << ad[0].building_square << endl;
	ofile << endl;
	ofile.close();
}

string fpath(Household& hs)//���Զ���·����д�ɺ�������
{
	stringstream fname_s;//<sstream>�ַ������е�һ���÷������԰��ַ���ƴ��������Ϊ�ļ���ַ 
	string fname;

	if (hs.housenumber != "0")
	{
		fname_s << "d:\\" << hs.housenumber << ".txt";
		fname_s >> fname;
	}
	else
	{
		cin >> fname;
		fname_s << "d:\\" << fname << ".txt";
		fname_s >> fname;
	}
	return fname;
}
void CreateHousehold()//��ס����д���ļ��У����Ա��������� 
{
	Household hs;
	InputHousehold(hs);//����ס����Ϣ
	Openfile("d:\\househole.txt", hs);
	OpenFeefile(hs);
	if (hs.relationship == "��������")
	{
		ofstream out(fpath(hs));
		out << hs.phonenumber;
	}
	cout << "create complished!" << endl;//�����ж��Ƿ�д���ļ� 
	Menu(); //���д���������ǲ����ܷ����ļ���д�������ݣ����������ס����Ϣ�����ں����������У���������һ��Add�����������ס����Ϣ 
}
void CreateCommunity()//�޸ġ�����С����Ϣ
{
	Administrators* ad;
	ad = new Administrators[n];
	InputCommuinty(ad);
	Openfile_a("d:\\community.txt", ad);
	cout << "create complished" << endl;
	Menu();
}
void Show()//��ѯ������Ϣ
{
	Household hs[100];
	int n = -1;
	ifstream ifile("d:\\househole.txt");
	if (!ifile)
	{
		cout << "error" << endl;
		exit(0);
	}

	string check;
	do//��ȡ��Ϣ
	{
		n++;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].workphonenumber >> hs[n].QQ >> hs[n].car_number;
	} while (getline(ifile, check));
	cout << setw(15) << "����" << setw(15) << "ס������" << setw(15) << "��������" << setw(15) << "�뻧����ϵ" << setw(15) << "���" << setw(15) << "ְҵ" << setw(30) << "��λλ��" << setw(15) << "�ֻ�����" << setw(15) << "�����绰" << setw(15) << "QQ" << setw(15) << "���ƺ�" << endl;
	for (int i = 0; i < n; i++)
	{
		if (hs[i].housenumber != "0")
			cout << setw(15) << hs[i].housenumber << setw(15) << hs[i].name << setw(15) << hs[i].hname << setw(15) << hs[i].relationship << setw(15) << hs[i].identity << setw(15) << hs[i].job << setw(30) << hs[i].workplace << setw(15) << hs[i].phonenumber << setw(15) << hs[i].workphonenumber << setw(15) << hs[i].QQ << setw(15) << hs[i].car_number << endl;
	}
	Menu();
}
void Show_s()//��ѯС����Ϣ
{
	ifstream ifile("d:\\community.txt");
	if (!ifile)
	{
		cout << "error" << endl;
		exit(0);
	}
	string check;
	while (getline(ifile, check))//���ļ�����������뵽check ��
	{
		cout << check << endl;
	}
	ifile.close();
	Menu();

}
void Jiaona(string zhuhu)
{
	int i = 0;
	string a;
	string b = "d:\\fee.txt";
	string message1;
	message1 = zhuhu.substr(3);
	for (int i = 0; i <= 3; i++)
		message1.erase(message1.end() - 1);
	Household hs[100];
	int n = -1;
	string c;
	double count;
	ifstream ifile("d:\\fee.txt");
	if (!ifile)
	{
		cout << "error" << endl;
		exit(0);
	}
	string check;
	do//�жϽǱ�
	{
		n++;
		ifile >> hs[n].housenumber >> hs[n].hname >> hs[n].workphonenumber >> hs[n].fee >> hs[n].shiji;
	} while (getline(ifile, check) && hs[n].housenumber != "0");//�ж��ļ��Ƿ�������ҷ����ǲ���Ĭ��ֵ
	for (i = 0; i <= n; i++)
	{
		if (hs[i].housenumber == message1)//��ȡ�뷿��һֱ�ļ�¼�ĽǱ�i

			break;
	}

	if ((hs[i].fee - hs[i].shiji) > 0)//�ж��Ƿ���©�����
	{

		cout << "��Ŀǰδ���ɵ���ҵ��Ϊ" << hs[i].fee - hs[i].shiji << "Ԫ" << "���Ƿ�Ҫ���ɣ�YES or NO��" << endl;
		cin >> c;
		if (c == "YES")
		{
			cout << "��������ɽ��" << endl;
			cin >> count;
			if (count > hs[i].fee - hs[i].shiji)//�жϣ���ֹס����ǰ����
			{
				cout << "����������ɽ��˻�" << count - hs[i].fee + hs[i].shiji << "Ԫ" << endl;
				count = hs[i].fee - hs[i].shiji;
			}

			hs[i].shiji += count;
			ofstream ofile("d:\\fee.txt", ios::trunc);//���ԭ���ļ�
			ofstream o("d:\\fee.txt", ios::app);
			for (int index = 0; index <= n; index++)
			{

				o << hs[index].housenumber << " " << hs[index].hname << " " << hs[index].workphonenumber << " " << hs[index].fee << " " << hs[index].shiji << endl;

			}
			cout << "���ɳɹ�" << endl;
			MenuB(zhuhu);
		}
		else
		{
			MenuB(zhuhu);
		}

	}
	if ((hs[i].fee - hs[i].shiji) <= 0)
	{
		cout << "�����ò���" << endl;
		MenuB(zhuhu);
	}
}
void Delete()
{
	ifstream in("D:\\househole.txt", ios::in);//ԭ�ļ�
	ofstream out("D:\\househole2.txt", ios::trunc | ios::out);//�����ļ�
	ifstream ifile("D:\\car_parking.txt", ios::in);
	string del = "����", pass;
	string temp;//���ַ�����
	string name;
	string a[100];
	int judge = 1;
	//stringstream fname_s;//<sstream>�ַ������е�һ���÷������԰��ַ���ƴ��������Ϊ�ļ���ַ 
	Household hs[100];
	int n = -1;
	int i = 0;//ѭ���ж�
	int j = 0;
	string check;
	cout << "������Ҫɾ���ķ���:" << endl;
	cin >> pass;//����
	do//��ȡ��Ϣ
	{
		n++;
		in >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].QQ >> hs[n].workphonenumber >> hs[n].car_number;
	} while (getline(in, check) && hs[n].housenumber != "0");
	cout << "����������ɾ����������" << endl;
	for (int i = 0; i <= n; i++)
	{
		if (hs[i].housenumber == pass)
		{
			cout << hs[i].name << endl;
			a[j] = hs[i].name;
			j++;
		}
	}

	cin >> name;
	do
	{
		cin >> name;
		for (int i = 0; i <= j; i++)
		{
			if (name == a[i])
			{
				judge = 0;
				//cout << a[i];
			}

		}
		//cout << judge;
	} while (judge);
	for (i = 0; i <= n && hs[i].housenumber != "0"; i++)//�жϽǱ�
	{
		if (hs[i].name == name)
		{
			getline(in, temp);//����
			continue;
		}
		out << hs[i].housenumber << " " << hs[i].name << " " << hs[i].hname << " " << hs[i].relationship << " " << hs[i].identity << " " << hs[i].job << " " << hs[i].workplace << " " << hs[i].phonenumber << " " << hs[i].workphonenumber << " " << hs[i].QQ << " " << hs[i].car_number << endl;//��һ�µ�����д�������ļ����У�ע�⻻��
	}
	cout << "ɾ���ɹ�" << endl;
	in.close();//�ر���
	out.close();
	fstream outfile("D:\\househole.txt", ios::out);
	fstream infile("D:\\househole2.txt", ios::in);
	string ch;
	while (getline(infile, ch)) //�������ļ�������д��Դ�ļ�
	{
		outfile << ch << "\n";
	}
	outfile.close();//�ر���
	infile.close();
	Menu();
}
void repair_complain(string zhuhu)
{
	int a;
	int i = 0;
	string message1;
	string message2;//ɾͷȥβ
	message1 = zhuhu.substr(3);
	for (i = 0; i <= 3; i++)
		message1.erase(message1.end() - 1);
	cout << "��������Ҫ���޻���Ͷ��" << endl;
	cout << "���ޣ�1��" << "     " << "Ͷ�ߣ�2��" << endl;
	cin >> a;
	switch (a)
	{
	case(1):
	{
		ofstream  ofile("d://repair.txt", ios::app);
		if (!ofile)
		{
			cout << "������������½���" << endl;
			break;
		}
		cout << "�������걨����" << endl;
		cin >> message2;
		ofile << message1 << "\t" << message2 << endl;
		cout << "�걨�ɹ�" << endl;
		ofile.close();
		break;
	}
	case(2):
	{
		ofstream  ofile("d://complain.txt", ios::app);
		if (!ofile)
		{
			cout << "������������½���" << endl;
			break;
		}
		cout << "������Ͷ������" << endl;
		cin >> message2;
		ofile << message1 << "\t" << message2 << endl;
		cout << "Ͷ�߳ɹ�" << endl;
		ofile.close();
		break;
	}
	}
	MenuB(zhuhu);
}
void Fee()
{

	string judge;
	Household temp;
	Household hs[100];
	int n = -1;
	int i = 0;
	int j = 0;
	int k = 0;
	ifstream ifile("d:\\Fee.txt");
	if (!ifile)
	{
		cout << "error" << endl;
		exit(0);
	}
	string check;
	do//��ȡ��Ϣ
	{
		n++;
		ifile >> hs[n].housenumber >> hs[n].hname >> hs[n].workphonenumber >> hs[n].fee >> hs[n].shiji;
	} while (getline(ifile, check));
	system("cls");
	cout << "����" << "\t\t" << "��������" << "\t" << "�����ֻ�" << "\t\t" << "Ӧ������(Ԫÿ��)" << "\t" << "ʵ�ʽ���(Ԫÿ��)" << "\t" << "��Ƿ(Ԫÿ��)" << endl;
	for (int i = 0; i <= n && hs[i].housenumber != "0"; i++)
	{
		cout << hs[i].housenumber << "\t\t" << hs[i].hname << "\t\t" << hs[i].workphonenumber << "\t\t" << hs[i].fee << "\t\t\t" << hs[i].shiji << "\t\t\t" << hs[i].fee - hs[i].shiji << endl;
	}

	cout << "�Ƿ�ɸѡ��Ҫ������Ա(YES or NO)" << endl;
	cin >> judge;
	if (judge == "NO")
		Menu();
	if (judge == "YES")
	{
		for (j = 0; j <= n; j++)
			for (k = 0; k <= j; k++)
			{
				if ((hs[k].fee - hs[k].shiji) < (hs[k + 1].fee - hs[k + 1].shiji))
				{
					temp = hs[k];
					hs[k] = hs[k + 1];
					hs[k + 1] = temp;
				}
			}
		cout << "����" << "\t\t" << "��������" << "\t" << "�����ֻ�" << "\t\t" << "Ӧ������(Ԫÿ��)" << "\t" << "ʵ�ʽ���(Ԫÿ��)" << "\t" << "��Ƿ(Ԫÿ��)" << endl;
		for (i = 0; i < n; i++)
			cout << hs[i].housenumber << "\t\t" << hs[i].hname << "\t\t" << hs[i].workphonenumber << "\t\t" << hs[i].fee << "\t\t\t" << hs[i].shiji << "\t\t\t" << hs[i].fee - hs[i].shiji << endl;
		Menu();
	}
}

void carp(string zhuhu)
{
	string message1;
	message1 = zhuhu.substr(3);
	for (int i = 0; i <= 3; i++)
		message1.erase(message1.end() - 1);

	string carpark_number1;
	string carpark_number2;
	Household hs[100];
	string a[100];
	string b[100];
	int c[100];
	string d[100];//��ȡ�ض���ͥ�ĳ�������
	string check;
	int n = -1;
	string car;
	int judge = 1;
	int money;
	int j = 0;
	int i = 0;
	int m = 0;
	string Check;
	ofstream  ofile("d://car_parking.txt", ios::app);
	ifstream in("d://car_parking.txt", ios::in);
	ifstream ifile("d:\\househole.txt", ios::in);
	do//��ȡ��Ϣ
	{
		n++;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].workphonenumber >> hs[n].QQ >> hs[n].car_number;
	} while (getline(ifile, check));
	if (!ofile)
	{
		cout << "������������½���" << endl;
	}
	cout << "����������Ҫ����ĳ���" << endl;
	for (int i = 0; i <= n; i++)
	{
		if (hs[i].housenumber != "0" && hs[i].housenumber == message1 && hs[i].car_number != "û������")
		{
			cout << hs[i].car_number << endl;
			d[i] = hs[i].car_number;
		}
	}
	for (m = 0; m < 10; m++)
	{
		in >> a[m] >> b[m] >> c[m];
		//cout <<a[m]<<b[m]<<c[m]<<endl;
	}

	do//�ж�������Ƿ���ȷ����ȷ���ܽ��н������Ĳ���
	{
		cin >> car;
		for (int i = 0; i <= n; i++)
		{
			if (car == d[i])
			{
				judge = 0;//�ж�
				//cout << a[i];
			}

		}
		//cout << judge;
	} while (judge);
	for (i = 0; i < m; i++)
	{
		if (a[i] == car)
		{
			cout << "�������������λ������ʧ��" << endl;
			MenuB(zhuhu);
		}
	}
	for (i = 0; i < m; i++)
	{
		if (a[i]=="��")
		{
			cout << b[i]<<endl;

		}
	}
	cout << "��������Ҫ�����ͣ��λ��" << endl;
	cin >> carpark_number1;

	judge = 1;
	for (i = 0; i < m; i++)
	{
		if (b[i] == carpark_number1)
		{
			judge = 0;
			
		}
	}
	if (judge)
	{
		cout << "û�в�ѯ����ͣ��λ"<<endl;
		MenuB(zhuhu);
	}
	for (i = 0; i < m; i++)
	{
		if (b[i] == carpark_number1 && a[i] != "��")
		{
			cout << "����λ�ѱ����룬����ʧ��" << endl;
			MenuB(zhuhu);
		}
	}


	for (i = 0; i < m; i++)
	{
		if (carpark_number1 == b[i] && a[i] == "��")
		{
			break;
		}

	}
	for (i = 0; i < m; i++)
	{
		if (carpark_number1 == b[i])
		{
			break;
		}

	}
	//cout << i;
	a[i] = car;
	b[i] = carpark_number1;
	ofstream  out("d://car_parking.txt", ios::trunc);
	cout << "����������Ҫ���ɵĽ�1200Ԫÿ�꣩" << endl;
	cin >> money;
	if (money >= 1200 && money % 1200 == 0)
	{
		cout << "����ɹ�,����Ϊ" << car << "����" << carpark_number1 << "ͣ��λ" << money / 1200 << "��" << endl;
		c[i] = money / 1200;
		//cout << a[i] << b[i] << c[i];
		for (i = 0; i < m; i++)
		{
			out << a[i] << " " << b[i] << " " << c[i] << endl;
		}
	}
	else
	{
		cout << "����������ʧ��" << endl;
	}
	if (money >= 1200 && money % 1200 != 0)
	{
		int  money1 = money % 1200;
		cout << "����ɹ�,����Ϊ" << car << "����" << carpark_number1 << "ͣ��λ" << money / 1200 << "��" << endl;
		cout << "�˻�" << money1 << endl;
		c[i] = money / 1200;

		for (i = 0; i < m; i++)
		{
			out << a[i] << " " << b[i] << " " << c[i] << endl;
		}
	}


	ofile.close();
	MenuB(zhuhu);
}


void Display_car()
{
	string a[100];
	string b[100];
	string c[100];
	int m = 0;
	ifstream ifile("d:\\car_parking.txt");
	if (!ifile)
	{
		cout << "error" << endl;
		exit(0);
	}
	string check;

	for (m = 0; m < 100; m++)
	{
		ifile >> a[m] >> b[m] >> c[m];
		//cout <<a[m]<<b[m]<<c[m]<<endl;
	}
	cout << setw(10) << "���ƺ�" << setw(10) << "ͣ��λ" << setw(10) << "����" << endl;
	for (m = 0; m < 10; m++)
		if (a[m] != "��")
			cout << setw(10) << a[m] << setw(10) << b[m] << setw(10) << c[m] << endl;
	ifile.close();
	Menu();


}
void change()
{
	Household hs[100];//��ȡhousehole�ļ�
	Household hs1[100];//��ȡס���ļ�
	string c;
	int index = 0;
	int judge = 1;
	string name;
	int n = -1;
	string a[100];
	int m = -1;
	int j = 0;
	string check;
	ifstream ifile("d:\\househole.txt");
	ifstream Ifile("d:\\Fee.txt");
	do//��ȡ��Ϣ
	{
		n++;
		//	cout << n;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].QQ >> hs[n].workphonenumber >> hs[n].car_number;
	} while (getline(ifile, check));
	do//��ȡ��Ϣ
	{
		m++;
		//	cout << m;
		Ifile >> hs1[m].housenumber >> hs1[m].hname >> hs1[m].phonenumber >> hs1[m].fee >> hs1[m].shiji;
	} while (getline(Ifile, check));
	for (int i = 0; i <= m; i++)//������ֵ��֮�󷽱�Ƿ���ļ����޸ĺ���ļ�ͬ��
	{
		for (int j = 0; j <= n; j++)
		{
			if (hs[j].hname == hs[j].name && hs[j].housenumber == hs1[i].housenumber)
			{
				hs[j].fee = hs1[i].fee;
				hs[j].shiji = hs1[i].shiji;

			}

		}
	}
	cout << "��������Ҫ�޸ĵķ���" << endl;
	cin >> c;
	cout << "�����������޸ĵ�������" << endl;
	for (int i = 0; i <= n; i++)
	{
		if (hs[i].housenumber == c)
		{
			cout << hs[i].name << endl;
			a[j] = hs[i].name;
			j++;
		}
	}
	do
	{
		cin >> name;
		for (int i = 0; i <= j; i++)
		{
			if (name == a[i])
			{
				judge = 0;
				//cout << a[i];
			}

		}
		//cout << judge;
	} while (judge);

	for (int i = 0; i < n; i++)
	{
		if (hs[i].housenumber == c && hs[i].name == name)
		{
			cout << "��������Ҫ���ĵ���Ϣ" << endl;
			cout << "1 ����" << endl;
			cout << "2 ס������" << endl;
			cout << "3 ��������" << endl;
			cout << "4 �뻧����ϵ" << endl;
			cout << "5 ��� ְҵ" << endl;
			cout << "6 ��λλ��" << endl;
			cout << "7 �ֻ�����" << endl;
			cout << "8 �����绰" << endl;
			cout << "9 QQ����" << endl;
			cout << "10 ���ƺ�" << endl;
			cin >> index;
			switch (index)
			{
			case(1): {cout << "����" << endl;
				cin >> hs[i].housenumber;
				break;
			}
			case(2): {cout << "ס������" << endl;
				cin >> hs[i].name;
				break;
			}
			case(3): {cout << "��������" << endl;
				cin >> hs[i].hname;

				break;
			}
			case(4): {
				cout << "�뻧����ϵ" << endl;
				cin >> hs[i].relationship;
				break;
			}
			case(5): {cout << "���" << endl;
				cin >> hs[i].identity;
				cout << "ְҵ" << endl;
				cin >> hs[i].job;
				break;
			}
			case(6): {cout << "��λλ��" << endl;
				cin >> hs[i].workplace;
				break;
			}
			case(7): {cout << "�ֻ�����" << endl;
				cin >> hs[i].phonenumber;
				break;
			}
			case(8): {cout << "�����绰" << endl;
				cin >> hs[i].workphonenumber;
				break;
			}
			case(9): {cout << "QQ����" << endl;
				cin >> hs[i].QQ;
				break;
			}
			case(10): {cout << "���ƺ�" << endl;
				cin >> hs[i].car_number;
				break;
			}
			}
			if (hs[i].relationship == "��������")
			{
				cout << "������Ӧ������ҵ��" << endl;
				cin >> hs[i].fee;
				cout << "������ʵ�ʽ�����ҵ��" << endl;
				cin >> hs[i].shiji;
				ofstream out("d:\\Fee.txt", ios::trunc);//���ԭ���ļ�
				ofstream Out("d:\\Fee.txt", ios::app);
				for (int i = 0; i <= n; i++)
				{
					if (hs[i].name == hs[i].hname)
						out << hs[i].housenumber << " " << hs[i].hname << " " << hs[i].phonenumber << " " << hs[i].fee << " " << hs[i].shiji << endl;
				}
			}
		}
	}


	ofstream ofile("d:\\househole.txt", ios::trunc);//���ԭ���ļ�
	ofstream Ofile("d:\\househole.txt", ios::app);
	for (int i = 0; i <= n; i++)
	{

		Ofile << hs[i].housenumber << " " << hs[i].name << " " << hs[i].hname << " " << hs[i].relationship << " " << hs[i].identity << " " << hs[i].job << " " << hs[i].workplace << " " << hs[i].phonenumber << " " << hs[i].workphonenumber << " " << hs[i].QQ << " " << hs[i].car_number << endl;

	}

	Menu();
}
void change(string zhuhu)
{
	Household hs[100];//��ȡhousehole�ļ�
	Household hs1[100];//��ȡס���ļ�
	string c;
	string message1;
	message1 = zhuhu.substr(3);
	for (int i = 0; i <= 3; i++)
		message1.erase(message1.end() - 1);
	string a[100];
	int index = 0;
	string name;
	int n = -1;
	int m = -1;
	int j = 0;
	int judge = 1;
	string check;
	ifstream ifile("d:\\househole.txt");
	ifstream Ifile("d:\\Fee.txt");
	do//��ȡ��Ϣ
	{
		n++;
		//	cout << n;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].QQ >> hs[n].workphonenumber >> hs[n].car_number;
	} while (getline(ifile, check));
	do//��ȡ��Ϣ
	{
		m++;
		//	cout << m;
		Ifile >> hs1[m].housenumber >> hs1[m].hname >> hs1[m].phonenumber >> hs1[m].fee >> hs1[m].shiji;
	} while (getline(Ifile, check));
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (hs[j].hname == hs[j].name && hs[j].housenumber == hs1[i].housenumber)//��fee�е���Ϣ�����ȶ��ж�д��househole��
			{
				hs[j].fee = hs1[i].fee;
				hs[j].shiji = hs1[i].shiji;

			}

		}
	}

	cout << "�����������޸ĵ�������" << endl;
	for (int i = 0; i <= n; i++)
	{
		if (hs[i].housenumber == message1)
		{
			cout << hs[i].name << endl;
			a[j] = hs[i].name;
			j++;
		}
	}
	do
	{
		cin >> name;
		for (int i = 0; i <= j; i++)
		{
			if (name == a[i])
			{
				judge = 0;
				//cout << a[i];
			}

		}
		//cout << judge;
	} while (judge);
	for (int i = 0; i < n; i++)
	{
		if (hs[i].housenumber == message1 && hs[i].name == name)
		{
			cout << "��������Ҫ���ĵ���Ϣ" << endl;
			cout << "1 ����" << endl;
			cout << "2 ס������" << endl;
			cout << "3 ��������" << endl;
			cout << "4 �뻧����ϵ" << endl;
			cout << "5 ��� ְҵ" << endl;
			cout << "6 ��λλ��" << endl;
			cout << "7 �ֻ�����" << endl;
			cout << "8 �����绰" << endl;
			cout << "9 QQ����" << endl;
			cout << "10 ���ƺ�" << endl;
			cin >> index;
			switch (index)
			{
			case(1): {cout << "����" << endl;
				cin >> hs[i].housenumber;
				break;
			}
			case(2): {cout << "ס������" << endl;
				cin >> hs[i].name;
				break;
			}
			case(3): {cout << "��������" << endl;
				cin >> hs[i].hname;

				break;
			}
			case(4): {
				cout << "�뻧����ϵ" << endl;
				cin >> hs[i].relationship;
				break;
			}
			case(5): {cout << "���" << endl;
				cin >> hs[i].identity;
				cout << "ְҵ" << endl;
				cin >> hs[i].job;
				break;
			}
			case(6): {cout << "��λλ��" << endl;
				cin >> hs[i].workplace;
				break;
			}
			case(7): {cout << "�ֻ�����" << endl;
				cin >> hs[i].phonenumber;
				break;
			}
			case(8): {cout << "�����绰" << endl;
				cin >> hs[i].workphonenumber;
				break;
			}
			case(9): {cout << "QQ����" << endl;
				cin >> hs[i].QQ;
				break;
			}
			case(10): {cout << "���ƺ�" << endl;
				cin >> hs[i].car_number;
				break;
			}
			}
			if (hs[i].relationship == "��������")
			{
				cout << "������Ӧ������ҵ��" << endl;
				cin >> hs[i].fee;
				cout << "������ʵ�ʽ�����ҵ��" << endl;
				cin >> hs[i].shiji;
				ofstream out("d:\\Fee.txt", ios::trunc);//���ԭ���ļ�
				ofstream Out("d:\\Fee.txt", ios::app);
				for (int i = 0; i <= n; i++)
				{
					if (hs[i].name == hs[i].hname)
						out << hs[i].housenumber << " " << hs[i].hname << " " << hs[i].phonenumber << " " << hs[i].fee << " " << hs[i].shiji << endl;
				}
			}
		}
	}


	ofstream ofile("d:\\househole.txt", ios::trunc);//���ԭ���ļ�
	ofstream Ofile("d:\\househole.txt", ios::app);
	for (int i = 0; i <= n; i++)
	{

		Ofile << hs[i].housenumber << " " << hs[i].name << " " << hs[i].hname << " " << hs[i].relationship << " " << hs[i].identity << " " << hs[i].job << " " << hs[i].workplace << " " << hs[i].phonenumber << " " << hs[i].workphonenumber << " " << hs[i].QQ << " " << hs[i].car_number << endl;

	}

	MenuB(zhuhu);
}
void showsingle()
{

	Household hs[100];//��ȡhousehole�ļ�
	string c;
	string name;
	int n = -1;
	string check;
	ifstream ifile("d:\\househole.txt");
	do//��ȡ��Ϣ
	{
		n++;
		//	cout << n;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].QQ >> hs[n].workphonenumber >> hs[n].car_number;
	} while (getline(ifile, check));
	cout << "��������Ҫ��ѯ�ķ���" << endl;
	cin >> c;
	cout << setw(15) << "����" << setw(15) << "ס������" << setw(15) << "��������" << setw(15) << "�뻧����ϵ" << setw(15) << "���" << setw(15) << "ְҵ" << setw(30) << "��λλ��" << setw(15) << "�ֻ�����" << setw(15) << "�����绰" << setw(15) << "QQ" << setw(15) << "���ƺ�" << setw(15) << endl;
	for (int i = 0; i <= n; i++)
	{
		if (hs[i].housenumber == c)
			cout << setw(15) << hs[i].housenumber << setw(15) << hs[i].name << setw(15) << hs[i].hname << setw(15) << hs[i].relationship << setw(15) << hs[i].identity << setw(15) << hs[i].job << setw(30) << hs[i].workplace << setw(15) << hs[i].phonenumber << setw(15) << hs[i].workphonenumber << setw(15) << hs[i].QQ << setw(15) << hs[i].car_number << endl;
	}
	Menu();
}
void showsingle(string zhuhu)
{

	Household hs[100];//��ȡhousehole�ļ�
	string message1;//��Ϊ·���Ĺ���
	message1 = zhuhu.substr(3);
	for (int i = 0; i <= 3; i++)
		message1.erase(message1.end() - 1);//��÷���
	string name;
	int n = -1;
	string check;
	ifstream ifile("d:\\househole.txt");
	do//��ȡ��Ϣ
	{
		n++;
		//	cout << n;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].QQ >> hs[n].workphonenumber >> hs[n].car_number;
	} while (getline(ifile, check));
	cout << setw(15) << "����" << setw(15) << "ס������" << setw(15) << "��������" << setw(15) << "�뻧����ϵ" << setw(15) << "���" << setw(15) << "ְҵ" << setw(30) << "��λλ��" << setw(15) << "�ֻ�����" << setw(15) << "�����绰" << setw(15) << "QQ" << setw(15) << "���ƺ�" << endl;
	for (int i = 0; i <= n; i++)
	{
		if (hs[i].housenumber == message1)
			cout << setw(15) << hs[i].housenumber << setw(15) << hs[i].name << setw(15) << hs[i].hname << setw(15) << hs[i].relationship << setw(15) << hs[i].identity << setw(15) << hs[i].job << setw(30) << hs[i].workplace << setw(15) << hs[i].phonenumber << setw(15) << hs[i].workphonenumber << setw(15) << hs[i].QQ << setw(15) << hs[i].car_number << endl;
	}
	MenuB(zhuhu);
}
void shoubaoxiu()
{
	ifstream Ifile("d:\\repair.txt");
	ifstream ifile("d:\\complain.txt");
	if (!ifile)
	{
		cout << "error" << endl;

	}
	string check;
	cout << "Ͷ��" << endl;
	while (getline(ifile, check))//���ļ�����������뵽check ��
	{
		cout << check << endl;
	}
	ifile.close();

	if (!Ifile)
	{
		cout << "error" << endl;

	}
	string Check;
	cout << "����" << endl;
	while (getline(Ifile, Check))//���ļ�����������뵽Check ��
	{
		cout << Check << endl;
	}
	Ifile.close();
	Menu();


}
void car_search()//ͨ�����ƺŲ�ѯ����
{
	Household hs[100];
	string a;
	string check;
	ifstream ifile("d:\\househole.txt");
	if (!ifile)
	{
		cout << "���������µ�¼" << endl;
		exit(0);
	}
	int n = -1;
	int i = 0;
	cout << "����Ҫ��ѯ�ĳ��ƺţ�" << endl;
	cin >> a;
	do//��ȡ��Ϣ
	{
		n++;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].workphonenumber >> hs[n].QQ >> hs[n].car_number;
	} while (getline(ifile, check));
	for (i = 0; i <= n; i++)//�жϽǱ�
	{
		if (hs[i].car_number == a)
		{
			cout << "����" << hs[i].car_number << endl;
			cout << "���ţ�" << hs[i].housenumber << endl;
			cout << "����������" << hs[i].name << endl;
			cout << "�����ֻ�:" << hs[i].phonenumber << endl;
			Menu();
		}
	}

	cout << "δ��ѯ��" << endl;
	Menu();


}