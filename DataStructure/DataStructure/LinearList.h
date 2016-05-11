#pragma once
enum boolean{True,False};
template<class T>
class LinearList
{
public:
	LinearList();
	virtual ~LinearList();
	virtual int Size() const = 0;
	//virtual int Search(const T& target) const = 0;	书本上是用来返回表项的 顺序表和链表的实现方式不一样
	//virtual int Locate(int index) const = 0;			所以我觉得应该去掉；
	virtual T getData(int index) const = 0;
	virtual void setData(int index, const T& data) = 0;
	virtual boolean Insert(int index, const T& data) = 0;
	virtual boolean Remove(int index) = 0;
	virtual boolean IsEmpty() const = 0;
	virtual boolean IsFull() const = 0;
	virtual LinearList<T>* Resize(const int& Size) = 0;
	virtual void Sort() = 0;
	virtual void input() = 0;
	virtual void output() = 0;
	virtual LinearList<T>& operator=(const LinearList<T>& List) = 0;
	virtual boolean IsSequence() const = 0;
};

template<class T>
LinearList<T>::LinearList()
{
}

template<class T>
inline LinearList<T>::~LinearList()
{
}