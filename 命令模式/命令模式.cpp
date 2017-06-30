//���������࣬��ʵ��һ���������һ����ķ���
#include<iostream>
#include<list>
using namespace std;

class Doctor
{
public:
	void treat_eye(){
		cout << "ҽ�������� �ۿƲ�" << endl;
	}
	void treat_nose(){
		cout << "ҽ�������� �ǿƲ�" << endl;
	}
};

//����һ������
class CommandTreat
{
public:
	virtual void treat() = 0;
};


//������
class CommandTreatEye:public CommandTreat
{
public:
	CommandTreatEye(Doctor *doc)
	{
		m_doctor = doc;
	}
	void treat(){
		m_doctor->treat_eye();
	}
private:
	Doctor *m_doctor;
};
class CommandTreatNose:public CommandTreat
{
public:
	CommandTreatNose(Doctor *doc)
	{
		m_doctor = doc;
	}
	void treat(){
		m_doctor->treat_nose();
	}
private:
	Doctor *m_doctor;
};


//��ʿ
class BeautyNurse
{
public:
	BeautyNurse(CommandTreat *comm)
	{
		m_command = comm;
	}

	void SubmittedCase()///�ύ����
	{
		m_command->treat();
	}
private:
	CommandTreat *m_command;
};

//��ʿ��
class HeadNurse
{
public:
	HeadNurse(){
		m_list.clear(); //���list
	}
	
	void setCommand(CommandTreat *command)
	{
		m_list.push_back(command);
	}

	void SubmittedCase()///�ύ����
	{
		for (list<CommandTreat*>::iterator it = m_list.begin();
			it != m_list.end(); it++)
		{
			(*it)->treat();
		}
	}
private:
	CommandTreat *m_command;
	list<CommandTreat*> m_list;
};

int main1(){
	//1,ҽ��ֱ�ӿ���
	Doctor *doctor = new Doctor;
	doctor->treat_eye();
	delete doctor;

	//2��ͨ�����ҽ��ͨ�������������ۿƲ�
	Doctor *doctor1 = new Doctor;
	CommandTreat *commandtreat = new CommandTreatEye(doctor1);
	commandtreat->treat();
	delete commandtreat;
	delete doctor1;
	return 0;
}
int main2(){
	//��ʿ�ύ�����������˿���
	Doctor *doctor2 = NULL;
	CommandTreat *commandtreat = NULL;
	BeautyNurse *nurse = NULL;


	doctor2 = new Doctor;
	commandtreat = new CommandTreatEye(doctor2);	
	nurse = new BeautyNurse(commandtreat);
	nurse->SubmittedCase();

	delete commandtreat;
	delete nurse;

	commandtreat = new CommandTreatNose(doctor2);
	nurse = new BeautyNurse(commandtreat);
	nurse->SubmittedCase();

	delete doctor2;
	delete commandtreat;
	delete nurse;

	return 0;
}

int main3(){
	//ͨ����ʿ���������µ� ����
	Doctor *doctor3 = NULL;
	HeadNurse *headnurse = NULL;
	CommandTreat *commandtreat1 = NULL;
	CommandTreat *commandtreat2 = NULL;


	doctor3 = new Doctor;

	commandtreat1 = new CommandTreatEye(doctor3);
	commandtreat2 = new CommandTreatNose(doctor3);

	headnurse = new HeadNurse();
	headnurse->setCommand(commandtreat1); //��ʿ���������
	headnurse->setCommand(commandtreat2);

	headnurse->SubmittedCase(); //��ʿ�������´�����

	delete doctor3;
	delete commandtreat1;
	delete commandtreat2;
	delete headnurse;
	return 0;
}

int main(){
	//main1();
	//main2();
	main3();
	return 0;
}