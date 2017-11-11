#pragma once
template<class T>
class TStack
{
protected:
	int Size, MaxSize;
	T *mas;
public:
	TStack(int _MaxSize = 100)
	{
		MaxSize = _MaxSize;
	Size = 0;
		mas = new T[Maxsize];
	}
	TStack(const Tstack & ts)
	{
		MaxSize = ts.MaxSize;
		Size = ts.Size;
		mas = new T[MaxSize];
		for (int i = 0; i < Size; i++)
			mas[i] = ts.mas[i];
	}
	bool IsEmpty()
	{
		if (Size == 0)
			return true;
		else return false;
	}
	bool IsFull()
	{
		if (size == MaxSize)
			return true;
		else return false;
	}
	void Push(T a)
	{
		if (IsFull())
			throw - 1;
		mas[Size] = a;
		Size++;
	}
	T Top() const
	{
		if (IsEmpty)
			throw - 1;
		return mas[Size];
	}
	T Pop()
	{
		if (IsEmpty())
			throw - 1;
		size--;
		return mas[Size];
	}
	void ClearStack()
	{
		Size = 0;
	}
};