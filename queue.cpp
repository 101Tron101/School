#include "queue.h"
#include <iostream>

/*
This whole template is a modified version of the one you can find in the book showing how to create a stack
It uses linked list to maintain the row and column pairs, but generates its own array so that it can fill
it's own array
*/

Queue::Queue()
{
	first = nullptr;
	last = nullptr;
	len = 0;
	pos = 1;
}

void Queue::push(int a, int b) {
	Pair* new_pair = new Pair;
	new_pair->row = a;
	new_pair->column = b;
	new_pair->next = nullptr;
	
	if (first == nullptr)
	{
		first = new_pair;
		last = new_pair;
	}
	else
	{

		last->next = new_pair;
		last = new_pair;

	}
	len++;
}

void Queue::top() const
{
	cout << first->row << ", " << first->column << endl;

}

void Queue::fill()
{
	do {
		/*
		based on the criteria given it will always fill stack from north,east,south,west, the operate on current node
		then fill stack again with n,s,e,w of current node etc
		*/
		Pair* to_delete = first;
		first = first->next;
		if (grid[to_delete->row][to_delete->column] == 0)
		{
			grid[to_delete->row][to_delete->column] = pos;
			pos++;


			if ((grid[to_delete->row - 1][to_delete->column] == 0) && (to_delete->row - 1 >= 0) && (to_delete->column >= 0))
			{
				Queue::push(to_delete->row -1, to_delete->column);
			}
			if ((grid[to_delete->row][to_delete->column + 1] == 0) && (to_delete->row >= 0) && (to_delete->column + 1 >= 0))
			{
				Queue::push(to_delete->row, to_delete->column + 1);
			}
			if ((grid[to_delete->row + 1][to_delete->column] == 0) && (to_delete->row + 1 >= 0) && (to_delete->column >= 0))
			{
				Queue::push(to_delete->row + 1, to_delete->column);
			}
			if ((grid[to_delete->row][to_delete->column - 1] == 0) && (to_delete->row >= 0) && (to_delete->column - 1 >= 0))
			{
				Queue::push(to_delete->row, to_delete->column - 1);
			}
		}

		delete to_delete;
		len--;
		/*if (len != 0)
		{
			Stack::fill();
		}*/
	} while (len != 0);
}

int Queue::size() const
{
	return len;
}

void Queue::print()
{
	cout << "Grid\n" << endl;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << grid[i][j] << "   ";
		}
		cout << '\n';
	}

	cout << endl;

}

void Queue::generate()
{

	/*
	forgot how to make a 2d array so used the one here as my template
	http://www.cplusplus.com/forum/beginner/141027/
	*/

	cout << "Grid\n" << endl;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			grid[i][j] = 0;
			cout << grid[i][j] << "   ";
		}
		cout << '\n';
	}

	cout << endl;

}