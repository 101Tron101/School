#include <iostream>
#include "queue.h"

//https://www.youtube.com/watch?v=TCmkquGrmDQ&t=344s this video helped alot.
using namespace std;

int main()
{
	Queue Paint;
	Paint.generate();
	Paint.push(0, 0);
	Paint.fill();
	Paint.print();

}