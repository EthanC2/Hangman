#ifndef GAME_LOOP
#define GAME_LOOP

//Native header files
#include <iostream>        //I/O stream operations
#include <string>         //String class
#include <limits>        //Contains numeric_limits::max()
#include <cctype>       //Contains function toupper()
#include <unistd.h>    //Miscellaneous Functions for the Linux Terminal in C++ (includes sleep())

//Custom Header Files
#include "menu.hpp"                //The main menu
#include "wordType.hpp"           //The unknown word to be guessed
#include "letterBankType.hpp"    //The letters that have been/can be guessed
#include "gallowType.hpp"       //The ASCII art of the gallow
#include "textMods.h"          //Contains text coloring

//Namespace
using namespace std;     //Small project, so using namespace std is acceptable

//****************************** GAME DECLARATION *******************************\\

//Class: Game (contains the contents of the game, including the game loop)
class Game
{
    private:
        //Abstract Aspects
        bool playGame;
        int  guesses;
        char guess;

        //Parts of the game
        Menu menu;
        Word word;
        Gallow gallow;
        LetterBank letterBank;

    public:
        //Parts of a game loop
        Game();
        void run();
        void stop();

        //Game Core
        void displayGame();
        void getGuess();
        void evalGuess();
        void updateGame();

        //End of game
        void endWithLoss();
        void endWithWin();
};

//****************************** GAME IMPLEMENTATION *******************************\\

//Default constructor
Game::Game()
{
    //Set starting values
    playGame = true;
    guesses  =  6;         //6 guesses, one for each major body part (head, torso, arms, legs)
    guess    = '?';       //Initializes guess to an error value, which will be overwritten at the first turn

    //Start the game upon instantiation
    this->run();    
}

//run() (game loop)
void Game::run()
{
    //Game loop
    while(playGame)
    {
        this->displayGame();     //Display the title, gallow, word, and letter bank
        this->getGuess();       //Get a guess from the player
        this->evalGuess();
        this->updateGame();    //Evaluate the consequences of the guess
    }
}

//stop() (ends the game loop)
void Game::stop()
{
    playGame = false;
}

//displayGame (word progress, wordbank, gallow, etc.)
void Game::displayGame()
{
    //Clear screen
    system("clear");
    cout.flush();

    //Show updated screen
    menu.showTitle();      
    cout << gallow;       
    cout << word;
    cout << "Guesses: " << guesses << endl;
    cout << letterBank << endl;
}

//guess()
void Game::getGuess()
{
    //Get character from the user
    cout << "\nEnter a character: ";
    cin.get(guess);

    //Prevent registering the extra guess from hitting 'enter' to submit guess
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n' );

    //Set the character to guessed 
    letterBank.setGuessed( toupper(guess) );
}

//evalGuess()
void Game::evalGuess()
{
    if (word.contains(guess))     //If the word contains the guess
    {
        word.reveal(guess);    //Reveal the appropriate letters
    }
    else
    {
        guesses--;     //Subtract one guess
        gallow++;     //Add another body part (overloaded postfix operator)
    }
}

//updateGame
void Game::updateGame()
{
    //If no guesses left, end the game (lost)
    if (guesses <= 0)
        this->endWithLoss();
    
    //If the word is solved, end the game (won)
    else if (word.solved())
        this->endWithWin();
}

//End game (lost)
void Game::endWithLoss()
{
    this->stop();
    this->displayGame();
    cout << '\n' << RED << "You lost!" << RESET << '\n' << endl;
}

//End game (won)
void Game::endWithWin()
{
    this->stop();
    this->displayGame();
    cout << '\n' << GREEN << "You won!" << RESET << '\n' << endl;
}

#endif  
