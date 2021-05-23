#include <iostream>
#include <string>
using namespace std;

//*************************** WORD CLASS DECLARATION  ******************************\\

class Word
{
    private:
        string word;      //The actual word, in characters
        string shadow;   //The mirror of the word, in underscores

    public:
        //Methods
        Word();
        bool contains(const char);
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
    //the default word is '?', to indicate an error.
  //    word = "?";
 //   shadow = "_";

    word = "word";
    shadow = "____";
}

//contains()
bool Word::contains(const char character)
{
    int pos = word.find(character);
    bool found = (pos != string::npos ? true : false);    //if word.find() found the character, found = true

    while ( word.find(character) != string::npos )   //For every occurance of the character,
    {
        //Set the underscored character to the actual character
        shadow[pos] = word[pos];

        //Get the next position of the character
        pos = word.find(character);
    }

    return found;
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
ostream& operator<<(ostream& osObj, Word& wordObj)
{
    wordObj.print();
    return osObj;   //empty ostream object
}
