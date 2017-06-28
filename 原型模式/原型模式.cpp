#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	virtual Person* clone() = 0;
	virtual void print() = 0;
};

class CPlusProgrammer :public Person
{
public:
	CPlusProgrammer(){
		m_name = "";
		m_age = 0;
	}
	CPlusProgrammer(string n, int a) :m_name(n), m_age(a){}
	virtual void print(){
		cout << "m_name: " << m_name << "m_age: " << m_age << endl;
	}
	virtual Person* clone(){
		CPlusProgrammer *tmp = new CPlusProgrammer;
		*tmp = *this;
		return tmp;
	}
private:
	string m_name;
	int m_age;
};

int main(){
	Person *c1 = new CPlusProgrammer("casen", 25);
	c1->print();
	Person *c2 = c1->clone();
	c2->print();
	return 0;
}