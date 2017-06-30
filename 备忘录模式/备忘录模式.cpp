#include<iostream>
#include<string>
using namespace std;

class MememTo
{
public:
	MememTo(string name, int age){
		m_name = name;
		m_age = age;
	}
	string getName(){
		return m_name;
	}
	int getAge(){
		return m_age;
	}

	void setName(string name)
	{
		m_name = name;
	}
	void setAge(int age)
	{
		m_age = age;
	}
private:
	string m_name;
	int    m_age;
};
class Person
{
public:
	Person(string name, int age){
		m_name = name;
		m_age = age;
	}
	string getName(){
		return m_name;
	}
	int getAge(){
		return m_age;
	}

	void setName(string name)
	{
		m_name = name;
	}
	void setAge(int age)
	{
		m_age = age;
	}
	//保存
	MememTo *createMememTo()
	{
		return new MememTo(m_name, m_age);
	}
	//还原
	void setMememTo(MememTo *mem)
	{
		m_age = mem->getAge();
		m_name = mem->getName();
	}

	void printT(){
		cout << "Name: " << m_name << endl << "Age: " << m_age << endl;
	}
private:
	string m_name;
	int    m_age;
	MememTo *memo;
};

//管理者
class CareTaker
{
public:
	CareTaker(MememTo *m)
	{
		memto = m;
	}
	MememTo *getMememTo()
	{
		return memto;
	}
	void setMememTo(MememTo *m)
	{
		memto = m;
	}
private:
	MememTo *memto;
}; 


int main(){
	Person *p1 = NULL;
	//MememTo *mem = NULL;
	CareTaker *care = NULL;


	p1 = new Person("ccc", 23);
	cout << "原始数据" << endl;
	p1->printT();
	care = new CareTaker(p1->createMememTo());
	//care->setMememTo(p1->createMememTo());
	//mem = p1->createMememTo();
	p1->setAge(42);
	cout << "改变后" << endl;
	p1->printT();

	p1->setMememTo(care->getMememTo());
	//p1->setMememTo(mem);
	cout << "还原后" << endl;
	p1->printT();

	delete p1 ;
	//delete mem;
	delete care;
	return 0;
}