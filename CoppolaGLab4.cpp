//-------------------------------------------------------------------------------------------------
//File Name: CoppolaGLab4.cpp
//Associated File: Cards.cpp and Stack.h
//Contains:
//  DealTheCards - function to deal all of the cards to the user and the computer
//  PlayTheGame - function to play the game of war
//  PlayWar - function to determine the winner of a tie
//  AreDecksEmpty - function to determine if the user's or the computer's decks are empty
//  mainDeck - main deck of the deck class type
//  Stacks for the user and the computer (table, main deck, and winning pile)
//
//-------------------------------------------------------------------------------------------------

//Include the header file for Cards
#include "Cards.h"

//Include the header file for the stacks
#include "Stacks.h"

//Prototype for the deal the cards function
void DealTheCards(DeckClassType& mainDeck, StackClassType& userDeck, StackClassType& computerDeck, int index);

//Prototype for the play the game function
void PlayTheGame(StackClassType& userDeck, StackClassType& computerDeck, StackClassType& tableDeckUser, 
    StackClassType& tableDeckComputer, StackClassType& userWinners, StackClassType& computerWinners);

//Prototype for the PlayWar function
void PlayWar(StackClassType& userDeck, StackClassType& computerDeck, StackClassType& userWinners,
    StackClassType& computerWinners, StackClassType& tableDeckUser, StackClassType& tableDeckComputer);

//Prototype for the AreDecksEmpty function
void AreDecksEmpty(StackClassType& userDeck, StackClassType& userWinners, 
    StackClassType& computerDeck, StackClassType& computerWinners);

int main(void)
{

	//Create a deck for the main pile that will be dealt out at the beginning of the game
	DeckClassType mainDeck;

	//Create a stack that will be used for the user playing the game
	StackClassType userDeck;

	//Create a stack that will be used for the computer playing the game
	StackClassType computerDeck;

	//Create a stack that will be used for the pile on the table for the user
	StackClassType tableDeckUser;

    //Create a stack that will be used for the pile on the table for the computer
    StackClassType tableDeckComputer;

    //Create a stack that will be used as the user's winning pile
    StackClassType userWinners;

    //Create a stack that will be used as the computer's winning pile
    StackClassType computerWinners;

	//Create the main deck
	mainDeck.CreateTheDeck();
	
	//Shuffle the deck
	mainDeck.ShuffleTheDeck();

    //Create an index that will be used in the recursive call of the deal function
    int index = 0;

    //Deal the deck of cards to the user and the computer
    DealTheCards(mainDeck, userDeck, computerDeck, index);

    //Call the play the game function
    PlayTheGame(userDeck, computerDeck, tableDeckUser, tableDeckComputer, userWinners, computerWinners);

    return 0;

}

//-------------------------------------------------------------------------------------------------
//DealTheCards - deal the cards to the user and the computer
//-------------------------------------------------------------------------------------------------
void DealTheCards(DeckClassType& mainDeck, StackClassType& userDeck, StackClassType& computerDeck, int index)
{

    //If the index is less than the deck size
    if (index < DECK_SIZE)
    {

        //If the current card is even, deal it to the user
        if (index % 2 == 0)
	    {

		    //Push the cards to the user deck
            userDeck.Push(mainDeck.GetRank(index), mainDeck.GetSuit(index));

	    }
        else
        {

            //Push the cards to the computers deck
            computerDeck.Push(mainDeck.GetRank(index), mainDeck.GetSuit(index));

        }

        //Increment the index
        index++;

        //Recursive call of the DealTheCards function
        DealTheCards(mainDeck, userDeck, computerDeck, index);

    }

}

//-------------------------------------------------------------------------------------------------
//PlayTheGame - function to play the war game between the user and the computer
//-------------------------------------------------------------------------------------------------
void PlayTheGame(StackClassType& userDeck, StackClassType& computerDeck, StackClassType& userWinners,
    StackClassType& computerWinners, StackClassType& tableDeckUser, StackClassType& tableDeckComputer)
{

    //Create an int variable that will be used to either display the whole game or just the winner
    int output;

    //Prompt the user to either print the whole game or the winner
    cout << "Enter a 1 for the whole game to be shown or a 2 for just the winner to be shown: ";
    cin >> output;
    cout << endl;

    //If the output is a 1
    if (output == 1)
    {

        //While both of the decks are still not empty
        while (!userDeck.IsEmpty() && !computerDeck.IsEmpty())
        {

            //Print that the user's card will be output
            cout << "User: ";

            //Print the user's card
            userDeck.GetTop()->data.PrintCard(userDeck.GetTop()->data.GetRank(), 
                userDeck.GetTop()->data.GetSuit());

            //Push the top card of the user deck to the table deck
            tableDeckUser.Push(userDeck.GetTop()->data.GetRank(), 
                userDeck.GetTop()->data.GetSuit());

            //Pop the top of the card off the user deck
            userDeck.Pop();

            //Print that the computer's card will be output
            cout << "Computer: ";

            //Print the computer's card
            computerDeck.GetTop()->data.PrintCard(computerDeck.GetTop()->data.GetRank(), 
                computerDeck.GetTop()->data.GetSuit());

            //Push the top card of the computer deck to the table deck
            tableDeckComputer.Push(computerDeck.GetTop()->data.GetRank(), 
                computerDeck.GetTop()->data.GetSuit());

            //Pop the top off of the computer deck
            computerDeck.Pop();

            //If there is a draw
            if (tableDeckUser.GetTop()->data == tableDeckComputer.GetTop()->data)
            {

                //If the output is a 1
                if (output == 1)
                {

                    //Print that there is a tie and ask if the user wants to continue
                    cout << "\nThere is a tie. Each player will have to place down 3 cards face down " <<
                        "and then turn the last card face up. 1 to continue and 2 to go to the end. ";
                    cin >> output;

                }
                cout << "We will now continue on with the war. " << endl;

                //Call the play war function
                PlayWar(userDeck, computerDeck, userWinners, computerWinners, tableDeckUser, tableDeckComputer);

            }
            //If the user's card is less than the computer's card
            else if (tableDeckUser.GetTop()->data < tableDeckComputer.GetTop()->data)
            {

                //Move the user's card to the computer's winning pile
                computerWinners.Push(tableDeckUser.GetTop()->data.GetRank(),
                    tableDeckUser.GetTop()->data.GetSuit());

                //Move the computer's card to the computer's winning pile
                computerWinners.Push(tableDeckComputer.GetTop()->data.GetRank(),
                    tableDeckComputer.GetTop()->data.GetSuit());

                //Pop the cards off of the table for the user
                tableDeckUser.Pop();

                //Pop the cards off of the table for the computer
                tableDeckComputer.Pop();

                //Print that the computer won that round
                cout << "\nThe computer won that round!" << endl;

                //Print the divider to the screen
                PrintDivider('-', 100);

                //If the output is a 1
                if (output == 1)
                {

                    //Let the user know they can wait and continue when ready
                    cout << "Enter a 1 when ready for the next round or a 2 to go to the end: ";
                    cin >> output;

                }

            }
            //If the user's card is greater than the computer's card
            else if (tableDeckUser.GetTop()->data > tableDeckComputer.GetTop()->data)
            {

                //Move the user's card to the user's winning pile
                userWinners.Push(tableDeckUser.GetTop()->data.GetRank(),
                    tableDeckUser.GetTop()->data.GetSuit());

                //Move the computer's card to the user's winning pile
                computerWinners.Push(tableDeckComputer.GetTop()->data.GetRank(),
                    tableDeckComputer.GetTop()->data.GetSuit());

                //Pop the cards off of the table for the user
                tableDeckUser.Pop();

                //Pop the cards off of the table for the computer
                tableDeckComputer.Pop();

                //Print that the user won that round
                cout << "\nThe user won that round!" << endl;

                //Print the divider to the screen
                PrintDivider('-', 100);

                //If the output is a 1
                if (output == 1)
                {

                    //Let the user know they can wait and continue when ready
                    cout << "Enter a 1 when ready for the next round or a 2 to go to the end: ";
                    cin >> output;

                }

            }

            //Call the AreDecksEmpty function
            AreDecksEmpty(userDeck, userWinners, computerDeck, computerWinners);

        }

    }
    else if (output == 2)
    {

        //While both of the decks are still not empty
        while (!userDeck.IsEmpty() && !computerDeck.IsEmpty())
        {

            //Print that the user's card will be output
            cout << "User: ";

            //Print the user's card
            userDeck.GetTop()->data.PrintCard(userDeck.GetTop()->data.GetRank(), 
                userDeck.GetTop()->data.GetSuit());

            //Push the top card of the user deck to the table deck
            tableDeckUser.Push(userDeck.GetTop()->data.GetRank(), 
                userDeck.GetTop()->data.GetSuit());

            //Pop the top of the card off the user deck
            userDeck.Pop();

            //Print that the computer's card will be output
            cout << "Computer: ";

            //Print the computer's card
            computerDeck.GetTop()->data.PrintCard(computerDeck.GetTop()->data.GetRank(), 
                computerDeck.GetTop()->data.GetSuit());

            //Push the top card of the computer deck to the table deck
            tableDeckComputer.Push(computerDeck.GetTop()->data.GetRank(), 
                computerDeck.GetTop()->data.GetSuit());

            //Pop the top off of the computer deck
            computerDeck.Pop();

            //If there is a draw
            if (tableDeckUser.GetTop()->data == tableDeckComputer.GetTop()->data)
            {

                //Print that there is a tie and ask if the user wants to continue
                cout << "\nThere is a tie. Each player will have to place down 3 cards face down " <<
                    "and then turn the last card face up or just turn their last card face up." << endl;
                cout << "We will now continue on with the war. " << endl;

                //Call the play war function
                PlayWar(userDeck, computerDeck, userWinners, computerWinners, tableDeckUser, tableDeckComputer);

            }
            //If the user's card is less than the computer's card
            else if (tableDeckUser.GetTop()->data < tableDeckComputer.GetTop()->data)
            {

                //Move the user's card to the computer's winning pile
                computerWinners.Push(tableDeckUser.GetTop()->data.GetRank(),
                    tableDeckUser.GetTop()->data.GetSuit());

                //Move the computer's card to the computer's winning pile
                computerWinners.Push(tableDeckComputer.GetTop()->data.GetRank(),
                    tableDeckComputer.GetTop()->data.GetSuit());

                //Pop the cards off of the table for the user
                tableDeckUser.Pop();

                //Pop the cards off of the table for the computer
                tableDeckComputer.Pop();

                //Print that the computer won that round
                cout << "\nThe computer won that round!" << endl;

                //Print the divider to the screen
                PrintDivider('-', 100);

            }
            //If the user's card is greater than the computer's card
            else if (tableDeckUser.GetTop()->data > tableDeckComputer.GetTop()->data)
            {

                //Move the user's card to the user's winning pile
                userWinners.Push(tableDeckUser.GetTop()->data.GetRank(),
                    tableDeckUser.GetTop()->data.GetSuit());

                //Move the computer's card to the user's winning pile
                userWinners.Push(tableDeckComputer.GetTop()->data.GetRank(),
                    tableDeckComputer.GetTop()->data.GetSuit());

                //Pop the cards off of the table for the user
                tableDeckUser.Pop();

                //Pop the cards off of the table for the computer
                tableDeckComputer.Pop();

                //Print that the user won that round
                cout << "\nThe user won that round!" << endl;

                //Print the divider to the screen
                PrintDivider('-', 100);

            }

            //Call the AreDecksEmpty function
            AreDecksEmpty(userDeck, userWinners, computerDeck, computerWinners);

        }

    }

}

//-------------------------------------------------------------------------------------------------
//PlayWar - function to play war when there is a tie
//-------------------------------------------------------------------------------------------------
void PlayWar(StackClassType& userDeck, StackClassType& computerDeck, StackClassType& userWinners,
    StackClassType& computerWinners, StackClassType& tableDeckUser, StackClassType& tableDeckComputer)
{

    //Create an integer for the count 
    int count = 0;

    //Boolean for if the user has lost
    bool userLost = false;

    //Boolean for if the computer has lost
    bool computerLost = false;

    //While the user deck is not empty
    while (count < 3)
    {

        //If the user deck is empty
        if (userDeck.IsEmpty())
        {

            //If the winner's deck is not empty
            if (!userWinners.IsEmpty())
            {

                //Push a card from the winner pile to the user deck
                userDeck.Push(userWinners.GetTop()->data.GetRank(),
                    userWinners.GetTop()->data.GetSuit());

                //Pop the card off of the winner pile
                userWinners.Pop();

                //Push the top card from the user deck onto the table "face down"
                tableDeckUser.Push(userDeck.GetTop()->data.GetRank(),
                    userDeck.GetTop()->data.GetSuit());

                //Pop the card off of the user's deck
                userDeck.Pop();

                //Increment the count
                count++;

            }
            else if (userWinners.IsEmpty())
            {

                //Call the AreDecksEmpty function
                AreDecksEmpty(userDeck, userWinners, computerDeck, computerWinners);

                //Set the count to 3
                count = 3;

                //Set the user lost boolean to true
                userLost = true;

                //Set the computer lost boolean to true
                computerLost = true;

            }

        }
        else if (!userDeck.IsEmpty())
        {

            //Push the top card from the user deck onto the table "face down"
            tableDeckUser.Push(userDeck.GetTop()->data.GetRank(),
                userDeck.GetTop()->data.GetSuit());

            //Pop the card off of the user's deck
            userDeck.Pop();

            //Increment the count
            count++;

        }

    }

    //If the user lost is true
    if (userLost == false)
    {

        //Print the computer card that will be printed
        cout << "User: ";

        //Print the top card on the table
        tableDeckUser.GetTop()->data.PrintCard(tableDeckUser.GetTop()->data.GetRank(),
            tableDeckUser.GetTop()->data.GetSuit());

        //Move the cursor to the next line
        cout << endl;

    }

    //Set the count to 0
    count = 0;

    //While the computer deck is not empty
    while (count < 3)
    {

        //If the computer deck is empty
        if (computerDeck.IsEmpty())
        {

            //If the winner's deck is not empty
            if (!computerWinners.IsEmpty())
            {

                //Push a card from the winner pile to the computer deck
                computerDeck.Push(computerWinners.GetTop()->data.GetRank(),
                    computerWinners.GetTop()->data.GetSuit());

                //Pop the card off of the winner pile
                computerWinners.Pop();

                //Push the top card from the computer deck onto the table "face down"
                tableDeckComputer.Push(computerDeck.GetTop()->data.GetRank(),
                    computerDeck.GetTop()->data.GetSuit());

                //Pop the card off of the user's deck
                computerDeck.Pop();

                //Increment the count
                count++;

            }
            else if (computerWinners.IsEmpty())
            {

                //Call the AreDecksEmpty function
                AreDecksEmpty(userDeck, userWinners, computerDeck, computerWinners);

                //Set the count to 3
                count = 3;

                //Set the computer lost to true
                computerLost = true;

            }

        }
        else if (!computerDeck.IsEmpty())
        {

            //Push the top card from the computer deck onto the table "face down"
            tableDeckComputer.Push(computerDeck.GetTop()->data.GetRank(),
                computerDeck.GetTop()->data.GetSuit());

            //Pop the card off of the user's deck
            computerDeck.Pop();

            //Increment the count
            count++;

        }

    }

    //If the computer lost is true
    if (computerLost == false)
    {

        //Print the computer card that will be printed
        cout << "Computer: ";

        //Print the top card on the table
        tableDeckComputer.GetTop()->data.PrintCard(tableDeckComputer.GetTop()->data.GetRank(),
            tableDeckComputer.GetTop()->data.GetSuit());

        //Move the cursor to the next line
        cout << endl;

    }

    //If the card's are equal again
    if (tableDeckUser.GetTop()->data == tableDeckComputer.GetTop()->data)
    {

        //Output that there was another tie
        cout << "\nThere was another tie which means there will be another round." << endl;

        cout << "Each player will lay down another 3 cards or use their last" << endl;

        //Print the divider to the screen
        PrintDivider('-', 100);

        //Call the function again to play war
        PlayWar(userDeck, computerDeck, userWinners, computerWinners, tableDeckUser, tableDeckComputer);

    }
    //If the user's card is less than the computer's
    else if (tableDeckUser.GetTop()->data < tableDeckComputer.GetTop()->data)
    {

        //Push all 4 of each player's cards to the computer's winning pile
        while (!tableDeckUser.IsEmpty() || !tableDeckComputer.IsEmpty())
        {

            //Push the user's card
            computerWinners.Push(tableDeckUser.GetTop()->data.GetRank(),
                tableDeckUser.GetTop()->data.GetSuit());

            //Push the computer's card
            computerWinners.Push(tableDeckComputer.GetTop()->data.GetRank(),
                tableDeckComputer.GetTop()->data.GetSuit());

            //Pop the cards off of the table for the user
            tableDeckUser.Pop();

            //Pop the cards off of the table for the computer
            tableDeckComputer.Pop();

        }

        //Output that the computer won that round of war
        cout << "\nThe computer's card was greater which means they won that round." << endl;

        //Print the divider to the screen
        PrintDivider('-', 100);

    }
    //If the user's card is greater than the computer's
    else if (tableDeckUser.GetTop()->data > tableDeckComputer.GetTop()->data)
    {

        //Push all 4 of each player's cards to the user's winning pile
        while (!tableDeckUser.IsEmpty() || !tableDeckComputer.IsEmpty())
        {

            //Push the user's card
            userWinners.Push(tableDeckUser.GetTop()->data.GetRank(),
                tableDeckUser.GetTop()->data.GetSuit());

            //Push the computer's card
            userWinners.Push(tableDeckComputer.GetTop()->data.GetRank(),
                tableDeckComputer.GetTop()->data.GetSuit());

            //Pop the cards off of the table for the user
            tableDeckUser.Pop();

            //Pop the cards off of the table for the computer
            tableDeckComputer.Pop();

        }

        //Output that the user one that round
        cout << "\nThe user's card was greater which means they won that round." << endl;

        //Print the divider to the screen
        PrintDivider('-', 100);

    }

}

//-------------------------------------------------------------------------------------------------
//AreDecksEmpty - function to determine what to do when the decks are empty
//-------------------------------------------------------------------------------------------------
void AreDecksEmpty(StackClassType& userDeck, StackClassType& userWinners, 
    StackClassType& computerDeck, StackClassType& computerWinners)
{

    //If the user has no cards left in their main deck
    if (userDeck.IsEmpty())
    {

        //If the user still has cards left in the winning pile
        if (!userWinners.IsEmpty())
        {

            //Push all of the cards from the winning pile back
            while (!userWinners.IsEmpty())
            {

                //Push the card
                userDeck.Push(userWinners.GetTop()->data.GetRank(),
                    userWinners.GetTop()->data.GetSuit());

                //Pop the cards off of the winning pile for the user
                userWinners.Pop();

            }

            //Output that the cards were pushed
            cout << "The cards from the users winning pile have been pushed" <<
                " into the user's main deck." << endl;

        }
        else if (userWinners.IsEmpty())
        {

            //Print the user is a loser and the computer has won
            cout << "The user has no more cards left meaning the computer has " <<
                "won the game. Thank you very much for playing!" << endl;

            //Print the divider to the screen
            PrintDivider('-', 100);

        }

    }

    //If the computer's deck is empty
    if (computerDeck.IsEmpty())
    {

        //If the computer still has cards left in the winning pile
        if (!computerWinners.IsEmpty())
        {

            //Push all of the cards from the winning pile back
            while (!computerWinners.IsEmpty())
            {

                //Push the card
                computerDeck.Push(computerWinners.GetTop()->data.GetRank(),
                    computerWinners.GetTop()->data.GetSuit());

                //Pop the cards off of the winning pile for the computer
                computerWinners.Pop();

            }

            //Output that the cards were pushed
            cout << "The cards from the computer's winning pile have been " <<
                "pushed into the computer's main deck." << endl;

        }
        else if (computerWinners.IsEmpty())
        {

            //Print the computer is a loser and the user has won
            cout << "\nThe computer has no more cards left meaning the user has " <<
                "won the game. Thank you very much for playing!" << endl;

            //Print the divider to the screen
            PrintDivider('-', 100);

        }

    }

}