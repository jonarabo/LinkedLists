#include <iostream>
#include <new>
using namespace std;

#include "Staque.h"

Staque::Staque() :myTop(0) {}              // Defining the Staque constructor.

Staque::Staque(const Staque& original)     // Defining the Staque copy constructor.
{
    myTop = 0;
    myBottom = 0;
    if (!original.empty())
    {
        
        myTop = new Staque::Node(original.top()); // This will copy the first node.


        Staque::NodePointer lastPtr = myTop, // Creating new pointers that will go through the linked lists.
            origPtr = original.myTop->next;

        while (origPtr != 0)
        {
            lastPtr->next = new Staque::Node(origPtr->data);
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    }
}


Staque::~Staque()                                   //Defining the Staque destructor.
{     
   Staque::NodePointer currPtr = myTop,             // Creating new pointers that will go through the Staque and ultimately be deallocated.
                      nextPtr;          
   while (currPtr != 0)
   {
      nextPtr = currPtr->next;
      delete currPtr;
      currPtr = nextPtr;
   }
}

bool Staque::empty() const                     // Defining the function that checks if the Staque is empty or not.
{
    return (myTop == 0);
}

StaqueElement Staque::top() const              // Defining the function that obtains the value at the top of the Staque.
{
    if (!empty())                               // Checks Staque to make sure it is not empty
        return (myTop->data);                   // If it is not empty, it will return and store the value at the top of the Staque
    else                                        // Otherwise, an error will be outputted and the code will create a temp element to store the garbage value.
    {
        cerr << "*** Stack is empty " " -- returning garbage ***" << endl;
        StaqueElement* temp = new(StaqueElement);
        StaqueElement garbage = *temp;     
        delete temp;                            // The temp value gets deleted and the value returned is a random number that we consider "garbage"
        return garbage;
    }
}

StaqueElement Staque::bottom() const {       // Defining the function that obtains the value at the bottom of the Staque. (Performs the same actions as above, except returns the bottom value if not empty)
    if (!empty())
        return (myBottom->data);
    else
    {
        cerr << "*** Stack is empty " " -- returning garbage ***" << endl;
        StaqueElement* temp = new(StaqueElement);
        StaqueElement garbage = *temp;     
        delete temp;
        return garbage;
    }
}


void Staque::display(ostream& out) const        // Defining the function that will display the Staque
{
    Staque::NodePointer ptr;
    for (ptr = myTop; ptr != 0; ptr = ptr->next)
        out << ptr->data << endl;
}


void Staque::push(StaqueElement num) {          // Defining the function that will allow us to insert values into the staque.

    if (empty()) {                              // Creating a general rule if the Staque is empty that will create a node and make myBottom and myTop point to it.
        myTop = new Staque::Node(num, myTop);
        myBottom = myTop;
    }
    else {

        if (num % 2 == 0) {                        // Creating an if statement for even numbers to be added to the top of the staque.
            myTop = new Staque::Node(num, myTop);

        }

        else {                                              // Otherwise, the numbers are odd and will be placed at the bottom of the stack.
            myBottom->next = new Staque::Node(num, NULL);
            myBottom = myBottom->next;
        }
    }
}


void Staque::pop() {                            // Defining the function that will allow us to remove values from the staque.
    
    char popChar; 
    
    cout << "Please enter the character O to pop an odd number" << endl;
    cout << "OR" << endl;
    cout << "Please enter the character E to pop an even number" << endl;
    
    cin >> popChar;                                 // Prompting the user to enter either O or E depending on what number they would like to pop.


    if (!empty()) {                                 // First checking if the Staque is empty, if is not, move onto the next condition.

        if (popChar == 'E') { // If the user will like to pop an even number, they will press E and the code following it will remove the top value of the Staque, which is first even number of the Staque.
            NodePointer topPtr = myTop; 
            myTop = myTop->next; 
            if (myTop->next == NULL)
                myBottom = myTop; 
            cout << "Popping... " << topPtr->data << endl;                 // The user will be told the number they are popping and it will be deleted from the Staque. 
            cout << "POPPED: " << topPtr->data << endl << endl;
            delete topPtr; 

        }

        else if (popChar == 'O') { // If the user will like to pop an even number, they will press O and the code following it will remove the top value of the Staque, which is first odd number of the Staque.
            
            NodePointer currPtr = myTop;            // Creating separate temporary pointers. 
            NodePointer nextPtr = currPtr->next;

            if (nextPtr == NULL) {                 // If there is nothing the nextPtr can point too, the Staque is completed.
                myTop = NULL;
                myBottom = NULL;
                cout << "Popping... " << currPtr->data << endl;                 
                cout << "POPPED: " << currPtr->data << endl << endl;
                delete currPtr;
            }
            else {
                while (nextPtr->next != NULL) {  // If there is something that nextPtr can point to, the following code will build the new "bridges" to link the numbers together. (Traversing)
                    currPtr = currPtr->next; 
                    nextPtr = currPtr->next; 
                }

                currPtr->next = NULL; 
                myBottom = currPtr;
                currPtr = NULL;
                cout << "Popping... " << nextPtr->data << endl;             // Again, the user will be told the number the odd number they are popping and it will be deleted from the staque.
                cout << "POPPED: " << nextPtr->data << endl << endl;
                delete nextPtr;
            }
        }
    }
    else {
        cerr << "Staque is empty!" << endl;                                 // The error that will return if the first check does not pass. It will tell the user that the Staque is empty.
    }
}


    
    