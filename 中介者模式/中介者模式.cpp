#include<iostream>
#include<string>
using namespace std;



class Mediator; //�����н���

class Person
{
public:
	Person(string name, int sex, int condi,Mediator *m){
		m_name = name;
		m_sex = sex;
		m_condi = condi;
		m_mediator = m;
	}
	string getName(){
		return m_name;
	}
	int getSex(){
		return m_sex;
	}
	int getCondi(){
		return m_condi;
	}
	virtual void getParter(Person *p) = 0;

protected:
	string m_name;
	int m_sex;
	int m_condi;
	Mediator *m_mediator;
};


//�н���
class Mediator
{
public:
	void setMan(Person *man)
	{
		m_man = man;
	}
	void setWoman(Person *woman)
	{
		m_woman = woman;
	}

	virtual void getParter()
	{
		if (m_man->getSex() == m_woman->getSex())
		{
			cout << m_man->getName() << " and " << m_woman->getName() << " with the same sex, can not together." << endl;
		}
		else if (m_man->getCondi() == m_woman->getCondi())
		{
			cout << m_man->getName() << " and " << m_woman->getName() << " are same condition" << endl;
		}
		else
		{
			cout << m_man->getName() << " and " << m_woman->getName() << " are not same condition" << endl;
		}
	}
private:
	Person *m_man;
	Person *m_woman;
	//���˵������󣬻������������ļ��ϣ�Ȼ������������жϺ�ѡ��
};



class Woman :public Person
{
public:
	Woman(string name, int sex, int condi, Mediator *m) :Person(name, sex, condi, m){

	}
	void getParter(Person *p)
	{
		m_mediator->setMan(p);
		m_mediator->setWoman(this);
		m_mediator->getParter(); //�Ҷ���
	}
private:
	Person *person;
};

class Man :public Person
{
public:
	Man(string name, int sex, int condi, Mediator *m) :Person(name, sex, condi, m){

	}
	void getParter(Person *p)
	{		
		m_mediator->setMan(this);
		m_mediator->setWoman(p);
		m_mediator->getParter(); //�Ҷ���		
	}
private:
	Person *person;
};

int main(){
	Mediator *mediator = new Mediator();
	Person *xiaofang = new Woman("С��", 2, 5, mediator);
	Person *zhangsan = new Woman("����", 1, 4, mediator);
	Person *lisi = new Woman("����", 1, 5, mediator);

	xiaofang->getParter(zhangsan);
	xiaofang->getParter(lisi);
	zhangsan->getParter(lisi);



	return 0;
}