#include<iostream>
#include<string>
#include<list>
using namespace std;

class Secretary;
//被观察者
class PlayserObserver
{
public:
	PlayserObserver(string n, Secretary *m)
	{
		m_name = n;
		this->m_sercretary = m;
	}
	void update(string action) //观察者更新信息
	{
		cout <<m_name<< " action: " << action << endl;
	}

private:
	string m_name;
	Secretary *m_sercretary;
};

class Secretary
{
public:
	Secretary(){
		m_list.clear();
	}
	void Notify(string info)
	{
		//给所有的 被观察者 发送信息
		for (list<PlayserObserver*>::iterator it = m_list.begin();
			it != m_list.end(); it++)
		{
			(*it)->update(info);
		}
	}
	void setPlayerOberserve(PlayserObserver *o)
	{
		m_list.push_back(o);
	}
private:
	list<PlayserObserver*> m_list;
};

int main(){
	Secretary *sec = NULL;
	PlayserObserver *p01 = NULL;
	PlayserObserver *p02 = NULL;

	sec = new Secretary;

	p01 = new PlayserObserver("cc",sec);
	p02 = new PlayserObserver("xx",sec);

	sec->setPlayerOberserve(p01);
	sec->setPlayerOberserve(p02);

	sec->Notify("老板来了");
	sec->Notify("老板走了");

	delete sec;
	delete p01;
	delete p02;

	return 0;
}