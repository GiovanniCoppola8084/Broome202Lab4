//-------------------------------------------------------------------------------------------------
//File Name: Stacks.cpp
//Associated File: Stacks.h
//Contains:
//  The function definitions for the stack class
//
//-------------------------------------------------------------------------------------------------

//Include the stack header file
#include "Stacks.h"

//-------------------------------------------------------------------------------------------------
//StackClassType - constructor for the stack class- created the stack
//-------------------------------------------------------------------------------------------------
StackClassType::StackClassType()
{

    CreateAStack();

}

//-------------------------------------------------------------------------------------------------
//~StackClassType - destructor for the stack class- delete the stack
//-------------------------------------------------------------------------------------------------
StackClassType::~StackClassType()
{

    //Destroy the stack
    DestroyStack();

}

//-------------------------------------------------------------------------------------------------
//IsEmpty - returns true if the list is empty and false otherwise
//-------------------------------------------------------------------------------------------------
bool StackClassType::IsEmpty()
{

    //Return if the top is equal to NULL
    return (top == NULL);

}

//-------------------------------------------------------------------------------------------------
//GetANode - creates new memory for the structure and adds the data and sets link to NULL
//-------------------------------------------------------------------------------------------------
nodePtr StackClassType::GetANode(int aRank, int aSuit)
{

    //Create a new node to allocate memory for
    nodePtr ptr = new nodeStructType;

    //Set the rank
    ptr->data.SetRank(aRank);

    //Set the suit
    ptr->data.SetSuit(aSuit);

    //Set the link to NULL
    ptr->link = NULL;

    //Return the pointer
    return ptr;

}

//-------------------------------------------------------------------------------------------------
//GetTop - accesses the number on top of the stack
//-------------------------------------------------------------------------------------------------
nodePtr StackClassType::GetTop()
{

    //Pointer to be used as the location of top
    nodePtr node = top;

    //If the deck is not empty
    if (!IsEmpty())
    {

        //Return the node pointer
        return node;

    }

}

//-------------------------------------------------------------------------------------------------
//Push - puts a new item on the stack and creates data for it
//-------------------------------------------------------------------------------------------------
void StackClassType::Push(int aRank, int aSuit)
{

    //Pointer used to hold the value of the previous node
    nodePtr node;

    //If the stack is empty
    if (IsEmpty())
    {

        //Add a new node by calling GetANode and setting the current node to the new one made
        node = GetANode(aRank, aSuit);

		//Set the top to node
		top = node;

    }
    else
    {

        //Add the new node to the top of the stack by calling GetANode
        node = GetANode(aRank, aSuit);

		//Set the current link to the top
		node->link = top;

		//Set the top link to the node
		top = node;

    }

}

//-------------------------------------------------------------------------------------------------
//Pop - takes an item off of the top of the stack and removes it
//-------------------------------------------------------------------------------------------------
nodePtr StackClassType::Pop()
{

    //Create a node pointer for the node that will be the new top
    nodePtr aNode;

	//Create a node pointer for the temporary value of the top before it is deleted
	nodePtr oldTop;

    //If the stack is not empty
    if (!IsEmpty())
    {

        //Set the current node equal to the top
        aNode = top;

        //Move the pointer along
        top = top->link;

        //Set the current link to null
        aNode->link = NULL;

		//Set the old top pointer to the top before it was moved along
		oldTop = aNode;

		//Delete the node
		delete aNode;

        //Return the new node
        return GetANode(oldTop->data.GetRank(), oldTop->data.GetSuit());

    }
	else
	{

		//Return NULL if the list is empty
		return NULL;

	}

}

//-------------------------------------------------------------------------------------------------
//CreateAStack - sets the top of the stack to NULL
//-------------------------------------------------------------------------------------------------
void StackClassType::CreateAStack()
{

    //Sets the top of the stack equal to NULL to show that the stack is empty
    top = NULL;

}

//-------------------------------------------------------------------------------------------------
//DestroyStack - removes everything off of the stack and returns the empty stack
//-------------------------------------------------------------------------------------------------
void StackClassType::DestroyStack()
{

    //Create a node pointer to be the stack that will become empty
    nodePtr aNode;

    //While the stack is not empty
    while (!IsEmpty())
    {

        //Call the pop node to delete all of the nodes
		Pop();

    }

}