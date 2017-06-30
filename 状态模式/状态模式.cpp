#include<iostream>
using namespace std;

class Worker;
class State
{
public:
	virtual void doSomeThing(Worker *w) = 0;
};

class Worker
{
public:
	Worker();
	int getHour()
	{
		return m_hour;
	}
	void setHour(int hour) //改变状态7
	{
		m_hour = hour;
	}
	State* getCurrentState()
	{
		return m_currstate;
	}
	void setCurrentState(State* state)
	{
		m_currstate = state;
	}

	void doSomtThing()
	{
		m_currstate->doSomeThing(this);
	}
private:
	int m_hour;
	State *m_currstate; //对象当前的状态
};

class State1 :public State
{
public:
	void doSomeThing(Worker *w);
};

class State2 :public State
{
public:
	void doSomeThing(Worker *w);
};

void State1::doSomeThing(Worker *w)
{
	if (w->getHour()==7 || w->getHour()==8)
	{
		cout << "吃早饭" << endl;
	}
	else
	{
		delete w->getCurrentState(); //状态1 不满足 要转到状态2
		w->setCurrentState(new State2);
		w->getCurrentState()->doSomeThing(w);
	}
}

void State2::doSomeThing(Worker *w)
{
	if (w->getHour() == 9 || w->getHour() == 10)
	{
		cout << "上班" << endl;
	}
	else
	{
		delete w->getCurrentState(); //状态1 不满足 要转到状态2
		w->setCurrentState(new State1);
		cout << "当前时间点：" << w->getHour() << "未知状态" << endl;
	}
}

Worker::Worker()
{
	m_currstate = new State1;
}

void main(){
	Worker *w1 = new Worker;
	w1->setHour(7);
	w1->doSomtThing();

	w1->setHour(9);
	w1->doSomtThing();

	w1->setHour(11);
	w1->doSomtThing();

	delete w1;
}