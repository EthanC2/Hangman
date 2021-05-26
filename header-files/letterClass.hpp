#ifndef LETTER_TYPE
#define LETTER_TYPE

//Native Header Files
#include <iostream>       //I/O Operations
#include <cctype>        //Contains isalpha()

//Custom Header File
#include "textMods.h"   //Contains text coloring 


//****************************** Letter Declaration **************************\\

//Class: Letter (composes the individual letters in the wordbank)
class Letter
{
    private:
        //Data Members
        char letter;
        bool guessed;

    public:

        //Constructors
        Letter();
        Letter(char);

        //Letter Get/Set Methods
        char getLetter();
        void setLetter(char);
        
        //Gussed Get/Set Methods
        void setGuessed(bool);
        bool isGuessed();
        
        //Miscellaneous Methods
        void print() const;
        bool isEqual(const char);

        //Overloaded operators
        void operator=(const char);
        bool operator==(const char); 
        friend ostream& operator<<(ostream&, const Letter&);        
};


//****************************** Letter Implementation **************************\\

//Default Constructor
Letter::Letter()
{
    //Set default values
    letter = '?';   //reserved letter - indicates an error
    guessed = false;
}

//Parameterized Constructor
Letter::Letter(char character)
{
    //Set default values
    letter  = character;
    guessed = false;
}

//getLetter()
char Letter::getLetter()
{
    return letter;
}

//setLetter()
void Letter::setLetter(char character)
{
    if (isalpha(character))      //If the given character is alphabetic,
        letter = character;     //Then store the letter
}

//setGuessed()
void Letter::setGuessed(bool boolean)  
{
    guessed = boolean;
}

//isGuessed()
bool Letter::isGuessed()
{
    return guessed;
}

//isEqual
bool Letter::isEqual(const char character)
{
    return this->letter == character;
}

//print()
void Letter::print() const
{
     //If the letter has not been guessed, print it as green,
    //otherwise, print it as red (guessed)
    cout << (!guessed ? GREEN : RED) << letter << LIGHT_BLUE << " ";
}

//Overloaded = operator
void Letter::operator=(const char character)
{
    this->setLetter(character);
}

//Overloaded == operator
bool Letter::operator==(const char character)
{
    return this->isEqual(character);
}

//Overloaded << operator
ostream& operator<<(ostream& osObj, const Letter letterTypeObj)
{
    letterTypeObj.print();
    return osObj; //empty ostream object
}

#endif
