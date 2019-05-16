#ifndef QUEUE_H
#define QUEUE_H	

#include <string>

using namespace std;

class Queue
{
public:
	Queue();
	void push(int a, int b);
	void top() const;
	void fill();
	int size() const;
	void print();
	void generate();

private:
	int grid[10][10];
	class Pair
	{
	public:
		int row;
		int column;
		Pair* next;
	};

	Pair* first;
	Pair* last;
	int pos;
	int len;


};
#endif