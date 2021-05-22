#ifndef GAME_LOOP
#define GAME_LOOP

//Native header files
#include <iostream>      //I/O stream operations
#include <string>       //String class
#include <unistd.h>    //Miscellaneous Functions for the Linux Terminal in C++

//Custom Header Files
#include "menu.hpp"               //The main menu
#include "wordType.hpp"          //The unknown word to be guessed
#include "letterBankType.hpp"   //The letters that have been/can be guessed
#include "gallowType.hpp"      //The ASCII art of the gallow
#include "textMods.h"         //Contains text coloring

//Namespace
using namespace std;     //Small project, so using namespace std is acceptable

//****************************** GAME DECLARATION *******************************\\

//Class: Game (contains the contents of the game, including the game loop)
class Game
{
    private:
        //Abstract Aspects
        bool playGame;
        int guesses;

        //Parts of the game
        Menu menu;
        GallowType gallow;
        LetterBank letterBank;

    public:
        Game();
        void run();
        void stop();
        void displayGame();
        void guess();
        void endWithLoss();
        void endWithWin();
};

//****************************** GAME INITIALIZATION *******************************\\

//Default constructor
Game::Game()
{
    //Set starting values
    playGame = true;
    guesses  = 6;         //6 guesses, one for each major body part (head, torso, arms, legs)

    //Start the game upon instantiation
    this->run();    
}

//run() (game loop)
void Game::run()
{
    //Header
    menu.showMenu();
    gallow.showGallow();

    //Game loop
    while(playGame)
    {
        this->displayGame(); 
        this->stop();
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
    cout << letterBank;
}

//guess()
void Game::guess()
{
    cout << "Guessing!" << endl;
}

//End game (lost)
void Game::endWithLoss()
{
    //Empty
}

//End game (won)
void Game::endWithWin()
{
    //Empty
}

#endif
