#include <iostream>
#include <string>
using namespace std;

class Grades
{
private:
public:
	double Math;
	double English;
	double procedure;
	
};

class Student
{
private:

	int m_id;
	string m_class;
	string m_name;
	string m_profession;
	Grades m_grades;
public:
	static int m_flag;

	void m_choice2(Student Person[]);//录入
	void Show_Program();//展示目录
	void ExitSystem();//退出程序
	void setName();//学生信息
	void showStudent(Student Persion[]);//展示学生
	void findStudent(Student Persion[]);//查找
	void alterStudent(Student Persion[]);//修改信息
	void deleteStudent(Student Persion[]);
	void showGrades(Student Persion[]);
};
int Student::m_flag = 0;
//主函数
int main()
{

	Student stu;
	Student m_stu[1000];

	while (1)
	{
		int choice;
		stu.Show_Program();
		cout << "请输入您的选择: ";
		cin >> choice;

		switch (choice)
		{
		case 1:  stu.ExitSystem(); break;//
		case 2:  stu.m_choice2(m_stu); break;//
		case 3:  stu.showStudent(m_stu); break;//
		case 4:  stu.findStudent(m_stu); break;//
		case 5:  stu.alterStudent(m_stu); break;//
		case 6:  stu.deleteStudent(m_stu); break;//
		case 7:  stu.showGrades(m_stu); break;//
		//case 7:  break;//
		default: system("cls");//清屏
		}
	}
}
void Student::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void Student::Show_Program()
{
	cout << "................................." << endl;
	cout << "................................." << endl;
	cout << "...........1.退出程序............" << endl;
	cout << "...........2.增加学生............" << endl;
	cout << "...........3.显示学生............" << endl;
	cout << "...........4.查找学生............" << endl;
	cout << "...........5.修改学生............" << endl;
	cout << "...........6.删除学生............" << endl;
	cout << "...........7.成绩查看............" << endl;

	cout << "................................." << endl;
	cout << "注意：如果没有输入正确的序号，将会刷新重新输入！！！！！" << endl;
}

void Student::m_choice2(Student Person[])//增加
{
	int m_n;
	cout << "(最多10个)请选择输入的人数： ";
	cin >> m_n;
	for (int i = m_flag; i < m_n + m_flag; i++)
	{
		Person[i].setName();
	}
	m_flag += m_n;
	cout << "您以操作完毕，请继续操作" << endl;
	system("pause");
}
void Student::setName()
{
	cout << "请输入名字： ";
	cin >> m_name;
	cout << "请输入学号： ";
	cin >> m_id;
	cout << "请输入班级： ";
	cin >> m_class;
	cout << "请输入专业： ";
	cin >> m_profession;
	cout << "请依次输入高数，英语，程序的成绩： ";
	cin >> m_grades.Math >> m_grades.English >> m_grades.procedure;
}
void Student::showStudent(Student Persion[])
{
	for (int i = 0; i < m_flag; i++)
	{
		cout << Persion[i].m_id << " " << Persion[i].m_name << endl;
	}
	if (m_flag == 0)
	{
		cout << "还没有任何数据，请先往里面输入数据信息,请重新选择！" << endl;
	}
	system("pause");

}

void Student::findStudent(Student Persion[])
{
	int M_ID;
	int M_Flag = -1;
	cout << "请输入您要查找的学生学号： ";
	cin >> M_ID;
	for (int i = 0; i < m_flag; i++)
	{
		if (M_ID == Persion[i].m_id)
		{
			M_Flag = i;
		}

	}
	if (M_Flag >= 0 && M_Flag < m_flag)
	{
		cout << "学号： " << Persion[M_Flag].m_id << endl;
		cout << "姓名： " << Persion[M_Flag].m_name << endl;
		cout << "班级： " << Persion[M_Flag].m_class << endl;
		cout << "专业： " << Persion[M_Flag].m_profession << endl;
		cout << "高数成绩： " << Persion[M_Flag].m_grades.Math << endl;
		cout << "英语成绩： " << Persion[M_Flag].m_grades.English << endl;
		cout << "程序设计成绩： " << Persion[M_Flag].m_grades.procedure << endl;
	}
	else
	{
		cout << "本系统并未录入该学生信息或检查你的学号是否正确~~~" << endl;
	}
	system("pause");
}
void Student::alterStudent(Student Persion[])
{
	int M_id, M_flag = -1;
	cout << "请输入需要修改的学生学号： ";
	cin >> M_id;
	for (int i = 0; i < m_flag; i++)
	{
		if (M_id == Persion[i].m_id)
		{
			M_flag = i;
		}
	}
	if (M_flag > 0)
	{
		cout << "你修改的是" << Persion[M_flag].m_name << "的信息" << endl;
		cout << "班级修改： ";
		cin >> Persion[M_flag].m_class;
		cout << "专业修改： ";
		cin >> Persion[M_flag].m_profession;
		cout << "高数成绩修改： ";
		cin >> Persion[M_flag].m_grades.Math;
		cout << "英语成绩修改： ";
		cin >> Persion[M_flag].m_grades.English;
		cout << "程序设计成绩修改： ";
		cin >> Persion[M_flag].m_grades.procedure;
		cout << "谢谢您的使用！！！！！" << endl;
	}
	else
	{
		cout << "没有这名同学的信息" << endl;
	}
	system("pause");
}
void Student::deleteStudent(Student Persion[])
{
	int M_id, M_flag = -1, Flag = 0;
	cout << "请输入需要删除的学生学号： ";
	cin >> M_id;
	for (int i = 0; i < m_flag; i++)
	{
		if (M_id == Persion[i].m_id)
		{
			M_flag = i;
		}
	}
	if (M_flag > 0)
	{
		cout << "你打算删除的是" << Persion[M_flag].m_name << "的信息" << endl;
		cout << "是否确定删除（删除1，取消0）: ";
		cin >> Flag;
		if (Flag == 1)
		{
			for (int i = M_flag + 1; i <= m_flag; i++)
			{
				Persion[M_flag] = Persion[i];
				M_flag = i;
			}
			m_flag--;
		}
	}
	else
	{
		cout << "没有这名同学的信息" << endl;
	}
	system("pause");
}

void Student::showGrades(Student Persion[])
{
	double mathmin = Persion[0].m_grades.Math, mathmax = Persion[0].m_grades.Math, mathaver = 0;
	double Engmin = Persion[0].m_grades.English, Engmax = Persion[0].m_grades.English, Engaver = 0;
	double Promin = Persion[0].m_grades.procedure, Promax = Persion[0].m_grades.procedure, Proaver = 0;
	double addaver = 0;
	for (int i = 0; i < m_flag; i++)
	{
		if (mathmin > Persion[i].m_grades.Math)
		{
			mathmin = Persion[i].m_grades.Math;
		}
		if (mathmax < Persion[i].m_grades.Math)
		{
			mathmax = Persion[i].m_grades.Math;
		}
		mathaver += Persion[i].m_grades.Math;
	}
	for (int i = 0; i < m_flag; i++)
	{
		if (Engmin > Persion[i].m_grades.English)
		{
			Engmin = Persion[i].m_grades.English;
		}
		if (Engmax < Persion[i].m_grades.English)
		{
			Engmax = Persion[i].m_grades.English;
		}
		Engaver += Persion[i].m_grades.English;
	}
	for (int i = 0; i < m_flag; i++)
	{
		if (Promin > Persion[i].m_grades.procedure)
		{
			Promin = Persion[i].m_grades.procedure;
		}
		if (Promax < Persion[i].m_grades.procedure)
		{
			Promax = Persion[i].m_grades.procedure;
		}
		Proaver += Persion[i].m_grades.procedure;
	}
	addaver = mathaver + Engaver + Proaver;
	addaver /= m_flag;
	mathaver /= m_flag;
	Engaver /= m_flag;
	Proaver /= m_flag;
	cout << "高数最高分： " << mathmax << endl;
	cout << "高数最低分： " << mathmin << endl;
	cout << "高数平均分： " << mathaver << endl;
	cout << endl;
	cout << "英语最高分： " << Engmax << endl;
	cout << "英语最低分： " << Engmin << endl;
	cout << "英语平均分： " << Engaver << endl;
	cout << endl;
	cout << "程序最高分： " << Promax << endl;
	cout << "程序最低分： " << Promin << endl;
	cout << "程序平均分： " << Proaver << endl;
	cout << endl;
	cout << "成绩平均分： " << addaver << endl;
	system("pause");
}
