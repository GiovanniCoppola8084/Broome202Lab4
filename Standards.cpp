//-------------------------------------------------------------------------------------------------
//File Name: Standard.cpp
//Associated File: Standard.h
//Contains:
// This source file will contain the function definition for the PrintDivider, 
//  PrintCenteredMessage, PrintFileName, and PrintCourseHeading functions.
//
//-------------------------------------------------------------------------------------------------

#include "Standards.h"

//-------------------------------------------------------------------------------------------------
//PrintDivider - Print the divider to the output file
//-------------------------------------------------------------------------------------------------
void PrintDivider(ofstream& fout, char symbol, int width)
{

    //Print the divider to the output file
    fout << setfill(symbol) << setw(width) << symbol << setfill(' ') << endl;

}

//-------------------------------------------------------------------------------------------------
//PrintDivider - Print the divider to the console
//-------------------------------------------------------------------------------------------------
void PrintDivider(char symbol, int width)
{

    //Print the divider to the console
    cout << setfill(symbol) << setw(width) << symbol << setfill(' ') << endl;

}

//-------------------------------------------------------------------------------------------------
//PrintCenteredMessage - Print a message, centered, to the output file
//-------------------------------------------------------------------------------------------------
void PrintCenteredMessage(ofstream& fout, string message, int width)
{

    //Make a variable for the length of the message
    int length;

    //Assign the length of the message to length
    length = static_cast<int>(message.length());

    //Output the message, centered, to the output file
    fout << right << setfill(' ') << setw((width + length) / 2) << message << endl;

}

//-------------------------------------------------------------------------------------------------
//PrintCourseHeading - Print the heading of the course to the output file
//-------------------------------------------------------------------------------------------------
void PrintCourseHeading(ofstream& fout, string college, string program, string name, int width)
{

    //Make a variable for the length of the constants
    int length;

    //Assign length of the college constant
    length = static_cast<int>(college.length());

    //Output the college constant to the middle of the output file
    fout << setfill(' ') << setw((width + length) / 2) << college << endl;

    //Assign length of the name constant
    length = static_cast<int>(name.length());

    //Output the name constant to the middle of the output file
    fout << setw((width + length) / 2) << name << endl;

    //Assign length of the program constant
    length = static_cast<int>(program.length());

    //Output the program constant to the middle of the output file
    fout << setw((width + length) / 2) << program << endl;

}

//-------------------------------------------------------------------------------------------------
//PrintCourseHeading - Print the heading of the course to the console
//-------------------------------------------------------------------------------------------------
void PrintCourseHeading(string college, string program, string name, int width)
{

    //Make a variable for the length of the constants
    int length;

    //Assign length of the college constant
    length = static_cast<int>(college.length());

    //Output the college constant to the middle of the output file
    cout << setfill(' ') << setw((width + length) / 2) << college << endl;

    //Assign length of the name constant
    length = static_cast<int>(name.length());

    //Output the name constant to the middle of the output file
    cout << setw((width + length) / 2) << name << endl;

    //Assign length of the program constant
    length = static_cast<int>(program.length());

    //Output the program constant to the middle of the output file
    cout << setw((width + length) / 2) << program << endl;

}

//-------------------------------------------------------------------------------------------------
//PrintFileName - Print the file name to the screen
//-------------------------------------------------------------------------------------------------
void PrintFileName(string fileName)
{

	//Print the divider
	PrintDivider('-', 100);

	//Print the name of the file to the screen
	cout << fileName << endl;

	//Print the divider
	PrintDivider('-', 100);

}

//-------------------------------------------------------------------------------------------------
//PrintFileName - Print the file name to the output file
//-------------------------------------------------------------------------------------------------
void PrintFileName(ofstream& fout, string fileName)
{

	//Print the divider
	PrintDivider(fout, '-', 100);

	//Print the name of the file to the output file
	fout << fileName << endl;

	//Print the divider
	PrintDivider(fout, '-', 100);

}