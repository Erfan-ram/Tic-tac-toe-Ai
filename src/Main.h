#ifndef BUILD // include guard
#define BUILD

// #include "Ai_module.h"
#include <iostream>
#include <string>

using namespace std;

struct Players
{
    const char Bot = 'x';
    const char opponent = 'o';
};

// main class contain execute - set turn - check winner and ....
// just create an object and run start_game() -all you need to change is on execute functions
class Base
{
private:
    string med_switch = "easy";

    // save players choices to prevent edit chosen field
    bool isFinished = false;

    // index field valeu for showing match
    char p[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}};

    // index field valeu for showing available choices
    char num_p[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

public:
    // constructor to set name,turn
    Base();

    // show game match and available choices
    void showUi(bool);

    // return symbol of player turn
    char showTurn(const string st);

    // check all possible win positions using for loop for coulm and row
    void checkWinner();

    // get the player choice index
    int getPosition();

    // sumbit symbol to the right position
    void takeAction(Players playerType, int position);

    // ordered functions by importance
    void playerExecution();

    // all bot selections moves is chosen there. choose move considering mode and
    // pick the best move
    void bot_execute();

    // set turn to prenvent wrong move considering last move
    void lead_road(char turn);

    // show the winner and show the match .
    // ask to play again to call reset_game() functions
    void set_winner(char result);

    // to set which moves cause win on available choice array
    void showWin();

    // mode is chosen by user
    // also first player is chosen here
    void start_game();

    // if user wants to play again it will reset game match - available choices
    // and set variables to play again
    void reset_game();
};

#endif /* BUILD */