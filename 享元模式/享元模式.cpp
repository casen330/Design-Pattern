#include<iostream>
#include<string>
#include<map>
using namespace std;


class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	virtual void printT() = 0;
protected:
	string m_name;
	int m_age;
};

class Teacher :public Person
{
public:
	Teacher(string name, int age, string id) :Person(name,age)
	{
		m_id = id;
	}
	void printT(){
		cout << "name:  " << m_name << "\nage:  " << m_age << "\nid:  " << m_id << endl;
	}
private:
	string m_id;
};

//��� ��ʦ��� �洢

//��Ԫ����
class FlyWeightFactory
{
public:
	FlyWeightFactory(){
		map1.clear();
	}
	~FlyWeightFactory(){
		while (!map1.empty())  //�ͷ��ڴ�
		{
			Person *tmp = NULL;
			map<string, Person*>::iterator it = map1.begin();
			tmp = it->second;
			map1.erase(it); //�ѵ�һ������������ɾ��
			delete tmp;
		}
	}
	Person *GetTeacher(string id)
	{
		map<string, Person*>::iterator it;
		
		it = map1.find(id);
		if (it == map1.end()) //û�ҵ�
		{
			string tmpname;
			cout << "Please input the teacher's name: ";
			cin >> tmpname;
			int tmpage;
			cout << "Please input the teacher's age: ";
			cin >> tmpage;
			Teacher *tmp = new Teacher(tmpname, tmpage, id);
			map1.insert(pair<string, Person*>(id, tmp));
			return tmp;
		}
		else
		{
			return it->second;
		}
	}
private:
	map<string, Person*> map1;

};


int main(){
	Person *p1 = NULL;
	Person *p2 = NULL;
	FlyWeightFactory *fwtf = new FlyWeightFactory;
	p1 = fwtf->GetTeacher("001");
	p1->printT();

	p2 = fwtf->GetTeacher("001"); //����001���ҵ�����ֱ�ӷ���map�����second
	p2->printT();


	delete fwtf;
	return 0;
}