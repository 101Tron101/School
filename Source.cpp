#include <iostream>
#include "stack.h"


using namespace std;

int main()
{
	Stack Paint;
	Paint.generate();
	Paint.push(2, 2);
	Paint.fill();
	Paint.print();

	return 0;

}