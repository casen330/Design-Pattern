#include<iostream>
#include<list>
#include<string>
using namespace std;
//文件抽象
class IFile
{
public:
	virtual void display() = 0;
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;
	virtual list<IFile*> *getChild() = 0;
};
//文件
class File :public IFile
{
public:
	File(string name){
		m_name = name;
	}
	virtual void display(){
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile){
		return -1;
	}
	virtual int remove(IFile *ifile){
		return -1;
	}
	virtual list<IFile*> *getChild(){
		return NULL;
	}
private:
	string m_name;
};
//目录结点
class Dir :public IFile
{
public:
	Dir(string name){
		m_name = name;
		m_list = new list<IFile*>;
		m_list->clear();
	}
	virtual void display(){
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile){
		m_list->push_back(ifile);
		return 0;
	}
	virtual int remove(IFile *ifile){
		m_list->remove(ifile);
		return 0;
	}
	virtual list<IFile*> *getChild(){
		return m_list;
	}
private:
	string m_name;
	list<IFile*> *m_list;
};

int main(){
	Dir *diroot = new Dir("c");
	diroot->display();

	Dir *dir1 = new Dir("dir111");
	File *file1 = new File("file111");

	diroot->display();
	//获取root结点下的  孩子集合
	list<IFile*> *mylist = diroot->getChild();

	diroot->add(dir1);
	diroot->add(file1);

	for (list<IFile*>::iterator it = mylist->begin(); it != mylist->end(); it++)
	{
		(*it)->display();
	}
	return 0;
}