#include<iostream>
using namespace std;

//发动机，抽象
class Engine{
public:
	virtual void InstallEngine() = 0;
};

//具体发动机
class E4400 :public Engine
{
public:
	virtual void InstallEngine(){
		cout << "E4400 engine,installed" << endl;
	}
};
class E3500 :public Engine
{
public:
	virtual void InstallEngine(){
		cout << "E3500 engine,installed" << endl;
	}
};

//车，抽象
class Car
{
public:
	Car(Engine *engine)
	{
		m_engine = engine;
	}
	virtual void installengine() = 0;
protected:
	Engine *m_engine;
};
class BWM5 :public Car
{
public:
	BWM5(Engine *engine) :Car(engine){

	}
	virtual void installengine(){
		cout << "宝马5：";
		m_engine->InstallEngine();
	}
};
class BWM6 :public Car
{
public:
	BWM6(Engine *engine) :Car(engine){

	}
	virtual void installengine(){
		m_engine->InstallEngine();
	}
};

int main(){
	Engine *engine = NULL;
	BWM5 *bmw5 = NULL;
		 
	engine = new E4400;
	bmw5 = new BWM5(engine);
	bmw5->installengine();

	return 0;
}