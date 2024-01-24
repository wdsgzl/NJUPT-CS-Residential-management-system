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
	string housenumber;//栋-单元-房号
	string name;//姓名
	string hname;//户主姓名
	string identity;//身份
	string relationship;//与户主关系
	string job;//职业
	string workplace;//工作地点
	string phonenumber;//手机号码
	string workphonenumber;//工作电话
	string QQ;//QQ
	string car_number;//车辆编号
	double fee;//应缴物业费用
	double shiji;//实际缴纳
	double owe;//欠费
public:
	Household()
	{
		housenumber = "0";
		name = "请输入姓名";
		hname = "请输入户主姓名";
		identity = "请输入身份";
		relationship = "户主本人";
		job = "请输入职业";
		workplace = "请输入单位";
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
	friend void CreateHousehold();//管理员创建/添加住户
	friend void InputHousehold(Household& hs);//输入信息
	friend void Openfile(string fname, Household& hs);//打开目标文件，并写入内容
	friend string fpath(Household& hs);//将字符串转变为文件路径
	friend void OpenFeefile(Household& hs);//建立欠款文件夹
	friend void Fee();//查询欠款
	friend void Show();//查询所有住户信息
	friend void Delete();//管理员删除
	friend void Jiaona(string zhuhu);//住户缴纳欠款
	friend void car_search();//管理员查询车辆
	friend void change();//管理员修改住户信息
	friend void  showsingle();//管理员查询单独住户信息
	friend void showsingle(string zhuhu);//住户查询自个家里信息
	friend void change(string zhuhu);//住户修改自个家里信息
	friend void carp(string zhuhu);
};
class Administrators
{
private:
	string communityname;//小区名称
	string total_buildings;//建筑总量
	string green_square;//绿化面积
	string  supportingfacilities;//配套设施
	string building_square;//建筑面积
public:
	Administrators()
	{

		communityname = "小区名称";
		total_buildings = "0";
		green_square = "0";
		supportingfacilities = "配套设施";
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

	friend void CreateCommunity();//创建/打开小区文件夹
	friend  void Openfile_a(string fname1, Administrators ad[]);//将小区信息写入文件
	friend void InputCommuinty(Administrators ad[]);//输入小区信息

};
void CreateHousehold();
void CreateCommunity();
void InputHousehold(Household& hs);
void InputCommuinty(Administrators ad[]);
void Search();
void Show();//展示所有信息
//void Show(string zhuhu);
void Show_s();
void Openfile(string fname, Household& hs);
void Openfile_a(string fname1, Administrators ad[]);
string fpath(Household& hs);
void Delete();
void Fee();
void OpenFeefile(Household& hs);
void repair_complain(string zhuhu);//投诉和保修
void Jiaona(string zhuhu);
void car_search();
void Display_car();//通过车位查询房号
void carp(string zhuhu);//申请停车位
void change();
void showsingle();//管理员查询
void showsingle(string zhuhu);//住户查询
void change(string zhuhu);
void shoubaoxiu();
int main()
{
	Login();
}
void Menu()
{
	cout << "—————————————" << endl;
	cout << "|小区物业管理系统(管理员)|" << endl;
	cout << "—————————————" << endl;
	cout << "|     1、添加住户信息    |" << endl;
	cout << "|   2、查询所有住户信息  |" << endl;
	cout << "|   3、查询单个住户信息  |" << endl;
	cout << "|     4、删除住户信息    |" << endl;
	cout << "|     5、修改住户信息    |" << endl;
	cout << "|     6、查询社区信息    |" << endl;
	cout << "|     7、修改社区信息    |" << endl;
	cout << "|     8、查询车牌号      |" << endl;
	cout << "|     9、查询物业费      |" << endl;
	cout << "|     10、查询停车位     |" << endl;
	cout << "|   11、查询保修与投诉   |" << endl;
	cout << "|      12、退出登录      |" << endl;
	cout << "|      13、退出系统      |" << endl;
	cout << "—————————————" << endl;
	int c;
	cout << "请输入操作指令" << endl;
	cin >> c;
	if (!(c >= 1 && c <= 13))
	{
		cout << "无效指令" << endl;
		Menu();
	}
	switch (c)//用于执行1~7号指令 ，目前已完成1，7命令 
	{
	case(1):
	{
		system("cls");
		CreateHousehold();//本条实现创建新用户
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
	{system("cls");//本条实现删除用户数据
	Delete();
	break;
	}
	case(6):
	{system("cls");
	Show_s();
	}
	case(7):
	{system("cls");//本条实现社区的信息输入和修改
	cout << "输入配套设施的数目" << endl;
	cin >> ::n;
	CreateCommunity();
	break;
	}
	case(12): {system("cls");
		cout << "成功退出登录";
		Login();
	}
	case(13):
	{system("cls");//本条实现退出系统 
	exit(1);
	}
	case(9):
	{system("cls");
	Fee();//查询物业费情况
	break;
	}
	case(8):
	{system("cls");
	car_search();//查询车辆
	Menu();
	break;
	}
	case(10):
	{system("cls");
	Display_car();//通过车位查询房号
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
		cout << "—————————————" << endl;
		cout << "| 小区物业管理系统(住户) |" << endl;
		cout << "—————————————" << endl;
		cout << "|     1、修改住户信息    |" << endl;
		cout << "|     2、查询住户信息    |" << endl;
		cout << "|      3、报修与投诉     |" << endl;
		cout << "|      4、缴纳物业费     |" << endl;
		cout << "|      5、申请停车位     |" << endl;
		cout << "|      6、退出登录       |" << endl;
		cout << "|      7、退出系统       |" << endl;
		cout << "—————————————" << endl;

		cout << "请输入操作指令" << endl;
		cin >> c;
		if (!(c >= 1 && c <= 7))
		{
			cout << "无效指令,请输入1~7" << endl;
		}
		switch (c)//用于执行1~7号指令 ，目前已完成1，7命令 
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
			cout << "成功退出登录";
			Login();
		}
		case(7):
		{//本条实现退出系统 
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
string HidenWrite(char character)//形参是密码隐写成的字符 
{
	string s;
	char ch;
	ch = _getch();
	while (ch != '\n' && ch != '\r')//直到出现回车就停止 
	{
		_putch(character);//输出隐藏字符 
		s += ch;//将输入的字符读入s中 
		ch = _getch();
	}
	cout << endl;
	return s;//返回s数组 

}

void Login()//登录
{
	string account;//账号
	string account1;//用户，管理员账号过渡
	string password;//密码
	string temp = "0";//作为密码的过渡，用于实现住户界面自动定位房号
	stringstream password_s;//实现星号输出的关键变量
	stringstream account_s;
	int count = 0;//五次输入错误自动退出
	string getpassword;//密码的过渡，从文件中获取密码
	password_s.clear();//将密码的过渡清空，使其多次利用
	cout << "请输入账号" << endl;
	cin >> account;
	account1 = account;//因为后面需要account作为路径形参，所以需要原始过渡
	account_s << "d:\\" << account << ".txt";
	account_s >> account;
	fstream in(account, ios::in);
	if (account1 != "administer" && !fstream(account))//判断账号是否正确
		do
		{
			account_s.clear();
			account.clear();

			cout << "账号错误，请重新输入账号" << endl;
			cin >> account;//输入账号
			account1 = account;
			account_s << "d:\\" << account << ".txt";
			account_s >> account;
			fstream in(account);
		} while (account1 != "administer" && !fstream(account));//不正确则一直循环
		if (account1 == "administer")//管理员账户，密码是文件中预设的
		{
			ifstream ifile("d:\\password.txt");
			ifile >> getpassword;//将文件内容保存到字符串
			cout << "请输入密码" << endl;
			password = HidenWrite('*');//星号输出
			if (!password.compare(getpassword) == 0)//如果与文件中预设的不同，则登录失败
				do {
					if (count >= 4)
						exit(1);
					cout << "密码错误，请重新输入密码(" << 4 - count << "次机会）" << endl;
					password = HidenWrite('*');//password读取写入字符串 
					count++;
				} while (!password.compare(getpassword) == 0);//判断，当密码和文件中预设得一样时可以进入系统 
				//cout<<"从文件中读取的密码是"<<getpassword<<endl<<"输入的密码是"<<password<<endl;
				cout << "密码正确，管理员系统登陆成功" << endl;
				Menu();
		}
		if (fstream(account))//居民账户，密码是手机号
		{
			ifstream In(account, ios::in);
			//cout << account;
			cout << "请输入密码" << endl;
			password = HidenWrite('*');//password读取写入字符串 
			//temp = password;//首先获取密码用于住户系统的定位房号
			In >> getpassword;
			//cout << getpassword;
			//cout << getpassword << endl;
			if (!password.compare(getpassword) == 0)//如果与文件中预设的不同，则登录失败
				do {
					if (count >= 4)
						exit(1);
					cout << "密码错误，请重新输入密码(" << 4 - count << "次机会）" << endl;
					password = HidenWrite('*');//password读取写入字符串 
					count++;
				} while (!password.compare(getpassword) == 0);//判断，当密码和文件中预设得一样时可以进入系统 
				//cout<<"从文件中读取的密码是"<<getpassword<<endl<<"输入的密码是"<<password<<endl;
				cout << "密码正确，住户" << account1 << "登录成功" << endl;
				MenuB(account);

		}
}
void InputHousehold(Household& hs)//输入住户信息
{
	cout << "请输入房号" << endl;
	cin >> hs.housenumber;
	cout << "请输入住户姓名" << endl;
	cin >> hs.name;
	cout << "请输入户主姓名" << endl;
	cin >> hs.hname;
	cout << "请输入与户主关系" << endl;
	cin >> hs.relationship;
	cout << "请输入身份" << endl;
	cin >> hs.identity;
	cout << "请输入职业" << endl;
	cin >> hs.job;
	cout << "请输入单位位置" << endl;
	cin >> hs.workplace;
	cout << "请输入手机号码" << endl;
	cin >> hs.phonenumber;
	cout << "请输入工作电话" << endl;
	cin >> hs.workphonenumber;
	cout << "请输入QQ号码" << endl;
	cin >> hs.QQ;
	cout << "请输入车牌号" << endl;
	cin >> hs.car_number;
	if (hs.relationship == "户主本人")
	{
		cout << "请输入应缴纳物业费" << endl;
		cin >> hs.fee;
		cout << "请输入实际缴纳物业费" << endl;
		cin >> hs.shiji;
	}

}
void InputCommuinty(Administrators  ad[])
{
	int i;
	cout << "请输入小区名称" << endl;
	cin >> ad[0].communityname;
	cout << "请输入楼总数" << endl;
	cin >> ad[0].total_buildings;
	cout << "请输入绿化面积" << endl;
	cin >> ad[0].green_square;
	cout << "请输入配套设施" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> ad[i].supportingfacilities;
	}
	cout << "请输入建筑面积" << endl;
	cin >> ad[0].building_square;
}
void Openfile(string fname, Household& hs)//打开文件加写入文件一体化，增强可读性和编程效率
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

	if (hs.relationship == "户主本人")
		out << hs.housenumber << " " << hs.hname << " " << hs.phonenumber << " " << hs.fee << " " << hs.shiji << endl;
}
void Openfile_a(string fname1, Administrators ad[])
{
	int i;
	ofstream ofile(fname1, ios::out);
	if (!ofile)
	{
		cout << "程序错误" << endl;
		exit(0);
	}
	ofile << "小区名称：" << ad[0].communityname << endl;
	ofile << "楼总数：" << ad[0].total_buildings << endl;
	ofile << "绿化面积：" << ad[0].green_square << endl;
	ofile << "配套设施：" << endl;
	for (i = 0; i <= n; i++)
	{

		ofile << ad[i].supportingfacilities << endl;

	}
	ofile << "建筑面积：" << ad[0].building_square << endl;
	ofile << endl;
	ofile.close();
}

string fpath(Household& hs)//把自定义路径名写成函数体了
{
	stringstream fname_s;//<sstream>字符串流中的一种用法，可以把字符串拼起来，作为文件地址 
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
void CreateHousehold()//将住户类写到文件中，可以保存无限条 
{
	Household hs;
	InputHousehold(hs);//输入住户信息
	Openfile("d:\\househole.txt", hs);
	OpenFeefile(hs);
	if (hs.relationship == "户主本人")
	{
		ofstream out(fpath(hs));
		out << hs.phonenumber;
	}
	cout << "create complished!" << endl;//便于判断是否写入文件 
	Menu(); //本行代码得意义是测是能否向文件中写入多个数据（类似于添加住户信息），在后续的完善中，单独建立一个Add函数用于添加住户信息 
}
void CreateCommunity()//修改、创建小区信息
{
	Administrators* ad;
	ad = new Administrators[n];
	InputCommuinty(ad);
	Openfile_a("d:\\community.txt", ad);
	cout << "create complished" << endl;
	Menu();
}
void Show()//查询所有信息
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
	do//读取信息
	{
		n++;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].workphonenumber >> hs[n].QQ >> hs[n].car_number;
	} while (getline(ifile, check));
	cout << setw(15) << "房号" << setw(15) << "住户姓名" << setw(15) << "户主姓名" << setw(15) << "与户主关系" << setw(15) << "身份" << setw(15) << "职业" << setw(30) << "单位位置" << setw(15) << "手机号码" << setw(15) << "工作电话" << setw(15) << "QQ" << setw(15) << "车牌号" << endl;
	for (int i = 0; i < n; i++)
	{
		if (hs[i].housenumber != "0")
			cout << setw(15) << hs[i].housenumber << setw(15) << hs[i].name << setw(15) << hs[i].hname << setw(15) << hs[i].relationship << setw(15) << hs[i].identity << setw(15) << hs[i].job << setw(30) << hs[i].workplace << setw(15) << hs[i].phonenumber << setw(15) << hs[i].workphonenumber << setw(15) << hs[i].QQ << setw(15) << hs[i].car_number << endl;
	}
	Menu();
}
void Show_s()//查询小区信息
{
	ifstream ifile("d:\\community.txt");
	if (!ifile)
	{
		cout << "error" << endl;
		exit(0);
	}
	string check;
	while (getline(ifile, check))//将文件里的数据输入到check 里
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
	do//判断角标
	{
		n++;
		ifile >> hs[n].housenumber >> hs[n].hname >> hs[n].workphonenumber >> hs[n].fee >> hs[n].shiji;
	} while (getline(ifile, check) && hs[n].housenumber != "0");//判断文件是否结束并且房号是不是默认值
	for (i = 0; i <= n; i++)
	{
		if (hs[i].housenumber == message1)//获取与房号一直的记录的角标i

			break;
	}

	if ((hs[i].fee - hs[i].shiji) > 0)//判断是否有漏缴情况
	{

		cout << "您目前未缴纳的物业费为" << hs[i].fee - hs[i].shiji << "元" << "您是否要缴纳（YES or NO）" << endl;
		cin >> c;
		if (c == "YES")
		{
			cout << "请输入缴纳金额" << endl;
			cin >> count;
			if (count > hs[i].fee - hs[i].shiji)//判断，防止住户超前缴纳
			{
				cout << "超出所需缴纳金额，退回" << count - hs[i].fee + hs[i].shiji << "元" << endl;
				count = hs[i].fee - hs[i].shiji;
			}

			hs[i].shiji += count;
			ofstream ofile("d:\\fee.txt", ios::trunc);//清空原有文件
			ofstream o("d:\\fee.txt", ios::app);
			for (int index = 0; index <= n; index++)
			{

				o << hs[index].housenumber << " " << hs[index].hname << " " << hs[index].workphonenumber << " " << hs[index].fee << " " << hs[index].shiji << endl;

			}
			cout << "缴纳成功" << endl;
			MenuB(zhuhu);
		}
		else
		{
			MenuB(zhuhu);
		}

	}
	if ((hs[i].fee - hs[i].shiji) <= 0)
	{
		cout << "您不用补缴" << endl;
		MenuB(zhuhu);
	}
}
void Delete()
{
	ifstream in("D:\\househole.txt", ios::in);//原文件
	ofstream out("D:\\househole2.txt", ios::trunc | ios::out);//过渡文件
	ifstream ifile("D:\\car_parking.txt", ios::in);
	string del = "房号", pass;
	string temp;//空字符跳行
	string name;
	string a[100];
	int judge = 1;
	//stringstream fname_s;//<sstream>字符串流中的一种用法，可以把字符串拼起来，作为文件地址 
	Household hs[100];
	int n = -1;
	int i = 0;//循环判断
	int j = 0;
	string check;
	cout << "输入想要删除的房号:" << endl;
	cin >> pass;//房号
	do//读取信息
	{
		n++;
		in >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].QQ >> hs[n].workphonenumber >> hs[n].car_number;
	} while (getline(in, check) && hs[n].housenumber != "0");
	cout << "请输入你想删除的人姓名" << endl;
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
	for (i = 0; i <= n && hs[i].housenumber != "0"; i++)//判断角标
	{
		if (hs[i].name == name)
		{
			getline(in, temp);//跳行
			continue;
		}
		out << hs[i].housenumber << " " << hs[i].name << " " << hs[i].hname << " " << hs[i].relationship << " " << hs[i].identity << " " << hs[i].job << " " << hs[i].workplace << " " << hs[i].phonenumber << " " << hs[i].workphonenumber << " " << hs[i].QQ << " " << hs[i].car_number << endl;//不一致的内容写到过渡文件中中，注意换行
	}
	cout << "删除成功" << endl;
	in.close();//关闭流
	out.close();
	fstream outfile("D:\\househole.txt", ios::out);
	fstream infile("D:\\househole2.txt", ios::in);
	string ch;
	while (getline(infile, ch)) //将过渡文件的内容写到源文件
	{
		outfile << ch << "\n";
	}
	outfile.close();//关闭流
	infile.close();
	Menu();
}
void repair_complain(string zhuhu)
{
	int a;
	int i = 0;
	string message1;
	string message2;//删头去尾
	message1 = zhuhu.substr(3);
	for (i = 0; i <= 3; i++)
		message1.erase(message1.end() - 1);
	cout << "请问您需要保修还是投诉" << endl;
	cout << "保修（1）" << "     " << "投诉（2）" << endl;
	cin >> a;
	switch (a)
	{
	case(1):
	{
		ofstream  ofile("d://repair.txt", ios::app);
		if (!ofile)
		{
			cout << "程序错误，请重新进入" << endl;
			break;
		}
		cout << "请输入申报内容" << endl;
		cin >> message2;
		ofile << message1 << "\t" << message2 << endl;
		cout << "申报成功" << endl;
		ofile.close();
		break;
	}
	case(2):
	{
		ofstream  ofile("d://complain.txt", ios::app);
		if (!ofile)
		{
			cout << "程序错误，请重新进入" << endl;
			break;
		}
		cout << "请输入投诉内容" << endl;
		cin >> message2;
		ofile << message1 << "\t" << message2 << endl;
		cout << "投诉成功" << endl;
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
	do//读取信息
	{
		n++;
		ifile >> hs[n].housenumber >> hs[n].hname >> hs[n].workphonenumber >> hs[n].fee >> hs[n].shiji;
	} while (getline(ifile, check));
	system("cls");
	cout << "房号" << "\t\t" << "户主姓名" << "\t" << "户主手机" << "\t\t" << "应当缴纳(元每年)" << "\t" << "实际缴纳(元每年)" << "\t" << "拖欠(元每年)" << endl;
	for (int i = 0; i <= n && hs[i].housenumber != "0"; i++)
	{
		cout << hs[i].housenumber << "\t\t" << hs[i].hname << "\t\t" << hs[i].workphonenumber << "\t\t" << hs[i].fee << "\t\t\t" << hs[i].shiji << "\t\t\t" << hs[i].fee - hs[i].shiji << endl;
	}

	cout << "是否筛选需要补缴人员(YES or NO)" << endl;
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
		cout << "房号" << "\t\t" << "户主姓名" << "\t" << "户主手机" << "\t\t" << "应当缴纳(元每年)" << "\t" << "实际缴纳(元每年)" << "\t" << "拖欠(元每年)" << endl;
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
	string d[100];//获取特定家庭的车辆号码
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
	do//读取信息
	{
		n++;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].workphonenumber >> hs[n].QQ >> hs[n].car_number;
	} while (getline(ifile, check));
	if (!ofile)
	{
		cout << "程序错误，请重新进入" << endl;
	}
	cout << "请输入你需要申请的车辆" << endl;
	for (int i = 0; i <= n; i++)
	{
		if (hs[i].housenumber != "0" && hs[i].housenumber == message1 && hs[i].car_number != "没有汽车")
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

	do//判断输入的是否正确，正确才能进行接下来的操作
	{
		cin >> car;
		for (int i = 0; i <= n; i++)
		{
			if (car == d[i])
			{
				judge = 0;//判断
				//cout << a[i];
			}

		}
		//cout << judge;
	} while (judge);
	for (i = 0; i < m; i++)
	{
		if (a[i] == car)
		{
			cout << "本车已申请过车位，申请失败" << endl;
			MenuB(zhuhu);
		}
	}
	for (i = 0; i < m; i++)
	{
		if (a[i]=="无")
		{
			cout << b[i]<<endl;

		}
	}
	cout << "请输入需要申请的停车位：" << endl;
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
		cout << "没有查询到该停车位"<<endl;
		MenuB(zhuhu);
	}
	for (i = 0; i < m; i++)
	{
		if (b[i] == carpark_number1 && a[i] != "无")
		{
			cout << "本车位已被申请，申请失败" << endl;
			MenuB(zhuhu);
		}
	}


	for (i = 0; i < m; i++)
	{
		if (carpark_number1 == b[i] && a[i] == "无")
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
	cout << "请输入您想要缴纳的金额（1200元每年）" << endl;
	cin >> money;
	if (money >= 1200 && money % 1200 == 0)
	{
		cout << "申请成功,您已为" << car << "申请" << carpark_number1 << "停车位" << money / 1200 << "年" << endl;
		c[i] = money / 1200;
		//cout << a[i] << b[i] << c[i];
		for (i = 0; i < m; i++)
		{
			out << a[i] << " " << b[i] << " " << c[i] << endl;
		}
	}
	else
	{
		cout << "金额错误，申请失败" << endl;
	}
	if (money >= 1200 && money % 1200 != 0)
	{
		int  money1 = money % 1200;
		cout << "申请成功,您已为" << car << "申请" << carpark_number1 << "停车位" << money / 1200 << "年" << endl;
		cout << "退回" << money1 << endl;
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
	cout << setw(10) << "车牌号" << setw(10) << "停车位" << setw(10) << "年限" << endl;
	for (m = 0; m < 10; m++)
		if (a[m] != "无")
			cout << setw(10) << a[m] << setw(10) << b[m] << setw(10) << c[m] << endl;
	ifile.close();
	Menu();


}
void change()
{
	Household hs[100];//读取househole文件
	Household hs1[100];//读取住户文件
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
	do//读取信息
	{
		n++;
		//	cout << n;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].QQ >> hs[n].workphonenumber >> hs[n].car_number;
	} while (getline(ifile, check));
	do//读取信息
	{
		m++;
		//	cout << m;
		Ifile >> hs1[m].housenumber >> hs1[m].hname >> hs1[m].phonenumber >> hs1[m].fee >> hs1[m].shiji;
	} while (getline(Ifile, check));
	for (int i = 0; i <= m; i++)//用来赋值，之后方便欠款文件和修改后的文件同步
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
	cout << "请输入你要修改的房号" << endl;
	cin >> c;
	cout << "请输入你想修改的人姓名" << endl;
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
			cout << "请输入需要更改的信息" << endl;
			cout << "1 房号" << endl;
			cout << "2 住户姓名" << endl;
			cout << "3 户主姓名" << endl;
			cout << "4 与户主关系" << endl;
			cout << "5 身份 职业" << endl;
			cout << "6 单位位置" << endl;
			cout << "7 手机号码" << endl;
			cout << "8 工作电话" << endl;
			cout << "9 QQ号码" << endl;
			cout << "10 车牌号" << endl;
			cin >> index;
			switch (index)
			{
			case(1): {cout << "房号" << endl;
				cin >> hs[i].housenumber;
				break;
			}
			case(2): {cout << "住户姓名" << endl;
				cin >> hs[i].name;
				break;
			}
			case(3): {cout << "户主姓名" << endl;
				cin >> hs[i].hname;

				break;
			}
			case(4): {
				cout << "与户主关系" << endl;
				cin >> hs[i].relationship;
				break;
			}
			case(5): {cout << "身份" << endl;
				cin >> hs[i].identity;
				cout << "职业" << endl;
				cin >> hs[i].job;
				break;
			}
			case(6): {cout << "单位位置" << endl;
				cin >> hs[i].workplace;
				break;
			}
			case(7): {cout << "手机号码" << endl;
				cin >> hs[i].phonenumber;
				break;
			}
			case(8): {cout << "工作电话" << endl;
				cin >> hs[i].workphonenumber;
				break;
			}
			case(9): {cout << "QQ号码" << endl;
				cin >> hs[i].QQ;
				break;
			}
			case(10): {cout << "车牌号" << endl;
				cin >> hs[i].car_number;
				break;
			}
			}
			if (hs[i].relationship == "户主本人")
			{
				cout << "请输入应缴纳物业费" << endl;
				cin >> hs[i].fee;
				cout << "请输入实际缴纳物业费" << endl;
				cin >> hs[i].shiji;
				ofstream out("d:\\Fee.txt", ios::trunc);//清空原有文件
				ofstream Out("d:\\Fee.txt", ios::app);
				for (int i = 0; i <= n; i++)
				{
					if (hs[i].name == hs[i].hname)
						out << hs[i].housenumber << " " << hs[i].hname << " " << hs[i].phonenumber << " " << hs[i].fee << " " << hs[i].shiji << endl;
				}
			}
		}
	}


	ofstream ofile("d:\\househole.txt", ios::trunc);//清空原有文件
	ofstream Ofile("d:\\househole.txt", ios::app);
	for (int i = 0; i <= n; i++)
	{

		Ofile << hs[i].housenumber << " " << hs[i].name << " " << hs[i].hname << " " << hs[i].relationship << " " << hs[i].identity << " " << hs[i].job << " " << hs[i].workplace << " " << hs[i].phonenumber << " " << hs[i].workphonenumber << " " << hs[i].QQ << " " << hs[i].car_number << endl;

	}

	Menu();
}
void change(string zhuhu)
{
	Household hs[100];//读取househole文件
	Household hs1[100];//读取住户文件
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
	do//读取信息
	{
		n++;
		//	cout << n;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].QQ >> hs[n].workphonenumber >> hs[n].car_number;
	} while (getline(ifile, check));
	do//读取信息
	{
		m++;
		//	cout << m;
		Ifile >> hs1[m].housenumber >> hs1[m].hname >> hs1[m].phonenumber >> hs1[m].fee >> hs1[m].shiji;
	} while (getline(Ifile, check));
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (hs[j].hname == hs[j].name && hs[j].housenumber == hs1[i].housenumber)//讲fee中的信息经过比对判断写到househole中
			{
				hs[j].fee = hs1[i].fee;
				hs[j].shiji = hs1[i].shiji;

			}

		}
	}

	cout << "请输入你想修改的人姓名" << endl;
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
			cout << "请输入需要更改的信息" << endl;
			cout << "1 房号" << endl;
			cout << "2 住户姓名" << endl;
			cout << "3 户主姓名" << endl;
			cout << "4 与户主关系" << endl;
			cout << "5 身份 职业" << endl;
			cout << "6 单位位置" << endl;
			cout << "7 手机号码" << endl;
			cout << "8 工作电话" << endl;
			cout << "9 QQ号码" << endl;
			cout << "10 车牌号" << endl;
			cin >> index;
			switch (index)
			{
			case(1): {cout << "房号" << endl;
				cin >> hs[i].housenumber;
				break;
			}
			case(2): {cout << "住户姓名" << endl;
				cin >> hs[i].name;
				break;
			}
			case(3): {cout << "户主姓名" << endl;
				cin >> hs[i].hname;

				break;
			}
			case(4): {
				cout << "与户主关系" << endl;
				cin >> hs[i].relationship;
				break;
			}
			case(5): {cout << "身份" << endl;
				cin >> hs[i].identity;
				cout << "职业" << endl;
				cin >> hs[i].job;
				break;
			}
			case(6): {cout << "单位位置" << endl;
				cin >> hs[i].workplace;
				break;
			}
			case(7): {cout << "手机号码" << endl;
				cin >> hs[i].phonenumber;
				break;
			}
			case(8): {cout << "工作电话" << endl;
				cin >> hs[i].workphonenumber;
				break;
			}
			case(9): {cout << "QQ号码" << endl;
				cin >> hs[i].QQ;
				break;
			}
			case(10): {cout << "车牌号" << endl;
				cin >> hs[i].car_number;
				break;
			}
			}
			if (hs[i].relationship == "户主本人")
			{
				cout << "请输入应缴纳物业费" << endl;
				cin >> hs[i].fee;
				cout << "请输入实际缴纳物业费" << endl;
				cin >> hs[i].shiji;
				ofstream out("d:\\Fee.txt", ios::trunc);//清空原有文件
				ofstream Out("d:\\Fee.txt", ios::app);
				for (int i = 0; i <= n; i++)
				{
					if (hs[i].name == hs[i].hname)
						out << hs[i].housenumber << " " << hs[i].hname << " " << hs[i].phonenumber << " " << hs[i].fee << " " << hs[i].shiji << endl;
				}
			}
		}
	}


	ofstream ofile("d:\\househole.txt", ios::trunc);//清空原有文件
	ofstream Ofile("d:\\househole.txt", ios::app);
	for (int i = 0; i <= n; i++)
	{

		Ofile << hs[i].housenumber << " " << hs[i].name << " " << hs[i].hname << " " << hs[i].relationship << " " << hs[i].identity << " " << hs[i].job << " " << hs[i].workplace << " " << hs[i].phonenumber << " " << hs[i].workphonenumber << " " << hs[i].QQ << " " << hs[i].car_number << endl;

	}

	MenuB(zhuhu);
}
void showsingle()
{

	Household hs[100];//读取househole文件
	string c;
	string name;
	int n = -1;
	string check;
	ifstream ifile("d:\\househole.txt");
	do//读取信息
	{
		n++;
		//	cout << n;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].QQ >> hs[n].workphonenumber >> hs[n].car_number;
	} while (getline(ifile, check));
	cout << "请输入你要查询的房号" << endl;
	cin >> c;
	cout << setw(15) << "房号" << setw(15) << "住户姓名" << setw(15) << "户主姓名" << setw(15) << "与户主关系" << setw(15) << "身份" << setw(15) << "职业" << setw(30) << "单位位置" << setw(15) << "手机号码" << setw(15) << "工作电话" << setw(15) << "QQ" << setw(15) << "车牌号" << setw(15) << endl;
	for (int i = 0; i <= n; i++)
	{
		if (hs[i].housenumber == c)
			cout << setw(15) << hs[i].housenumber << setw(15) << hs[i].name << setw(15) << hs[i].hname << setw(15) << hs[i].relationship << setw(15) << hs[i].identity << setw(15) << hs[i].job << setw(30) << hs[i].workplace << setw(15) << hs[i].phonenumber << setw(15) << hs[i].workphonenumber << setw(15) << hs[i].QQ << setw(15) << hs[i].car_number << endl;
	}
	Menu();
}
void showsingle(string zhuhu)
{

	Household hs[100];//读取househole文件
	string message1;//作为路径的过渡
	message1 = zhuhu.substr(3);
	for (int i = 0; i <= 3; i++)
		message1.erase(message1.end() - 1);//获得房号
	string name;
	int n = -1;
	string check;
	ifstream ifile("d:\\househole.txt");
	do//读取信息
	{
		n++;
		//	cout << n;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].QQ >> hs[n].workphonenumber >> hs[n].car_number;
	} while (getline(ifile, check));
	cout << setw(15) << "房号" << setw(15) << "住户姓名" << setw(15) << "户主姓名" << setw(15) << "与户主关系" << setw(15) << "身份" << setw(15) << "职业" << setw(30) << "单位位置" << setw(15) << "手机号码" << setw(15) << "工作电话" << setw(15) << "QQ" << setw(15) << "车牌号" << endl;
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
	cout << "投诉" << endl;
	while (getline(ifile, check))//将文件里的数据输入到check 里
	{
		cout << check << endl;
	}
	ifile.close();

	if (!Ifile)
	{
		cout << "error" << endl;

	}
	string Check;
	cout << "报修" << endl;
	while (getline(Ifile, Check))//将文件里的数据输入到Check 里
	{
		cout << Check << endl;
	}
	Ifile.close();
	Menu();


}
void car_search()//通过车牌号查询户主
{
	Household hs[100];
	string a;
	string check;
	ifstream ifile("d:\\househole.txt");
	if (!ifile)
	{
		cout << "错误，请重新登录" << endl;
		exit(0);
	}
	int n = -1;
	int i = 0;
	cout << "输入要查询的车牌号：" << endl;
	cin >> a;
	do//读取信息
	{
		n++;
		ifile >> hs[n].housenumber >> hs[n].name >> hs[n].hname >> hs[n].relationship >> hs[n].identity >> hs[n].job >> hs[n].workplace >> hs[n].phonenumber >> hs[n].workphonenumber >> hs[n].QQ >> hs[n].car_number;
	} while (getline(ifile, check));
	for (i = 0; i <= n; i++)//判断角标
	{
		if (hs[i].car_number == a)
		{
			cout << "车辆" << hs[i].car_number << endl;
			cout << "房号：" << hs[i].housenumber << endl;
			cout << "车主姓名：" << hs[i].name << endl;
			cout << "车主手机:" << hs[i].phonenumber << endl;
			Menu();
		}
	}

	cout << "未查询到" << endl;
	Menu();


}