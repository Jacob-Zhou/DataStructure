#pragma once
#include "LinearList.h"
#include <stdexcept>
#include <iostream>
#include <map>

enum ErrorMessage
{
	EMPTY = 1,
	WORRY_INDEX = 2,
	FULLED = 4
};

template<class T>
class SeqList :
	public LinearList<T>
{
public:
	SeqList();
	SeqList(const SeqList& SL);
	SeqList(const int& Size);
	virtual ~SeqList();
	virtual int Size() const override;
	int getMaxSize() const;
	int Search(const T& target) const;//其实我觉得这里返回对象指针会好一点！
	int Locate(int index) const;
	virtual T getData(int index) const override;
	virtual void setData(int index, const T& data) override;
	virtual boolean Insert(int index, const T& data) override;
	virtual boolean Remove(int index) override;
	virtual SeqList<T>* Resize(const int& Size) override;
	virtual boolean IsEmpty() const override;
	virtual boolean IsFull() const override;
	virtual void Sort() override;
	virtual void input() override;
	virtual void output() override;
	virtual SeqList<T>& operator=(const LinearList<T>& List) override;
	virtual SeqList<T>& operator=(const SeqList<T>& List);
	virtual boolean IsSequence() const;
private:
	boolean ErrorHandle(ErrorMessage message) const;
	boolean SetSize(const int& Size);
	bool IsInit() const;
	void move(T Data[]);
	T* DataArray;
	int size = 0;
	int maxSize = 0;
};

template<class T>
SeqList<T>::SeqList()
{
	DataArray = nullptr;
	maxSize = 0;
}

template<class T>
SeqList<T>::SeqList(const SeqList & SL)  //TODO
{
}

template<class T>
SeqList<T>::SeqList(const int & Size)
{
	this.Resize(Size);
	maxSize = Size;
}

template<class T>
SeqList<T>::~SeqList()
{
	delete DataArray;
	DataArray = nullptr;
}

template<class T>
int SeqList<T>::Size() const
{
	return size;
}

template<class T>
int SeqList<T>::getMaxSize() const
{
	return maxSize;
}

template<class T>
int SeqList<T>::Search(const T & target) const
{
	if (!IsInit())
	{
		ErrorHandle(EMPTY);
		return -1;
	}
	else {
		for (int i = 0; i < size; i++)
		{
			if (DataArray[i] == target)
			{
				return i + 1;
			}
		}
		return 0;
	}
}

template<class T>
int SeqList<T>::Locate(int index) const
{
	if (index <= 0 && index >= maxSize)
	{
		ErrorHandle(ErrorMessage::WORRY_INDEX);
		return -1;
	}
	else
	{
		return index - 1;
	}
}

template<class T>
T SeqList<T>::getData(int index) const
{
	if (!IsInit())
	{
		ErrorHandle(EMPTY);
		return -1;
	}
	else {
		return DataArray[Locate(index)];
	}
}

template<class T>
void SeqList<T>::setData(int index, const T & data)
{
	DataArray[Locate(index)] = data;
	return;
}

template<class T>
boolean SeqList<T>::Insert(int index, const T & data)
{
	if (!IsInit())
	{
		ErrorHandle(EMPTY);
		return False;
	}
	else if (this->IsFull() == True)
	{
		if (ErrorHandle(FULLED) == True)
		{
			return Insert(index, data);
		}
		else
		{
			std::cout << data << "未添加" << std::endl;
			return False;
		}
	}
	else
	{
		for (int i = size; i > Locate(index); i--)
		{
			DataArray[i] = DataArray[i - 1];
		}
		DataArray[Locate(index)] = data;
		size++;
		return True;
	}
}

template<class T>
boolean SeqList<T>::Remove(int index)
{
		if (!IsInit())
		{
			ErrorHandle(EMPTY);
			return False;
		}
		else
		{
			for (int i = Locate(index); i < Locate(size); i++)
			{
				DataArray[i] = DataArray[i + 1];
			}
			size--;
			return True;
		}
}

template<class T>
SeqList<T>* SeqList<T>::Resize(const int & Size)
{
	T* oldData = DataArray;
	DataArray = new T[Size];
	maxSize = Size;
	move(oldData);
	return this;
}

template<class T>
boolean SeqList<T>::IsEmpty() const
{
	if (maxSize == 0)
	{
		return False;
	}
	else
	{
		return True;
	}
}

template<class T>
boolean SeqList<T>::IsFull() const
{
	if (size == maxSize)
	{
		return True;
	}
	else
	{
		return False;
	}
}

template<class T>
void SeqList<T>::Sort() //TODO
{
}

template<class T>
void SeqList<T>::input()
{
	if (DataArray == nullptr)
	{
		int iSize;
		std::cout << "请输入顺序表的大小" << std::endl;
		std::cin >> iSize;
		Resize(iSize);
		size = iSize;
	}
	std::cout << "请输入 " << size << " 个数字" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cin >> DataArray[i];
	}
}

template<class T>
void SeqList<T>::output()
{
		if (!IsInit())
		{
			ErrorHandle(EMPTY);
		}
		else {
			std::cout << "[ ";
			for (int i = 0; i < size; i++)
			{
				std::cout << DataArray[i] << ", ";
			}
			std::cout << "\b\b ]" << std::endl;
		}
}

template<class T>
inline SeqList<T>& SeqList<T>::operator=(const LinearList<T>& List)
{
	return *this;
}


template<class T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& List)
{
	Resize(List.getMaxSize());
	SetSize(List.Size());
	for (int i = 0; i < getMaxSize(); i++)
	{
		DataArray[i] = List.getData(i + 1);
	}
	return *this;
}

template<class T>
boolean SeqList<T>::IsSequence() const
{
	return True;
}

template<class T>
boolean SeqList<T>::ErrorHandle(ErrorMessage message) const
{
	switch (message)
	{
	case 1:
	case 3:
	case 5:
	case 7:
		std::cout << "请初始化顺序表" << std::endl;
		return True;
		break;
	case 2:
		std::cout << "请输入正确的表项" << std::endl;
		return True;
		break;
	case 4:
		std::cout << "顺序表已满" << std::endl;
		std::cout << "是否扩充顺序表？" << " Y/N " << std::endl;
		char choice;
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			const_cast<SeqList<T>*>(this)->Resize(2 * maxSize);
			return True;
		}
		else
		{
			return False;
		}
	}
	return False;
}

template<class T>
inline boolean SeqList<T>::SetSize(const int & Size)
{
	if (Size > maxSize)
	{
		Resize(Size);
		return True;
	}
	else if (Size < 0)
	{
		return False;
	}
	else
	{
		size = Size;
		return True;
	}
}

template<class T>
inline bool SeqList<T>::IsInit() const
{
	if (this->DataArray == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<class T>
void SeqList<T>::move(T Data[])
{
	for (int i = 0; i < size; i++)
	{
		DataArray[i] = Data[i];
	}
	delete[] Data;
	Data = nullptr;
}
