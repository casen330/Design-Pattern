#include<iostream>
using namespace std;



//建造完车的一格部分以后，需要把任务传递下去
class CarHandle
{
public:
	virtual void HandleCar() = 0;
	CarHandle *setNextHandle(CarHandle *handle)
	{
		m_carhandle = handle;
		return m_carhandle;
	}
protected:
	CarHandle *m_carhandle; //要保存下一个数据单元
};
class HandleBody:public CarHandle
{
public:
	virtual void HandleCar(){
		cout << "make body" << endl;
		//造完车身后，如果有任务，就执行下一个任务
		if (m_carhandle!=NULL)
		{
			m_carhandle->HandleCar();
		}
	}
};
class HandleTail :public CarHandle
{
public:
	virtual void HandleCar(){
		cout << "make tail" << endl;
		//造完车身后，如果有任务，就执行下一个任务
		if (m_carhandle != NULL)
		{
			m_carhandle->HandleCar();
		}
	}
};
class HandleHead :public CarHandle
{
public:
	virtual void HandleCar(){
		cout << "make head" << endl;
		//造完车身后，如果有任务，就执行下一个任务
		if (m_carhandle != NULL)
		{
			m_carhandle->HandleCar();
		}
	}
};

int main(){
	CarHandle *handleHead = new HandleHead;
	CarHandle *handleBody = new HandleBody;
	CarHandle *handleTail = new HandleTail;

	//任务处理关系  类似于链表的存储，设置任务实行顺序
	handleHead->setNextHandle(handleBody);
	handleBody->setNextHandle(handleTail);
	handleTail->setNextHandle(NULL);

	//第一个任务开始
	handleHead->HandleCar();

						
	delete handleHead;
	delete handleBody;
	delete handleTail;


	return 0;
}