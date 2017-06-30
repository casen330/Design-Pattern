#include<iostream>
using namespace std;


typedef int Object; //模拟一个对象
#define SIZE 5

//抽象迭代器
class MyIterator
{
public:
	virtual void First() = 0; //迭代器指向头
	virtual void Next() = 0;  // 迭代器向下传
	virtual bool IsDone() = 0;// 判断迭代器是否到尾
	virtual Object CurrentItem() = 0; //返回当前对象
};
//抽象集合
class Aggregate
{
public:
	virtual MyIterator *CreateIterator() = 0;
	virtual Object getItem(int index) = 0;
	virtual int getSize() = 0;
};

//创建一个具体的迭代器
class ContreteIterator :public MyIterator
{
public:
	ContreteIterator(Aggregate *a)
	{
		_ag = a;  //初始化集合
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

//创建一个具体的集合
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
		return new ContreteIterator(this); //让迭代器持有一个集合的引用/指针
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
	Object object[SIZE]; //一个集合
};


int main(){

	Aggregate *ag = new ConcreteAggregate;
	//迭代器被那个集合创建，则这个迭代器就持有这个集合的引用
	MyIterator *it = ag->CreateIterator(); 

	for (; !(it->IsDone()); it->Next())
	{
		cout << it->CurrentItem() << endl;
	}
	
	delete ag;
	delete it;

	return 0;
}