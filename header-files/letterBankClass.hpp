#ifndef WORDBANK_TYPE
#define WORDBANK_TYPE

//Native Header Files
#include <iostream>
#include <string>
#include <array>

//Custom Header
#include "letterClass.hpp"

using namespace std;

//************************* LetterBank Declaration ****************************\\

class LetterBank
{
    private:
        //Data members
        array<Letter, 26> letters;    //Array of Letter objects

    public:
        //Methods
        LetterBank();
        bool isGuessed(const char);
        void setGuessed(const char);
        void print() const;
        
        //Overloaded Operators
        friend ostream& operator<<(ostream&, const LetterBank&);
};


//************************* LetterBank Implementation ****************************\\

//Default Constructor
LetterBank::LetterBank()
{
    //All uppercase letters
    const string uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    
    //For every character in the string above, create a 'Letter' object from it for the array 'letters'
    for(int pos=0; pos < uppercaseLetters.length(); pos++)  
    {
        //Load each position in the letter bank with a 'Letter' object from the alphabet
        letters[pos] = Letter( uppercaseLetters[pos] );  
    }
}

//setGuessed() -- simple sequential search, suitable for short items
void LetterBank::setGuessed(const char guess)
{
    //For every letter in the letter bank
    for(int pos=0; pos < letters.size(); pos++)
    {
        //If the current letter matches the given letter, set it to guessed
        if(letters[pos].isEqual(guess))
        {
            letters[pos].setGuessed(true);
            break;
        }
    }
}

//isGuessed
bool LetterBank::isGuessed(const char guess) 
{
    //For every letter in the letter bank
    for(int pos=0; pos < letters.size(); pos++)
    {
        //If the current letter matches the given letter, return whether it has been guessed
        if (letters[pos].isEqual(guess))
            return letters[pos].isGuessed();
    } 

    return NULL;   //for errors
}

//print()
void LetterBank::print() const
{
    //Header
    cout << "\nLetter Bank:\n";

    //Output each letter linearly, end=" "
    for(int pos=0; pos < letters.size(); pos++)
    {
        letters[pos].print();
    }
}

//Overloaded << operator
ostream& operator<<(ostream& osObj, const LetterBank& letterBankObj)
{
    //Print the letter bank
    letterBankObj.print();
    return osObj;   //empty ostream object
}

#endif
