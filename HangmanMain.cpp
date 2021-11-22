/*
Name: Ethan Cox
Date: 5/21/2021
Platform: Bash (a Linux Terminal)
Language: C++, no external libraries
External Dependencies: None
Project Link: https://github.com/EthanC2/hangman

Project Description: At the end of my first programming class, we were tasked with building Hangman as our final project. Even with the limited
                     knowledge that we had, we were all still able to make the game work using a procedural approach. Since I recently finished my
                     second programming course in early 2021 (CSC-1720), I decided to remake the project on my own to see how far I'd come. Naturally, I decided
                     to add a bit of my own personal touches such as the output coloring and overall restructuring of the project.

This file (HangmanMain.cpp): This file serves as the driver code for the program as it both chooses the random word and starts the game. 
*/

//Custom Header Files
#include "./header-files/GameClass.hpp"                   //Includes the game, and all of its dependents
#include "./header-files/randomWordGeneratorClass.hpp"   //Includes the random word generator

//Namespace
using namespace std;

//Function Prototypes
template <typename Type>
void reverse(Type& iterObj);


//DRIVER CODE
int main()
{
    //Seed random number generator
    srand(time(NULL));

    //Variables
    int response;                                                    //For making choices at the menu
    Menu mainMenu;                                                  //To display choices
    randomWordGenerator wordGenerator("hangmanWordlist.txt");      //Instantiate a random word generator (using the source file "hangmanWordlist.txt")
    string randomWord = wordGenerator.getRandomWord();            //Get a random word

    //Prompt user for normal mode or hard mode (normal or reverse mode)
    mainMenu.showMainMenu();
    
    //Input loop
    do
    {
        //Get choice
        cout << "\nResponse: ";
        cin.get(response);
    
        //Prevent registering the enter key
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 
    while(response != 1 && response != 2);


    //Declares the game, starting it -- { } needed to prevent jump to case label error
    switch (response)
    {
        case 1:
            {
                Game normalGame(randomWord);
                break;
            }
        case 2:
            {
                reverse(randomWord);
                Game reverseGame(randomWord);
                break;
            }
        default:
            clog << "Fatal Error: improper value from regularted input." << endl;  //Clog for non-fatal errors
            exit(1);
    }

    return 0;
}

//Reverse()
template <typename Type>
void reverse(Type& iterObj)  //any iterable rvalue
{
    size_t size = iterObj.size();   //reduces code clutter 

    for(int i=0; i < (size / 2); i++)
    {
        swap(iterObj[i], iterObj[size-1-i]);
    }
}

