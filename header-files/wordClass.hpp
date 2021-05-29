//Native Header Files
#include <iostream>
#include <string>
#include <vector>

//Namespace
using namespace std;

//*************************** Word Class Declaration  ******************************\\

class Word
{
    private:
        string target;      //The unknown word
        string shadow;     //The mirror of the word, in underscores

    public:
        //Methods
        Word();
        Word(string);
        bool contains(const char) const;
        void reveal(const char);
        bool solved() const;
        string getWord() const;    //Returns the target word
        int getLength() const;    //Returns the amount of characters in the word
        void print() const;      //Outputs the hidden word (the underscores)

        //Overloaded Operators
        void operator=(const string);
        friend ostream& operator<<(ostream&, Word&);

};

//*************************** Word Class Implementation  ******************************\\

//Default Constructor
Word::Word()
{
    //These values are overwritten immediately. They exist to initialize the variables at instantiation.
    target = "?";
    shadow = "_";
}

//Parameterized Constructor
Word::Word(string str)
{
    //Set both characters to the given string
    target = str;
    shadow = str;

    //Replace all the characters in 'hidden' with underscores
    for(int index=0; index < shadow.length(); index++)
    {
        shadow[index] = '_';
    }
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

//getLength()
int Word::getLength() const
{
    return target.length();
}

//getWord()
string Word::getWord() const  //Returns the target word
{
    return target;
}

//print
void Word::print() const
{
    cout << "Word: " << shadow << endl; 
}

//Overloaded = operator
void Word::operator=(const string str)
{
    //Set both characters to the given string
    target = str;
    shadow = str;

    //Replace all the characters in 'hidden' with underscores
    for(int index=0; index < shadow.length(); index++)
    {
        shadow[index] = '_';
    }
}


//Overloaded << operator
ostream& operator<<(ostream& osObj, Word& wordObj)
{
    wordObj.print();
    return osObj;   //empty ostream object
}
