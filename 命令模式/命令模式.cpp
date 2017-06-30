//利用命令类，来实现一个类调用另一个类的方法
#include<iostream>
#include<list>
using namespace std;

class Doctor
{
public:
	void treat_eye(){
		cout << "医生，治疗 眼科病" << endl;
	}
	void treat_nose(){
		cout << "医生，治疗 鼻科病" << endl;
	}
};

//抽象一个命令
class CommandTreat
{
public:
	virtual void treat() = 0;
};


//命令类
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


//护士
class BeautyNurse
{
public:
	BeautyNurse(CommandTreat *comm)
	{
		m_command = comm;
	}

	void SubmittedCase()///提交病例
	{
		m_command->treat();
	}
private:
	CommandTreat *m_command;
};

//护士长
class HeadNurse
{
public:
	HeadNurse(){
		m_list.clear(); //清空list
	}
	
	void setCommand(CommandTreat *command)
	{
		m_list.push_back(command);
	}

	void SubmittedCase()///提交病例
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
	//1,医生直接看病
	Doctor *doctor = new Doctor;
	doctor->treat_eye();
	delete doctor;

	//2，通过命令，医生通过命令来治疗眼科病
	Doctor *doctor1 = new Doctor;
	CommandTreat *commandtreat = new CommandTreatEye(doctor1);
	commandtreat->treat();
	delete commandtreat;
	delete doctor1;
	return 0;
}
int main2(){
	//护士提交病例，给病人看病
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
	//通过护士长，批量下单 看病
	Doctor *doctor3 = NULL;
	HeadNurse *headnurse = NULL;
	CommandTreat *commandtreat1 = NULL;
	CommandTreat *commandtreat2 = NULL;


	doctor3 = new Doctor;

	commandtreat1 = new CommandTreatEye(doctor3);
	commandtreat2 = new CommandTreatNose(doctor3);

	headnurse = new HeadNurse();
	headnurse->setCommand(commandtreat1); //护士长添加命令
	headnurse->setCommand(commandtreat2);

	headnurse->SubmittedCase(); //护士长批量下达命令

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