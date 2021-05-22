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
        array<LetterType, 26> letters;

    public:
        LetterBank();
        void print() const;

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

//print()
void LetterBank::print() const
{
    //Header
    cout << "Letters Bank:\n";

    for(int pos=0; pos < letters.size(); pos++)
    {
        letters[pos].print();
        //cout << letters[pos];      //simpler, but causes an 'ambiguous overload' error :/
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
