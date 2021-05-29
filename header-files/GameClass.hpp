#ifndef GAME_LOOP
#define GAME_LOOP

//Native header files
#include <iostream>        //I/O stream operations
#include <string>         //String class
#include <limits>        //Contains numeric_limits::max()
#include <cctype>       //Contains function toupper()
#include <unistd.h>    //Miscellaneous Functions for the Linux Terminal in C++ (includes sleep())

//Custom Header Files
#include "menuClass.hpp"                //The main menu
#include "wordClass.hpp"           //The unknown word to be guessed
#include "letterBankClass.hpp"    //The letters that have been/can be guessed
#include "gallowClass.hpp"       //The ASCII art of the gallow
#include "textMods.h"          //Contains text coloring

//Namespace
using namespace std;     //Small project, so using namespace std is acceptable

//****************************** Game Declaration *******************************\\

//Class: Game (contains the contents of the game, including the game loop)
class Game
{
    private:
        //Abstract Aspects
        bool playGame;
        char guess;

        //Parts of the game
        Menu menu;
        Word word;
        Gallow gallow;
        LetterBank letterBank;

    public:
        //Parts of a game loop
        Game(string);
        void run();
        void stop();

        //Game Core
        void displayGame();       //Show the 'board'/game, whatever
        void getGuess();         //Get a guess (a single character) from the player
        void evalGuess();       //Check whether that guess was right or wrong, and take the appropriate action
        void updateGame();     //Check whether or not to end the game (player has won or lost)

        //End of game
        void endWithLoss();
        void endWithWin();
};

//****************************** Game Implementation *******************************\\

//Parameterized Constructor
Game::Game(string givenWord)
{
    //Game setup
    playGame = true;
    guess = '?';
    word = givenWord;  //overloaded '=' operator sets both target and shadow

    //Start the game
    this->run();
}

//run() (game loop)
void Game::run()
{
    //Game loop
    while(playGame)
    {
        this->displayGame();      //Display the title, gallow, word, and letter bank
        this->getGuess();        //Get a guess from the player
        this->evalGuess();      //Mark the guess as right or wrong
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
    cout << "Word length: " << word.getLength() << endl;
    cout << "Guesses: " << 6 - gallow.getStage() << endl;
    cout << letterBank << endl;
}

//guess()
void Game::getGuess()
{
    //Lambda expression, returns true (invalid) if the character is not a capital letter
    auto invalidChar = [] (char guess) { return static_cast<int>(guess) < 65 || static_cast<int>(guess) > 90; };

    //Input validation loop: continues until a non-guessed, valid character is given
    do
    {
        //Get character from the user
        cout << "\nEnter a character: ";
        cin.get(guess);

        //Prevent registering hitting 'enter' to submit guess as another guess
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //Filter case sensitivity
        guess = toupper(guess);

        //If the letter has been guessed, display an error and loop again
        if (letterBank.isGuessed(guess))
        {
            cerr << "You have already guessed \'"  << guess << "\'. Try again." << endl;      //Using clog for non-critical errors
        }

        //If the letter is not a valid letter, display an error and loop again
        if (invalidChar(guess))
        {
            cerr << "Error: \'" << guess << "\' is not a valid letter" << endl;
        }

    } while (letterBank.isGuessed(guess) || invalidChar(guess));   //Continue prompting the user until a valid character is entered


    //Set the character to guessed 
    letterBank.setGuessed(guess);
}

//evalGuess()
void Game::evalGuess()
{
    if (word.contains(guess))     //If the word contains the guess,
        word.reveal(guess);      //Reveal the appropriate letters
    else
        gallow++;     //Add another body part (overloaded postfix operator)
}

//updateGame
void Game::updateGame()
{
    //If the man is dead (gallow stage 6), end the game (lost)
    if (gallow.isHanged())
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
    cout << '\n' << RED << "You lost!" << RESET << endl;
    cout << LIGHT_BLUE << "The word was: " << GREEN << word.getWord() << RESET << endl;
}

//End game (won)
void Game::endWithWin()
{
    this->stop();
    this->displayGame();
    cout << '\n' << GREEN << "You won!" << RESET << endl;
    cout << LIGHT_BLUE << "The word was: " << GREEN << word.getWord() << RESET << endl;
}

#endif  
