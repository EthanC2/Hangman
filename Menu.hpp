#ifndef MENU_TYPE
#define MENU_TYPE

//Native Header Files
#include <iostream>
#include <string>
using namespace std;

//*************************** MENU DECLARATION ********************************\\

class Menu
{
    public:
        Menu();
        void showMenu();
};

//*************************** MENU IMPLEMENTATION ********************************\\

//Default Constructor
Menu::Menu()
{

}

//showMenu
void Menu::showMenu()
{
  cout << "   _    _          _   _  _____ __  __          _   _  " << '\n';
  cout << "  | |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | | " << '\n';
  cout << "  | |__| |  /  \\  |  \\| | |  __| \\  / |  /  \\  |  \\| | " << '\n';
  cout << "  |  __  | / /\\ \\ | . ` | | |_ | |\\/| | / /\\ \\ | . ` | " << '\n';
  cout << "  | |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  | " << '\n';
  cout << "  |_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_| " << "\n\n\n";
}

#endif 
