//-------------------------------------------------------------------------------------------------
//File Name: Cards.cpp
//Associated File: Cards.h
//Contains:
//  The function definitions for the card and deck classes
//
//-------------------------------------------------------------------------------------------------

//Include the header file for Cards
#include "Cards.h"

//-------------------------------------------------------------------------------------------------
//Cards - constructor for cards (sets all variables to zero)
//-------------------------------------------------------------------------------------------------
CardClassType::CardClassType(void)
{

    //Set the rank to zero
    rank = 0;

    //Set the suit to zero
    suit = 0;

}

//-------------------------------------------------------------------------------------------------
//operator== - overloaded method for the == operator to compare cards directly
//-------------------------------------------------------------------------------------------------
bool CardClassType::operator==(CardClassType card1)
{

    //If the suit and rank are equal to each other
    if (card1.GetRank() == rank)
    {

        //Return true
        return true;

    }
    else
    {

        //Return false
        return false;

    }

}

//-------------------------------------------------------------------------------------------------
//operator< - overloaded method for the < operator to compare cards directly
//-------------------------------------------------------------------------------------------------
bool CardClassType::operator<(CardClassType card1)
{

    //If the suit and rank of card 1 are less than that of card 2
    if (card1.GetRank() < rank)
    {

        //Return true
        return false;

    }
    else
    {

        //Return false
        return true;

    }

}

//-------------------------------------------------------------------------------------------------
//operator> - overloaded method for the > operator to compare cards directly
//-------------------------------------------------------------------------------------------------
bool CardClassType::operator>(CardClassType card1)
{

    //If the suit and rank of card 1 are greater than that of card 2
    if (card1.GetRank() > rank)
    {

        //Return true
        return false;

    }
    else
    {

        //Return false
        return true;

    }

}

//-------------------------------------------------------------------------------------------------
//PrintCard - prints a card based on the part of the deck that was passed in
//-------------------------------------------------------------------------------------------------
void CardClassType::PrintCard(int aRank, int aSuit)
{

	//Create a character that will be used to print the character of the rank
	char printChar = 'J';

	//If the card rank is between 2 and 10
	if (aRank >= 2 && aRank <= 10)
	{

		//Print the card to the output file
		cout << aRank << left << setw(5) << (char)suit;

	}
	else
	{

		//Switch statement for the rank for if it is J, Q, K, or A
		switch (aRank)
		{

			//If the rank is 11
		case 11:
			//Set the print character to a J
			printChar = 'J';
			break;
			//If the rank is 12
		case 12:
			//Set the print character to a Q
			printChar = 'Q';
			break;
			//If the rank is 13
		case 13:
			//Set the print character to a K
			printChar = 'K';
			break;
			//If the character is an A
		case 14:
			//Set the print character to an ace
			printChar = 'A';
			break;

		}

		//Print the card to the output file
		cout << printChar << left << setw(5) << (char)suit;

	}

}

//-------------------------------------------------------------------------------------------------
//GetRank - return the rank of the current card
//-------------------------------------------------------------------------------------------------
int DeckClassType::GetRank(int index)
{

    //Return the rank of the card
    return deck[index].GetRank();

}

//-------------------------------------------------------------------------------------------------
//GetSuit - returns the suit of the current deck
//-------------------------------------------------------------------------------------------------
int DeckClassType::GetSuit(int index)
{

    //Return the suit of the card
    return deck[index].GetSuit();

}

//-------------------------------------------------------------------------------------------------
//GetCard - returns the card at index
//-------------------------------------------------------------------------------------------------
CardClassType DeckClassType::GetCard(int index)
{

    //Return the suit of the card
    return deck[index];

}

//-------------------------------------------------------------------------------------------------
//CreateTheDeck - create the deck in order of suit and rank
//-------------------------------------------------------------------------------------------------
void DeckClassType::CreateTheDeck()
{

	//Set the first rank to 1
	int aRank = 2;

	//Set the first suit to heart
	int aSuit = heart;

	//Use a for loop to loop through and fill the deck
	for (int index = 0; index < DECK_SIZE; index++)
	{

		//Set the rank of the card
		deck[index].SetRank(aRank);

		//Set the suit of the card
		deck[index].SetSuit(aSuit);

		//Increment the value of the rank
		aRank++;

		//If the rank is greater than 14
		if (aRank > 14)
		{

			//Set the back down to 1
			aRank = 2;

            //Increment the suit
            aSuit++;

		}

	}

}

//-------------------------------------------------------------------------------------------------
//ShuffleTheDeck - shuffle the entire deck passed in at somewhat random intervals
//-------------------------------------------------------------------------------------------------
void DeckClassType::ShuffleTheDeck()
{

    //Set the time space to NULL
    srand(time(NULL));

	//Create a random number integer
	int randomNumber;

	//For loop to loop through each one of the cards in the deck
	for (int index = 0; index < DECK_SIZE; index++)
	{

		//Create a random number from 0 to the deck size
		randomNumber = rand() % DECK_SIZE;

		//Swap the indexed card and the random card
		Swap(randomNumber, index);

	}

}

//-------------------------------------------------------------------------------------------------
//Swap - swap two cards at a random integer and index
//-------------------------------------------------------------------------------------------------
void DeckClassType::Swap(int randomNumber, int index)
{

	//Create a temporary card
	CardClassType temp;

	//Set the temp equal to the random number
	temp = deck[randomNumber];

	//Set the random card to the indexed card
	deck[randomNumber] = deck[index];

	//Set the indexed card to the temp
	deck[index] = temp;

}