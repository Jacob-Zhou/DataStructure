#pragma once
enum boolean{True,False};
template<class T>
class LinearList
{
public:
	LinearList();
	virtual ~LinearList();
	virtual int Size() const = 0;
	virtual int Search(const T& target) const = 0;
	virtual int Locate(int index) const = 0;
	virtual T getData(int index) const = 0;
	virtual void setData(int index, const T& data) = 0;
	virtual boolean Insert(int index, const T& data) = 0;
	virtual boolean Romove(int index) = 0;
	virtual boolean IsEmpty() const = 0;
	virtual boolean IsFull() const = 0;
	virtual void Sort() = 0;
	virtual void input() = 0;
	virtual void output() = 0;
	virtual LinearList<T> operator=(const LinearList<T>& List) = 0;
	virtual boolean IsSequence const = 0;
private:
	int size = 0;
};

