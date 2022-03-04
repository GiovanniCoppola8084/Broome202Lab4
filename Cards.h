//-------------------------------------------------------------------------------------------------
//File Name: Cards.h
//Associated File: Cards.cpp
//Contains:
//  The class declarations for the card and deck classes
//  The declaration for the node structure type
//  A typedef for a node pointer
//  An enumerated type for the suits
//
//-------------------------------------------------------------------------------------------------

#ifndef Cards_h
#define Cards_h

//Include the header file for standards
#include "Standards.h"

//Enumerated type to apply ASCII values to the suits
enum suits { heart = 3, diamond, club, spade };

//Constant for the deck size
const int DECK_SIZE = 52;

//Class for the card type
class CardClassType
{

public:

    //Prototype for the constructor
    CardClassType(void);

    //Inline getter method for the rank
    int GetRank(void) { return rank; }
    //Inline getter method for the suit
    int GetSuit(void) { return suit; }

    //Inline setter method for the rank
    void SetRank(int aRank) { rank = aRank; }
    //Inline setter method for the suit
    void SetSuit(int aSuit) { suit = aSuit; }

    //Prototype for the overloaded == operator
    bool operator==(CardClassType card1);
    //Prototype for the overloaded < operator
    bool operator<(CardClassType card1);
    //Prototype for the overloaded > operator
    bool operator>(CardClassType card1);

    //Prototype for PrintCard method
    void PrintCard(int aRank, int aSuit);

private:

    //Integer for the rank of the card
    int rank;
    //Integer for the suit of the card
    int suit;

};

//Structure for the node type
struct nodeStructType
{

    //Data for the card
    CardClassType data;

    //Link for the nodes
    nodeStructType* link;

};

//Typedef for the node type
typedef nodeStructType* nodePtr;


//Class for the deck type
class DeckClassType
{

public:

    //Instantiate an array of 52 cards
    CardClassType deck[DECK_SIZE];

    //Get method to get the rank of the current deck card
    int GetRank(int index);

    //Get method to get the suit of the current deck card
    int GetSuit(int index);

    //Get method to get the current deck card
    CardClassType GetCard(int index);

	//Create the deck method
	void CreateTheDeck();

	//Shuffle the deck method
	void ShuffleTheDeck();

	//Swap method
	void Swap(int randomNumber, int index);

};

#endif // !Cards_h