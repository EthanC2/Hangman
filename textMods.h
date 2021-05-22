//Terminal text modifiers for Linux

  //Source:
 //This ungodly long and detailed post by Shakiba Moshiri: https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux
//Shakiba Moshiri's StackOverflow: https://stackoverflow.com/users/4643584/shakiba-moshiri

#ifndef TEXT_MODIFIERS
#define TEXT_MODIFIERS

#include <string>
using namespace std;

//Basic text colors
#define BLACK "\u001b[30m"
#define RED "\u001b[31m"
#define GREEN "\u001b[32m"
#define YELLOW "\u001b[33m"
#define BLUE "\u001b[34m"
#define MAGENTA "\u001b[35m"
#define CYAN "\u001b[36m"
#define WHITE "\u001b[37m" 
#define RESET "\u001b[0m"

//Additional text colors
#define LIGHT_BLACK "\u001b[30;1m"
#define LIGHT_RED "\u001b[31;1m"
#define LIGHT_GREEN "\u001b[32;1m"
#define LIGHT_YELLOW "\u001b[33;1m"
#define LIGHT_BLUE "\u001b[34;1m"
#define LIGHT_MAGENTA "\u001b[35;1m"
#define LIGHT_CYAN "\u001b[36;1m"
#define LIGHT_WHITE "\u001b[37;1m"


//Basic background colors
#define BG_BLACK "\u001b[40m"
#define BG_RED "\u001b[41m"
#define BG_GREEN "\u001b[42m"
#define BG_YELLOW "\u001b[43m"
#define BG_BLUE "\u001b[44m" 
#define BG_MAGENTA "\u001b[45m"
#define BG_CYAN "\u001b[46m"
#define BG_WHITE "\u001b[47m"

//Additional background colors
#define BG_LIGHT_BLACK "\u001b[40;1m"
#define BG_LIGHT_RED "\u001b[41;1m"
#define BG_LIGHT_GREEN "\u001b[42;1m"
#define BG_LIGHT_YELLOW "\u001b[43;1m"
#define BG_LIGHT_BLUE "\u001b[44;1m"
#define BG_LIGHT_MAGENTA "\u001b[45;1m"
#define BG_LIGHT_CYAN "\u001b[46;1m"
#define BG_LIGHT_WHITE "\u001b[47;1m"


//Emphasizers
#define BOLD "\u001b[1m"
#define UNDERLINE "\u001b[4m "
#define REVERSE "\u001b[7m"

//Cursor Modifiers (usually used for loading bars, etc)
#define UP "\u001b[{n}A"
#define DOWN "\u001b[{n}B"
#define RIGHT "\u001b[{n}C"
#define LEFT "\u001b[{n}D"

//Extra -- moves cursor 1000 characters to the left (used to keep the cursor on the left-most part of the screen)
#define PROGRESS_BAR "\u001b[1000D"

#endif
