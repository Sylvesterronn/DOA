#include<iostream>
#include"Exercise4.h"

int main()
{
	Queue<int>*queuetest = new Queue<int>();

	queuetest->Queuepush(2);
	queuetest->Queuepush(5);
	queuetest->Queuepush(8);

	while (!queuetest->Queueempty())
	{
		std::cout << "Next element:  " << queuetest->get() << std::endl;
	}

	delete queuetest;

	return 0;
}