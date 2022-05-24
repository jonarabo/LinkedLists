#pragma once

#include <iostream>
using namespace std;

#ifndef STAQUE
#define STAQUE

typedef int StaqueElement; 
class Staque
{
private:
	class Node
	{
	public:
		StaqueElement data; 
		Node* next;

		Node(StaqueElement value, Node* linkAddr = 0)
			: data(value), next(linkAddr) {}

	};

	typedef Node* NodePointer;

	NodePointer myTop; // Pointer to the top of the stack
	NodePointer myBottom; // Pointer to the bottom of the stack

public:

	Staque(); // Declaring the Staque object

	Staque(const Staque&); // Declaring the Staque copy constructor.

	~Staque(); // Declaring the Staque destructor

	bool empty() const; // Declaring the function to check if the Staque is empty or not.

	StaqueElement top() const; // Declaring the function that obtains the top value of the Staque.

	StaqueElement bottom() const; // Declaring the function that obtains the top value of the Staque.

	void push(StaqueElement num); // Declaring the function that will insert numbers into the Staque.

	void pop();					// Declaring the function that will remove numbers from the Staque.

	void display(ostream&) const; // Declaring the function that will display the Staque.
};


#endif
