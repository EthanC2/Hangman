#include <iostream>
#include <string>
#include <vector>
using namespace std;

//*************************** WORD CLASS DECLARATION  ******************************\\

class Word
{
    private:
        string target;      //The unknown word
        string shadow;     //The mirror of the word, in underscores

    public:
        //Methods
        Word();
        bool contains(const char) const;
        void reveal(const char);
        bool solved() const;
        void print() const;

        //Overloaded Operators
        friend ostream& operator<<(ostream&, Word&);

};

//*************************** WORD CLASS IMPLEMENTATION  ******************************\\

//Default Constructor
Word::Word()
{
     //The default constructor should never be used, so
    //the default target is '?', to indicate an error.
//    target = "?";
//   shadow = "_";

    target = "target";
    shadow = "______";
}

//contains()
bool Word::contains(const char character) const
{
    return target.find(character) != string::npos;    //return true if the character appears at least once
}

//reveal()
void Word::reveal(const char letter)
{
    //Declare a vector to store all indexes of the guess (letter)
    vector<int> positions;
    
    //Traverse the guess to find all instances of that letter
    for(int index=0; index < target.length(); index++)
    {
        if (target[index] == letter)
            positions.push_back(index);
    }

    //Replace all appropriate underscores with the guessed letter
    for(int i=0; i < positions.size(); i++)
    {
        shadow[ positions[i] ] = letter;
    }
}

//solved()
bool Word::solved() const
{
    return (shadow.find('_') == string::npos);    //game is over when there are no unknown characters
}

//print
void Word::print() const
{
    cout << "Word: " << shadow << endl; 
}

//Overloaded << operator
ostream& operator<<(ostream& osObj, Word& targetObj)
{
    targetObj.print();
    return osObj;   //empty ostream object
}
