#include<iostream>
using namespace std;



//�����공��һ�񲿷��Ժ���Ҫ�����񴫵���ȥ
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
	CarHandle *m_carhandle; //Ҫ������һ�����ݵ�Ԫ
};
class HandleBody:public CarHandle
{
public:
	virtual void HandleCar(){
		cout << "make body" << endl;
		//���공�����������񣬾�ִ����һ������
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
		//���공�����������񣬾�ִ����һ������
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
		//���공�����������񣬾�ִ����һ������
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

	//�������ϵ  ����������Ĵ洢����������ʵ��˳��
	handleHead->setNextHandle(handleBody);
	handleBody->setNextHandle(handleTail);
	handleTail->setNextHandle(NULL);

	//��һ������ʼ
	handleHead->HandleCar();

						
	delete handleHead;
	delete handleBody;
	delete handleTail;


	return 0;
}