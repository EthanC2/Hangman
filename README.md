## Project Summary
This project is a simple, terminal-based Hangman game for Bash, made entirely in C++. It has a list of 58,000 unique words to choose from, many of which are quite obscure. In addition to the fact that you only have 6 guesses, this version of Hangman is meant to be difficult. Moreover, there are two game modes to choose from: normal and reverse. The names are quite telling; 'normal' is just standard Hangman, whereas the word is backwards when playing 'reversed'. <br />

Last update: 5/28/2021

### Compilation
`g++ HangmanMain.cpp`

### Conventions
- The _.hpp_ suffix is used to indicate not only that a header files is for C++, but also that it contains both the class declaration and implementation 
(.h and .cpp files) for said class. If you're curious, the word for this is [portmanteau](https://www.merriam-webster.com/dictionary/portmanteau).
- Camelcase is used for generic files (including class files) and Pascalcase is used for major files (HangmanMain.cpp, GameClass.hpp).

### Credits for Wordlist
The credit for the wordlist used in this project belongs to [Mieliestronk](http://www.mieliestronk.com/wordlist.html); however, I would also like to credit [Tom25](https://github.com/Tom25), since I found the wordlist through his Python Hangman project.

### License
This project is free software, distrubuted under an [MIT license](https://opensource.org/licenses/MIT). <br />

### Contact
If you have any questions about this project, please contact me at ethanrcox[at]gmail{dot}com
