#include<iostream>
#include<string>
using namespace std;

//房子的表示
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

//抽象一个builder 工程队
class Builder
{
public:
	virtual void buildDoor() = 0;
	virtual void buildWall() = 0;
	virtual void buildWindow() = 0;
	virtual House* getHouse() = 0;
};

//各种各样的工程队，造公寓的工程队
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
//别墅工程队
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

//设计师( 指挥者 )
//建造者（干具体的活儿）
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
	//请一个建造别墅的工程队
	builder = new VillaBuilder;
	//设计师指挥工程队干活儿
	director = new Director(builder);
	director->construct();
	house = builder->getHouse();
	house->getWindow();
	house->getDoor();
	house->getWall();

	delete house;
	delete builder;

	//请一个建造公寓的工程队
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