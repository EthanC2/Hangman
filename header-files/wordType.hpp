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
        Word();

};

//*************************** WORD CLASS IMPLEMENTATION  ******************************\\

//Default Constructor
Word::Word()
{
     //The default constructor should never be used, so
    //the default word is '?', to indicate an error.
      word = "?";
    shadow = "_";
}


