#include "./header-files/Game.hpp"                   //Includes the game, and all of its dependents
#include "./header-files/randomWordGenerator.hpp"   //Includes the random word generator
//#include <string>                                //Implicitly included above
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

    //Start the game
    game.run();

    return 0;
}
