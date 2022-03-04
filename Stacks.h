//-------------------------------------------------------------------------------------------------
//File Name: Stacks.h
//Associated File: Stacks.cpp
//Contains:
//  The declaration for the stack class
//
//-------------------------------------------------------------------------------------------------

#ifndef Stacks_h
#define Stacks_h

//Include the cards header file
#include "Cards.h"

//Stack Class
class StackClassType
{

public:

    //Constructor for the stack class
    StackClassType();

    //Destructor for the stack class
    ~StackClassType();

	//IsEmpty method for the deck stack
	bool IsEmpty();

	//GetANode method for the deck stack
	nodePtr GetANode(int aRank, int aSuit);

	//GetTop method for the deck stack
	nodePtr GetTop();

	//Push method for the deck stack
    void Push(int aRank, int aSuit);

	//Pop method for the deck stack
	nodePtr Pop();

	//CreateAStack method for the deck stack
	void CreateAStack();

	//DestroyStack method for the stack
	void DestroyStack();

private:

	//Top of the stack
	nodePtr top;

};

#endif // !Stacks_h

