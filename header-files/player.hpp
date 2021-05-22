#ifndef PLAYER_TYPE
#define PLAYER_TYPE

//Native Header Files
#include <iostream>            //I/O Operations
#include <cctype>             //Contains toupper()
using namespace std;

//************************** PLAYER DECLARATION *****************************\\

class Player
{
    private:
        char guess;
        int guesses;

    public:
        //Methods
        Player();
        char getGuess();
        int  getGuesses() const;
        void decrementGuess();

        //Overloaded Operators
        void operator--(int);
};

//************************** PLAYER IMPLEMENTATION *****************************\\

//Default Constructor
Player::Player()
{
    guess  = '?';
    guesses = 6;  //one for each major body part (head, torso, arms, legs)
}

//getGuess()
char Player::getGuess()
{
    //Get a single character from the player
    cout << "Enter your guess: ";
    guess = getchar();
    cout << endl;

    //Return the guess in uppercase
    return toupper(guess);
}

//getGuesses()
int Player::getGuesses() const
{
    return guesses;
}

//decrementGuess()
void Player::decrementGuess()
{
    guesses--;
}

void Player::operator--(int placeholder)
{
    this->decrementGuess();
}

#endif
