#ifndef LETTER_TYPE
#define LETTER_TYPE

#include <cctype>        //Contains isalpha()
#include "textMods.h"   //Contains text coloring 


//****************************** LETTERTYPE DECLARATION **************************\\

//Class: letterType (composes the individual letters in the wordbank)
class letterType
{
    private:
        char letter;
        bool guessed;

    public:
        //Constructors
        letterType();
        letterType(char);

        //Letter Get/Set Methods
        char getLetter();
        void setLetter(char);
        
        //Gussed Get/Set Methods
        void setGuessed(bool);
        bool isGuessed();
        
        //Print functions
        void print();
};


//****************************** LETTERTYPE INITIALIZATION **************************\\

//Default Constructor
letterType::letterType()
{
    //Set default values
    letter = '?';   //reserved letters - indicates an error
    guessed = false;
}

//Parameterized Constructor
letterType::letterType(char character)
{
    //Set default values
    letter  = character;
    guessed = false;
}

//getLetter()
char letterType::getLetter()
{
    return letter;
}

//setLetter()
void letterType::setLetter(char character)
{
    if ( isalpha(character) )
        letter = character;
}

//setGuessed()
void letterType::setGuessed(bool boolean)  
{
    guessed = boolean;
}

//isGuessed()
bool letterType::isGuessed()
{
    return guessed;
}

//print()
void letterType::print()
{
     //If the letter has not been guessed, print it as green,
    //otherwise, print it as red
    cout << (!guessed ? GREEN : RED)  << letter;
}

#endif
