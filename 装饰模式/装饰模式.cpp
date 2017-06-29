#include<iostream>
using namespace std;

class Car
{
public:
	virtual void show() = 0;
};

class RunCar :public Car
{
public:
	virtual void show(){
		cout << "Can run..." << endl;
	}
};

class SwimCarDirection :public Car
{
public:
	SwimCarDirection(Car *car){
		m_car = car;
	}
	//重写虚函数，增强功能
	virtual void show(){
		m_car->show();
		cout << "Can swimming..." << endl;
	}
private:
	Car *m_car;
};

class FlyCarDirection :public Car
{
public:
	FlyCarDirection(Car *car)
	{
		m_car = car;
	}
	virtual void show(){
		m_car->show();
		cout << "Can fly..." << endl;
	}
private:
	Car *m_car;
};


int main(){

	Car *mycar = NULL;
	mycar = new RunCar;
	mycar->show();
	cout << ">>>>>>>>>>>>" << endl;
	FlyCarDirection *flycar = new FlyCarDirection(mycar);
	flycar->show();
	cout << ">>>>>>>>>>>>>>" << endl;
	SwimCarDirection *swimcar = new SwimCarDirection(flycar);
	swimcar->show();
	delete mycar;
	delete flycar;
	delete swimcar;
	return 0;
}