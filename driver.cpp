#include <iostream>
using namespace std;

#include "Staque.h"

void print(Staque st)
{
	st.display(cout);
}

int main()
{
	Staque s;
	cout << "The Staque is as follows:" << endl;
	cout << endl;

	cout << "(FRONT)" << endl;
	
	s.push(1);  //Hardcoding the values to be pushed into the Staque (Change each one to change the values in the Staque.)
	s.push(3);
	s.push(2);
	s.push(4);
	s.push(6);
	s.push(8);
	s.push(9);
	
	s.display(cout);      // This will display the Staque with the values that were hardcoded.

	cout << "(BACK)" << endl;
	cout << endl;
	cout << "The top value is: " << s.top() << endl;          // This will display the value at the top of the Staque.
	cout << "The bottom value is: " << s.bottom() << endl;    // This will display the value at the bottom of the Staque.
	cout << endl;
	s.pop();												 // This will call for the user to pop an even or odd 3 separate times.
	s.pop();
	s.pop();
	
	cout << endl;
	
	cout << "After popping, the new Staque is: " << endl;
	cout << "(FRONT)" << endl;
	s.display(cout);										// The new Staque after popping the numbers will be displayed.
	cout << "(BACK)" << endl;
	cout << endl;
	cout << "The top value is: " << s.top() << endl;		// The value at the top of the new Staque will be displayed.
	cout << "The bottom value is: " << s.bottom() << endl;	// The value at the bottom of the new Staque will be displayed.

}

