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
    //the default word is '?', to indicate an error.
  //    word = "?";
 //   shadow = "_";

    word = "word";
    shadow = "____";
}

//contains()
bool Word::contains(const char character) const
{
    return word.find(character) != string::npos;    //return true if the character appears at least once
}

//reveal()
void Word::reveal(const char character)
{
    //Find the first position of the letter, sets the stage for the while loop
    int pos = word.find(character);     //Guaranteed not to be string::npos, since it's only called after this->contains()

    //Replace all proper underscores with the letter
    while(pos != string::npos)  
    {
        shadow[pos] = character;      //Set the underscore to the proper letter
        pos = word.find(character);   //Get the next index of said letter
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
ostream& operator<<(ostream& osObj, Word& wordObj)
{
    wordObj.print();
    return osObj;   //empty ostream object
}
