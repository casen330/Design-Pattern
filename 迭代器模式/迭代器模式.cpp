#include<iostream>
using namespace std;


typedef int Object; //ģ��һ������
#define SIZE 5

//���������
class MyIterator
{
public:
	virtual void First() = 0; //������ָ��ͷ
	virtual void Next() = 0;  // ���������´�
	virtual bool IsDone() = 0;// �жϵ������Ƿ�β
	virtual Object CurrentItem() = 0; //���ص�ǰ����
};
//���󼯺�
class Aggregate
{
public:
	virtual MyIterator *CreateIterator() = 0;
	virtual Object getItem(int index) = 0;
	virtual int getSize() = 0;
};

//����һ������ĵ�����
class ContreteIterator :public MyIterator
{
public:
	ContreteIterator(Aggregate *a)
	{
		_ag = a;  //��ʼ������
		_current_index = 0;
	}
	virtual void First()
	{
		_current_index = 0;
	}
	virtual void Next()
	{
		if (_current_index < _ag->getSize())
			_current_index++;
	}
	virtual bool IsDone()
	{
		return (_current_index == _ag->getSize());	
	}
	virtual Object CurrentItem()
	{
		return _ag->getItem(_current_index);
	}
private:
	int _current_index;
	Aggregate *_ag;
};

//����һ������ļ���
class ConcreteAggregate :public Aggregate
{
public:
	ConcreteAggregate()
	{
		for (int i = 0; i < SIZE; i++)
		{
			object[i] = i;
		}
	}
	virtual MyIterator *CreateIterator()
	{
		return new ContreteIterator(this); //�õ���������һ�����ϵ�����/ָ��
	}
	virtual Object getItem(int index)
	{
		return object[index];
	}
	virtual int getSize()
	{
		return SIZE;
	}
private:
	Object object[SIZE]; //һ������
};


int main(){

	Aggregate *ag = new ConcreteAggregate;
	//���������Ǹ����ϴ�����������������ͳ���������ϵ�����
	MyIterator *it = ag->CreateIterator(); 

	for (; !(it->IsDone()); it->Next())
	{
		cout << it->CurrentItem() << endl;
	}
	
	delete ag;
	delete it;

	return 0;
}