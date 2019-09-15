#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <windows.h>
using namespace std;
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
class StudentsINFO_management          //学生信息管理
{
private:
	char stu_num[11];                  //学号
	char name[20];                     //姓名
	char sex[3];                       //性别
	char Class[10];                    //班级
	double score;                      //分数
	StudentsINFO_management* students;
public:
	static int numStu;
	StudentsINFO_management();
	~StudentsINFO_management();
	void set_stu_num(char stu_num1[11]) { strcpy_s(stu_num, 11, stu_num1); }
	void set_name(char name1[20]) { strcpy_s(name, 20, name1); }
	void set_sex(char sex1[3]) { strcpy_s(sex, 3, sex1); }
	void set_Class(char Class1[10]) { strcpy_s(Class, 10, Class1); }
	void set_score(double score1) { score = score1; }
	void run();
	void systemMenu();
	void inputStuINFO();               //输入新的学生信息√
	void searchINFO();                 //查询学生信息√√√
	void searchClass();                // ↑
	void searchNum();                  // ↑ 子函数
	void scoreStatistics();            //统计学生成绩√
	void saveStudentINFO();            //保存学生信息,把信息输出到桌面√
	void readStudentINFO();            //读取刚刚输入的学生信息√
	void printStudentINFO();           //读取保存的所有学生信息√
	void clearAll();                   //清空所有信息√
	void Change();                     //修改学生信息√
	void Delete();                     //删除学生信息√
	void EXIT();                       //退出管理系统√
};
int StudentsINFO_management::numStu = 0;
//------------------------------------
int main()
{
	char a;
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "┍┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┑"<<endl;
	cout << "┊×请输入系统进入密码" << endl;
	cout << "┕┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┙" << endl;
	cout << "密码：";
	cin >> a;

	if (a == '+')
	{
		StudentsINFO_management A;
		A.systemMenu();
		A.run();
	}
	else
	{
		cout << "密码输入错误 三秒后退出" << endl;
		Sleep(3000);
		exit(0);
	}
	return 0;
}
StudentsINFO_management::StudentsINFO_management() {}
StudentsINFO_management::~StudentsINFO_management()
{
	numStu = 0;
}
//--------------------------------------
void StudentsINFO_management::systemMenu()
{

	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << setiosflags(ios::right) << setw(33) << "欢迎使用学生成绩管理系统" << endl;
	cout << "********************************************" << endl;

	cout << "*" << setiosflags(ios::right) << setw(25) << "1、录入学生信息" << setiosflags(ios::right) << setw(18) << "*" << endl;
	cout << "*" << setiosflags(ios::right) << setw(41) << "2、查询学生信息(按学号班级查找)" << setiosflags(ios::right) << setw(2) << "*" << endl;
	cout << "*" << setiosflags(ios::right) << setw(25) << "3、统计学生成绩" << setiosflags(ios::right) << setw(18) << "*" << endl;
	cout << "*" << setiosflags(ios::right) << setw(25) << "4、保存学生信息" << setiosflags(ios::right) << setw(18) << "*" << endl;
	cout << "*" << setiosflags(ios::right) << setw(33) << "5、读取刚输入的学生信息" << setiosflags(ios::right) << setw(10) << "*" << endl;
	cout << "*" << setiosflags(ios::right) << setw(37) << "6、读取已保存的所有学生信息" << setiosflags(ios::right) << setw(6) << "*" << endl;
	cout << "*" << setiosflags(ios::right) << setw(31) << "7、清空保存的所有信息" << setiosflags(ios::right) << setw(12) << "*" << endl;
	cout << "*" << setiosflags(ios::right) << setw(25) << "8、删除学生信息" << setiosflags(ios::right) << setw(18) << "*" << endl;
	cout << "*" << setiosflags(ios::right) << setw(25) << "9、修改学生信息" << setiosflags(ios::right) << setw(18) << "*" << endl;
	cout << "*" << setiosflags(ios::right) << setw(25) << "0、退出管理系统" << setiosflags(ios::right) << setw(18) << "*" << endl;
	cout << "********************************************" << endl;
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "保存的信息将会以txt格式默认保存到D盘下" << endl;
	cout << "请输入序号选择下一步操作:";
}
void StudentsINFO_management::run()
{
	int chose;
	char temp = 'N';
	while (temp == 'n' || temp == 'N')
	{
		cin >> chose;
		switch (chose)
		{
		case 1:
			inputStuINFO();      break;
		case 2:
			searchINFO();        break;
		case 3:
			scoreStatistics();   break;
		case 4:
			saveStudentINFO();   break;
		case 5:
			readStudentINFO();   break;
		case 6:
			printStudentINFO();  break;
		case 7:
			clearAll();          break;
		case 8:
			Delete();            break;
		case 9:
			Change();            break;
		case 0:
			EXIT();              break;
		}
		cout << "是否退出系统(N|Y)?" << endl;
		cin >> temp;
		if (temp == 'N' || temp == 'n')
		{
			system("cls");
			systemMenu();
		}
		else
		{
			EXIT();
			delete students;
		}
	}
}

void StudentsINFO_management::inputStuINFO()
{//1
	cout << "请输入需要输入的学生人数" << endl;
	cin >> numStu;
	StudentsINFO_management::students = new StudentsINFO_management[numStu];


	for (int i = 0; i < numStu; i++)
	{
		cout << "请输入第" << i + 1 << "名同学的学号" << endl;
		cin >> students[i].stu_num;
		cout << "请输入第" << i + 1 << "名同学的姓名" << endl;
		cin >> students[i].name;
		cout << "请输入第" << i + 1 << "名同学的性别" << endl;
		cin >> students[i].sex;
		cout << "请输入第" << i + 1 << "名同学的班级(A|B)" << endl;
		cin >> students[i].Class;
		cout << "请输入第" << i + 1 << "名同学的分数" << endl;
		cin >> students[i].score;
	}
	cout << "输入1保存,不保存则输入0" << endl;
	int chose2;
	cin >> chose2;
	switch (chose2)
	{
	case 1:
		saveStudentINFO();
		cout << "保存成功！" << endl;
		break;
	case 0:
		break;
	}
}
void StudentsINFO_management::searchINFO()
{//2
	int chose;
	cout << "输入1 按学号查找单个学生（格式：18xxxx）" << endl;
	cout << "输入2 查找某班级所有学生 （A班或B班）" << endl;
	cin >> chose;
	switch (chose)
	{
	case 1:
		searchNum();  break;
	case 2:
		searchClass();    break;
	}
}
void StudentsINFO_management::scoreStatistics()
{//3
	int i = 0;
	double average = 0;
	ifstream fin;
	StudentsINFO_management stu;
	fin.open("D:/全部学生信息.txt", ios::binary | ios::in);
	fin.read((char*)& stu, sizeof(stu));
	while (!fin.eof())
	{
		i++;
		average += stu.score;
		fin.read((char*)& stu, sizeof(stu));
	}
	average = average / i;
	cout << "所有学生的平均成绩是" << average << endl;
	fin.close();
}
void StudentsINFO_management::saveStudentINFO()
{//4
	ofstream fout;
	StudentsINFO_management S;
	fout.open("D:/全部学生信息.txt", ios::binary | ios::app);
	for (int i = 0; i < numStu; i++)
		fout.write((char*)& students[i], sizeof(students[i]));
	fout.close();
	/*
	for (int i = 0; i < length; i++)
	{
		fout << "学号：" << students[i].stu_num << "|"
			<< "姓名：" << students[i].name << "  "         //两个空格
			<< "性别：" << students[i].sex << "   "         //三个空格
			<< "班级：" << students[i].Class << '\t'
			<< "成绩：" << students[i].score << endl;
	}*/

}
void StudentsINFO_management::readStudentINFO()
{//5
	for (int i = 0; i < numStu; i++)
	{
		cout << "学号：" << students[i].stu_num << "|"
			<< "姓名：" << students[i].name << "  "         //两个空格
			<< "性别：" << students[i].sex << "   "         //三个空格
			<< "班级：" << students[i].Class << "    "      //四个空格
			<< "成绩：" << students[i].score << endl;
	}
}
void StudentsINFO_management::printStudentINFO()
{//6
	ifstream fin;
	fin.open("D:/全部学生信息.txt", ios::in | ios::binary);
	StudentsINFO_management S;
	fin.read((char*)& S, sizeof(S));
	while (!fin.eof())
	{
		SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout <<
			"学号：" << S.stu_num << "|";
		SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout <<
			"名字:" << setw(6) << S.name << "  ";    //两个空格
		SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout <<
			"性别:" << S.sex << "   " <<              //三个空格
			"班级:" << S.Class << "    " <<           //四个空格
			"成绩:" << S.score << endl;
		fin.read((char*)& S, sizeof(S));
		Sleep(100);
	}
	fin.close();
}
void StudentsINFO_management::clearAll()
{//7
	ofstream fout;
	fout.open("D:/全部学生信息.txt", ios::binary | ios::trunc);
	cout << "学生信息已清空" << endl;
}

void StudentsINFO_management::Delete()
{//8
	char num[11];
	ifstream fin;
	StudentsINFO_management stu;
	vector <StudentsINFO_management>vector;
	cout << "输入想要删除的学生的学号" << endl;
	cin >> num;
	fin.open("D:/全部学生信息.txt", ios::binary | ios::in);
	fin.read((char*)& stu, sizeof(stu));
	while (!fin.eof())
	{
		if (strcmp(stu.stu_num, num) != 0)
		{
			vector.push_back(stu);
		}
		fin.read((char*)& stu, sizeof(stu));
	}
	fin.close();
	ofstream fout;
	fout.open("D:/全部学生信息.txt", ios::binary | ios::trunc);
	for (int i = 0; i < vector.size(); i++)
	{
		stu = vector[i];
		fout.write((char*)& stu, sizeof(stu));
	}
	fout.close();
}
void StudentsINFO_management::Change()
{//9
	char num[11];
	char name[20];
	char sex[3];
	char Class[10];
	double score;
	ifstream fin;
	StudentsINFO_management stu;
	vector <StudentsINFO_management>vector;
	cout << "输入想要修改的学生的学号" << endl;
	cin >> num;
	cout << "输入想要修改后的姓名" << endl;
	cin >> name;
	cout << "输入修改后的性别" << endl;
	cin >> sex;
	cout << "输入修改后的班级" << endl;
	cin >> Class;
	cout << "输入修改后的成绩" << endl;
	cin >> score;
	fin.open("D:/全部学生信息.txt", ios::binary | ios::in);
	fin.read((char*)& stu, sizeof(stu));
	while (!fin.eof())
	{
		if (strcmp(stu.stu_num, num) != 0)
		{
			vector.push_back(stu);
		}
		else
		{
			stu.set_stu_num(num);
			stu.set_name(name);
			stu.set_sex(sex);
			stu.set_Class(Class);
			stu.set_score(score);
			vector.push_back(stu);
		}
		fin.read((char*)& stu, sizeof(stu));
	}
	fin.close();
	ofstream fout;
	fout.open("D:/全部学生信息.txt", ios::binary | ios::trunc);
	for (int i = 0; i < vector.size(); i++)
	{
		stu = vector[i];
		fout.write((char*)& stu, sizeof(stu));
	}
	fout.close();

}
void StudentsINFO_management::EXIT()
{//0
	exit(0);
}
void StudentsINFO_management::searchNum()        //安学号查找
{//2-1
	cout << "输入要查询的学生的学号" << endl;
	char num[11];
	cin >> num;
	ifstream fin;
	fin.open("D:/全部学生信息.txt", ios::in | ios::binary);
	StudentsINFO_management S;
	fin.read((char*)& S, sizeof(S));
	while (!fin.eof())
	{
		if (strcmp(num, S.stu_num) == 0)
		{
			SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout <<
				"学号：" << S.stu_num << "|";
			SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout <<
				"名字:" << setw(6) << S.name << "  ";    //两个空格
			SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout <<
				"性别:" << S.sex << "   " <<    //三个空格
				"班级:" << S.Class << "    " <<    //四个空格
				"成绩:" << S.score << endl;
		}

		fin.read((char*)& S, sizeof(S));
	}
	fin.close();
}
void StudentsINFO_management::searchClass()       //按班级查找
{//2-2
	cout << "输入要查询的学生的班级" << endl;
	char num[11];
	cin >> num;
	ifstream fin;
	fin.open("D:/全部学生信息.txt", ios::in | ios::binary);
	StudentsINFO_management S;
	fin.read((char*)& S, sizeof(S));
	while (!fin.eof())
	{
		if (strcmp(num, S.Class) == 0)
		{
			SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout <<
				"学号：" << S.stu_num << "|";
			SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout <<
				"名字:" << setw(6) << S.name << "  ";    //两个空格
			SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout <<
				"性别:" << S.sex << "   " <<
				"班级:" << S.Class << "    " <<
				"成绩:" << S.score << endl;
			Sleep(100);
		}

		fin.read((char*)& S, sizeof(S));
	}
	fin.close();
}

