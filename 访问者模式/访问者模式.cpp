#include<iostream>
#include<list>
using namespace std;

class ParkElement;

//访问者，抽象
class Visitor
{
public:
	virtual void visit(ParkElement *p) = 0;
};
//元素部分，抽象
class ParkElement
{
public:
	virtual void accept(Visitor *v) = 0;
};

//具体公园部分
class ParkA :public ParkElement
{
public:
	virtual void accept(Visitor *v)
	{
		v->visit(this);  //公园接收访问者访问，让访问者访问
	}
};
class ParkB :public ParkElement
{
public:
	virtual void accept(Visitor *v)
	{
		v->visit(this);  //公园接收访问者访问，让访问者访问
	}
};

//整个公园
class Park :public ParkElement
{
public:
	Park(){
		m_list.clear();
	}
	void setParkElement(ParkElement *p){
		m_list.push_back(p);
	}
	void accept(Visitor *v)
	{
		for (list<ParkElement *>::iterator it = m_list.begin();
			it != m_list.end(); it++)
		{
			//下面两种是一个意思
			(*it)->accept(v); //公园A部分，B部分接收管理者访问
			v->visit(*it);  //管理者访问A部分，B部分
		}
	}
private:
	list<ParkElement *> m_list;
};



//具体访问者
class VisitorA :public Visitor
{
public:
	virtual void visit(ParkElement *p)
	{
		cout << "清洁工A 完成 公园A部分的打扫。" << endl;
	}
};
class VisitorB :public Visitor
{
public:
	virtual void visit(ParkElement *p)
	{
		cout << "清洁工B 完成 公园A部分的打扫。" << endl;
	}
};

//管理者
class ManagerVisitor :public Visitor
{
public:
	virtual void visit(ParkElement *p)
	{
		cout << "管理者访问公园的各个部分" << endl;
	}
};

void main1(){
	Visitor *vA = NULL;
	Visitor *vB = NULL;
	ParkElement *pA = NULL;
	ParkElement *pB = NULL;
	vA = new VisitorA;
	vB = new VisitorB;
	pA = new ParkA;
	pB = new ParkB;

	pA->accept(vA);
	pB->accept(vB);

	delete vA;
	delete vB;
	delete pA;
	delete pB;
}

void main2(){
	Visitor *vM = NULL;
	Park *p = NULL;
	ParkElement *pA = NULL;
	ParkElement *pB = NULL;
	vM = new ManagerVisitor;
	p = new Park;
	pA = new ParkA;
	pB = new ParkB;
	p->setParkElement(pA);
	p->setParkElement(pB);
	//整个公园接受 管理者访问
	p->accept(vM);
	delete vM;
}


int main(){
	//main1();
	main2();
	return 0;
}