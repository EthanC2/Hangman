//Native Header Files
#include <iostream>
#include <string>
#include <fstream>

//Namespace
using namespace std;

//*************************** Random Word Generator Declaration  ****************************\\

class randomWordGenerator
{
    private:
        //Empty

    public:
        //Methods
        randomWordGenerator();
        string getRandomWord() const;   //technically const because there's no membeer variables...? lol
};


//*************************** Random Word Generator Implementation  ****************************\\

//Default Constructor
randomWordGenerator::randomWordGenerator()
{
    //Empty
}


//getRandomWord()
string randomWordGenerator::getRandomWord() const
{
    //Variables
    ifstream inFile;     //A read-only file
    string line;        //A place to store the contents of a line of the file
    int lines = 0;         //The total amount of lines in the file
    int randomLine;   //The random line to draw the word from (to start the game)

    //Open the infile
    inFile.open("hangmanWordlist.txt");

    //Find the total amount of lines in the file
    while(getline(inFile, line))
        lines++;

    //Return to beginning of file
    inFile.clear();     //Clear
    inFile.seekg(0);   //Reset the pointer back to the beginning of the file

    //Calculate a random line
    randomLine = rand() % (lines + 1);

    //Seek the random line
    for(int linenum=0; linenum < randomLine; linenum++)
        getline(inFile, line);

    //Cleanup - close the file
    inFile.close();

    return line;    //Return the random word
}
