#ifndef WORDBANK_TYPE
#define WORDBANK_TYPE

//Native Header Files
#include <iostream>
#include <string>
#include <array>

//Custom Header
#include "letterType.hpp"

using namespace std;

//************************* LETTERBANK DECLARATION ****************************\\

class LetterBank
{
    private:
        //Data members
        array<LetterType, 26> letters;

    public:
        //Methods
        LetterBank();
        void setGuessed(const char);
        void print() const;
        
        //Overloaded Operators
        friend ostream& operator<<(ostream&, const LetterBank&);
};


//************************* LETTERBANK IMPLEMENTATION ****************************\\

//Default Constructor
LetterBank::LetterBank()
{
    //All uppercase letters
    const string uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    
    //For every character in the string above, create a 'LetterType' object from it for the array 'letters'
    for(int pos=0; pos < uppercaseLetters.length(); pos++)  
    {
        letters[pos] = uppercaseLetters[pos];   //note the overloaded '=' operator
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

//print()
void LetterBank::print() const
{
    //Header
    cout << "Letter Bank:\n";

    for(int pos=0; pos < letters.size(); pos++)
    {
        letters[pos].print();
    }
    cout << '\n';
}

//Overloaded << operator
ostream& operator<<(ostream& osObj, const LetterBank& letterBankObj)
{
    letterBankObj.print();
    return osObj;   //empty ostream object
}

#endif
