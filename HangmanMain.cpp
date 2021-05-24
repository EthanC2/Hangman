/*
Name: Ethan Cox
Date: 5/21/2021
Platform: Bash (a Linux Terminal)
Language: C++, no external libraries
External Dependencies: None
Project Link: https://github.com/EthanC2/Hangman

Project Description: At the end of my first programming class, we were tasked with building Hangman as our final project. Even with the limited
                     knowledge that we had, we were all still able to make the game work using a procedural approach. Since I recently finished my
                     second programming course (CSC-1720), I decided to remake the project on my own to see how far I'd come. Naturally, I decided
                     to add a bit of my own personal touches such as the output coloring and overall restructuring of the project.

This file (HangmanMain.cpp): This file serves as the driver code for the program as it both chooses the random word and starts the game. 
*/
#include "./header-files/Game.hpp"                   //Includes the game, and all of its dependents
#include "./header-files/randomWordGenerator.hpp"   //Includes the random word generator
using namespace std;

//Driver code
int main()
{
    //Seed random number generator
    srand(time(NULL));

    //Get a random word 
    randomWordGenerator wordGenerator;
    string randomWord = wordGenerator.getRandomWord();

    //Declares the game, starting it
    Game game(randomWord);

    return 0;
}
