#pragma once

#include"../../../Week_03_code/Week_03/list/double_list.h"
#include"../../../Week_03_code/Week_03/stack/stack_class.h"

// Declaration of a templated Queue class
template <typename T>
class Queue
{
private:
	Stack<T>* dataStack;   // Pointer to the main data stack
	Stack<T>* TempStack;   // Pointer to a temporary stack for operations

public:
	// Constructor: Initializes the data stack and temporary stack
	Queue()
	{
		dataStack = new Stack<T>;
		TempStack = new Stack<T>;
	}

	// Destructor: Frees the memory occupied by the data stack and temporary stack
	~Queue()
	{
		delete dataStack;
		delete TempStack;
	}

	// Function to check if the queue is empty
	bool Queueempty() { return dataStack->empty(); }

	// Function to push an element onto the queue
	void Queuepush(const T x)
	{
		dataStack->push(x);
	}

	// Function to get the front element from the queue
	T get()
	{
		T next;

		// Transfer elements from the data stack to the temporary stack
		while (!dataStack->empty())
		{
			TempStack->push(dataStack->pop());
		}

		// Get the front element from the temporary stack
		next = TempStack->pop();

		// Transfer elements back from the temporary stack to the data stack
		while (!TempStack->empty())
		{
			dataStack->push(TempStack->pop());
		}

		return next; // Return the front element of the queue
	}
};