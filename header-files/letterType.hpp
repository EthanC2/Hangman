#ifndef LETTER_TYPE
#define LETTER_TYPE

//Native Header Files
#include <iostream>       //I/O Operations
#include <cctype>        //Contains isalpha()

//Custom Header File
#include "textMods.h"   //Contains text coloring 


//****************************** LETTERTYPE DECLARATION **************************\\

//Class: LetterType (composes the individual letters in the wordbank)
class LetterType
{
    private:
        //Data Members
        char letter;
        bool guessed;

    public:

        //Constructors
        LetterType();
        LetterType(char);

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
        friend ostream& operator<<(ostream&, const LetterType&);        
};


//****************************** LETTERTYPE IMPLEMENTATION **************************\\

//Default Constructor
LetterType::LetterType()
{
    //Set default values
    letter = '?';   //reserved letter - indicates an error
    guessed = false;
}

//Parameterized Constructor
LetterType::LetterType(char character)
{
    //Set default values
    letter  = character;
    guessed = false;
}

//getLetter()
char LetterType::getLetter()
{
    return letter;
}

//setLetter()
void LetterType::setLetter(char character)
{
    if (isalpha(character))
        letter = character;
}

//setGuessed()
void LetterType::setGuessed(bool boolean)  
{
    guessed = boolean;
}

//isGuessed()
bool LetterType::isGuessed()
{
    return guessed;
}

//isEqual
bool LetterType::isEqual(const char character)
{
    return this->letter == character;
}

//print()
void LetterType::print() const
{
     //If the letter has not been guessed, print it as green,
    //otherwise, print it as red (guessed)
    cout << (!guessed ? GREEN : RED) << letter << LIGHT_BLUE << " ";
}

//Overloaded = operator
void LetterType::operator=(const char character)
{
    this->setLetter(character);
}

//Overloaded == operator
bool LetterType::operator==(const char character)
{
    return this->isEqual(character);
}

//Overloaded << operator
ostream& operator<<(ostream& osObj, const LetterType letterTypeObj)
{
    letterTypeObj.print();
    return osObj; //empty ostream object
}

#endif
