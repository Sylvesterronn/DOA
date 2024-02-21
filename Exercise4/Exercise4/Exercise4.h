#pragma once

#include"../../../Week_03_code/Week_03/list/double_list.h"
#include"../../../Week_03_code/Week_03/stack/stack_class.h"

template <typename T>
class Queue
{
private:
	Stack <T> *dataStack;
	Stack <T> *TempStack;

public:
	Queue()
	{
		dataStack = new Stack<T>;
		TempStack = new Stack<T>;



	}

	~Queue()
	{
		delete dataStack;
		delete TempStack;
	}

	bool Queueempty() { return dataStack->empty(); }


	void Queuepush(const T x)
	{
		dataStack->push(x);
	}

	T get() 
	{ 
		T next;

		while (!dataStack->empty())
		{
			TempStack->push(dataStack->pop());
		}
		next = TempStack->pop();

		while (!TempStack->empty())
		{
			dataStack->push(TempStack->pop());
		}

		return next;

	};



};