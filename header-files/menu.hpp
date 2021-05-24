/*

This file: This file contains the Menu class, which contains the title and main menu of the game

*/

#ifndef MENU_TYPE
#define MENU_TYPE

//Native Header Files
#include <iostream>
#include <string>
#include <stdlib.h>

//Custom Header Files
#include "textMods.h"

//Namespace
using namespace std;

//*************************** Menu Declaration ********************************\\

class Menu
{
    private:
        //Empty

    public:
        //Methods
        Menu();
        void showTitle() const;
        void showMainMenu() const;
};

//*************************** Menu Implementation ********************************\\

//Default Constructor
Menu::Menu()
{
    //No data members to initialize 
}

//showMenu
void Menu::showTitle() const
{
   //I know it looks ugly, but that's just the escape codes ruining the alignment
  //Created with ASCII art generator: https://patorjk.com/software/taag/#p=display&f=Big&t=HANGMAN
 
  //Color the output
  cout << LIGHT_BLUE;
  
  cout << "   _    _          _   _  _____ __  __          _   _  " << '\n';
  cout << "  | |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | | " << '\n';
  cout << "  | |__| |  /  \\  |  \\| | |  __| \\  / |  /  \\  |  \\| | " << '\n';
  cout << "  |  __  | / /\\ \\ | . ` | | |_ | |\\/| | / /\\ \\ | . ` | " << '\n';
  cout << "  | |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  | " << '\n';
  cout << "  |_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_| " << "\n\n\n";
}


//showMainMenu()
void Menu::showMainMenu() const
{
    //Clear the screen
    system("clear");

    //Display the title
    this->showTitle();

    //Main Menu
    cout << "\n\nWelcome to Hangman! Please select a mode from the below:\n";   //Implicitly colored light blue because this->showTitle() does not include 'RESET'
    cout <<      "========================================================\n";
    cout << "1. Normal Mode\n";
    cout << "edoM esreveR .2\n";
}

#endif 
