#include<iostream>
#include<string>
using namespace std;

//���ӵı�ʾ
class House
{
public:
	void setDoor(string door)
	{
		this->m_door = door;
	}
	void setWall(string wall)
	{
		this->m_wall=wall;
	}
	void setWindow(string window)
	{
		this->m_window=window;
	}
	string getDoor()
	{
		cout << m_door << endl;
		return this->m_door;
	}
	string getWall()
	{
		cout << m_wall << endl;
		return this->m_wall;
	}
	string getWindow()
	{
		cout << m_window << endl;
		return this->m_window;
	}
private:
	string m_door;
	string m_wall;
	string m_window;
};

//����һ��builder ���̶�
class Builder
{
public:
	virtual void buildDoor() = 0;
	virtual void buildWall() = 0;
	virtual void buildWindow() = 0;
	virtual House* getHouse() = 0;
};

//���ָ����Ĺ��̶ӣ��칫Ԣ�Ĺ��̶�
class FlatBuilder :public Builder
{
public:
	FlatBuilder(){
		m_House = new House;
	}
	virtual void buildDoor(){
		m_House->setDoor("flat door");
	}
	virtual void buildWall(){
		m_House->setWall("flat wall");
	}
	virtual void buildWindow(){
		m_House->setWindow("flat window");
	}
	virtual House* getHouse(){
		return m_House;
	}
private:
	House *m_House;
};
//�������̶�
class VillaBuilder :public Builder
{
public:
	VillaBuilder(){
		m_House = new House;
	}
	virtual void buildDoor(){
		m_House->setDoor("vill door");
	}
	virtual void buildWall(){
		m_House->setWall("vill wall");
	}
	virtual void buildWindow(){
		m_House->setWindow("vill window");
	}
	virtual House* getHouse(){
		return m_House;
	}
private:
	House *m_House;
};

//���ʦ( ָ���� )
//�����ߣ��ɾ���Ļ����
class Director{
public:
	Director(Builder *build){
		m_build = build;
	}
	void construct(){
		m_build->buildDoor();
		m_build->buildWall();
		m_build->buildWindow();
	}
private:
	Builder *m_build;
};



int main(){

	House *house = NULL;
	Builder *builder = NULL;
	Director *director = NULL;
	//��һ����������Ĺ��̶�
	builder = new VillaBuilder;
	//���ʦָ�ӹ��̶Ӹɻ��
	director = new Director(builder);
	director->construct();
	house = builder->getHouse();
	house->getWindow();
	house->getDoor();
	house->getWall();

	delete house;
	delete builder;

	//��һ�����칫Ԣ�Ĺ��̶�
	builder = new FlatBuilder;
	director = new Director(builder);
	director->construct();
	house = builder->getHouse();
	house->getDoor();
	house->getWall();
	house->getWindow();
	delete house;
	delete builder;


	delete director;
	
	system("pause");
	return 0;
}