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

	void m_choice2(Student Person[]);//¼��
	void Show_Program();//չʾĿ¼
	void ExitSystem();//�˳�����
	void setName();//ѧ����Ϣ
	void showStudent(Student Persion[]);//չʾѧ��
	void findStudent(Student Persion[]);//����
	void alterStudent(Student Persion[]);//�޸���Ϣ
	void deleteStudent(Student Persion[]);
	void showGrades(Student Persion[]);
};
int Student::m_flag = 0;
//������
int main()
{

	Student stu;
	Student m_stu[1000];

	while (1)
	{
		int choice;
		stu.Show_Program();
		cout << "����������ѡ��: ";
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
		default: system("cls");//����
		}
	}
}
void Student::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void Student::Show_Program()
{
	cout << "................................." << endl;
	cout << "................................." << endl;
	cout << "...........1.�˳�����............" << endl;
	cout << "...........2.����ѧ��............" << endl;
	cout << "...........3.��ʾѧ��............" << endl;
	cout << "...........4.����ѧ��............" << endl;
	cout << "...........5.�޸�ѧ��............" << endl;
	cout << "...........6.ɾ��ѧ��............" << endl;
	cout << "...........7.�ɼ��鿴............" << endl;

	cout << "................................." << endl;
	cout << "ע�⣺���û��������ȷ����ţ�����ˢ���������룡��������" << endl;
}

void Student::m_choice2(Student Person[])//����
{
	int m_n;
	cout << "(���10��)��ѡ������������� ";
	cin >> m_n;
	for (int i = m_flag; i < m_n + m_flag; i++)
	{
		Person[i].setName();
	}
	m_flag += m_n;
	cout << "���Բ�����ϣ����������" << endl;
	system("pause");
}
void Student::setName()
{
	cout << "���������֣� ";
	cin >> m_name;
	cout << "������ѧ�ţ� ";
	cin >> m_id;
	cout << "������༶�� ";
	cin >> m_class;
	cout << "������רҵ�� ";
	cin >> m_profession;
	cout << "���������������Ӣ�����ĳɼ��� ";
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
		cout << "��û���κ����ݣ���������������������Ϣ,������ѡ��" << endl;
	}
	system("pause");

}

void Student::findStudent(Student Persion[])
{
	int M_ID;
	int M_Flag = -1;
	cout << "��������Ҫ���ҵ�ѧ��ѧ�ţ� ";
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
		cout << "ѧ�ţ� " << Persion[M_Flag].m_id << endl;
		cout << "������ " << Persion[M_Flag].m_name << endl;
		cout << "�༶�� " << Persion[M_Flag].m_class << endl;
		cout << "רҵ�� " << Persion[M_Flag].m_profession << endl;
		cout << "�����ɼ��� " << Persion[M_Flag].m_grades.Math << endl;
		cout << "Ӣ��ɼ��� " << Persion[M_Flag].m_grades.English << endl;
		cout << "������Ƴɼ��� " << Persion[M_Flag].m_grades.procedure << endl;
	}
	else
	{
		cout << "��ϵͳ��δ¼���ѧ����Ϣ�������ѧ���Ƿ���ȷ~~~" << endl;
	}
	system("pause");
}
void Student::alterStudent(Student Persion[])
{
	int M_id, M_flag = -1;
	cout << "��������Ҫ�޸ĵ�ѧ��ѧ�ţ� ";
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
		cout << "���޸ĵ���" << Persion[M_flag].m_name << "����Ϣ" << endl;
		cout << "�༶�޸ģ� ";
		cin >> Persion[M_flag].m_class;
		cout << "רҵ�޸ģ� ";
		cin >> Persion[M_flag].m_profession;
		cout << "�����ɼ��޸ģ� ";
		cin >> Persion[M_flag].m_grades.Math;
		cout << "Ӣ��ɼ��޸ģ� ";
		cin >> Persion[M_flag].m_grades.English;
		cout << "������Ƴɼ��޸ģ� ";
		cin >> Persion[M_flag].m_grades.procedure;
		cout << "лл����ʹ�ã���������" << endl;
	}
	else
	{
		cout << "û������ͬѧ����Ϣ" << endl;
	}
	system("pause");
}
void Student::deleteStudent(Student Persion[])
{
	int M_id, M_flag = -1, Flag = 0;
	cout << "��������Ҫɾ����ѧ��ѧ�ţ� ";
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
		cout << "�����ɾ������" << Persion[M_flag].m_name << "����Ϣ" << endl;
		cout << "�Ƿ�ȷ��ɾ����ɾ��1��ȡ��0��: ";
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
		cout << "û������ͬѧ����Ϣ" << endl;
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
	cout << "������߷֣� " << mathmax << endl;
	cout << "������ͷ֣� " << mathmin << endl;
	cout << "����ƽ���֣� " << mathaver << endl;
	cout << endl;
	cout << "Ӣ����߷֣� " << Engmax << endl;
	cout << "Ӣ����ͷ֣� " << Engmin << endl;
	cout << "Ӣ��ƽ���֣� " << Engaver << endl;
	cout << endl;
	cout << "������߷֣� " << Promax << endl;
	cout << "������ͷ֣� " << Promin << endl;
	cout << "����ƽ���֣� " << Proaver << endl;
	cout << endl;
	cout << "�ɼ�ƽ���֣� " << addaver << endl;
	system("pause");
}
