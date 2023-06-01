#include "include/Main.h"
#include "include/Ai_module.h"

Move bestMove;
win_pos position1;
win_pos position2;
win_pos position3;

Base::Base()
{
    position1.row = position2.row = position3.row = -1;
    position1.col = position2.col = position3.col = -1;
}

void Base::showUi(bool playerTurn = false)
{
    int size = 9;
    char Uib[size];
    char UIchoose[size];

    // assign values to each element using a for loop
    for (int i = 1; i < 10; i++)
    {
        Uib[i - 1] = *translateBoard(p, i);
        UIchoose[i - 1] = *translateBoard(num_p, i);
    }

    // show them via using format string in c++
    cout << endl;
    if (isFinished == true)
    {
        printf("          Final match               Winner moves       \n\n");
    }
    else
        printf("          Game match             Available chioces       \n\n");
    printf("            |     |                   |     |             \n");
    printf("         %c  |  %c  |  %c             %c  |  %c  |  %c       \n", Uib[0], Uib[1], Uib[2], UIchoose[0], UIchoose[1], UIchoose[2]);
    printf("        ____|_____|_____          ____|_____|_____        \n");
    printf("            |     |                   |     |             \n");
    printf("         %c  |  %c  |  %c     ==>     %c  |  %c  |  %c       \n", Uib[3], Uib[4], Uib[5], UIchoose[3], UIchoose[4], UIchoose[5]);
    printf("        ____|_____|_____          ____|_____|_____        \n");
    printf("            |     |                   |     |             \n");
    printf("         %c  |  %c  |  %c             %c  |  %c  |  %c       \n", Uib[6], Uib[7], Uib[8], UIchoose[6], UIchoose[7], UIchoose[8]);
    printf("            |     |                   |     |             \n\n\n");
    if (playerTurn)
    {
        printf("\033[0m");
        printf("     \033[41m You : %c \033[0m      \033[41m Bot :%c ", showTurn("pl"), showTurn("op"));
        printf("\033[0m");
        printf("\033[31m\n");
    }

    if (isFinished)
    {
        printf("\033[0m Final resault: ");
        printf("     \033[33;44m Bot :%i \033[0m    vs    \033[33;44m You :%i ", player_won[0], player_won[1]);
        printf("\033[0m");
    }
}
char Base::showTurn(const string st)
{
    if (st == "pl")
        return symbol.opponent;

    return symbol.Bot;
}

void Base::checkWinner()
{

    for (int i = 0; i < 3; i++)
    {
        // for loop to check 3 rows

        //  _*_|_*_|_*_
        //  ___|___|___
        //     |   |
        if (p[i][0] == p[i][1] && p[i][1] == p[i][2])
        {
            if (p[i][0] != '_')
            {
                // if 3 index are same  (X or O)  isFinished set
                // to true to end execute and set winner
                isFinished = true;
                position1.row = position2.row = position3.row = i;
                position1.col = 0;
                position2.col = 1;
                position3.col = 2;
                set_winner(p[i][0]);
                break;
            }
        }

        // for loop to check 3 coulms

        //  _*_|___|___
        //  _*_|___|___
        //   * |   |
        else if (p[0][i] == p[1][i] && p[1][i] == p[2][i])
        {
            if (p[0][i] != '_')
            {
                isFinished = true;
                position1.col = position2.col = position3.col = i;
                position1.row = 0;
                position2.row = 1;
                position3.row = 2;
                set_winner(p[0][i]);
                break;
            }
        }
    }

    // for loop to check orib

    //  _*_|___|___
    //  ___|_*_|___
    //     |   | *
    if (p[0][0] == p[1][1] && p[1][1] == p[2][2])
    {
        if (p[0][0] != '_')
        {
            isFinished = true;
            position1.row = position1.col = 0;
            position2.row = position2.col = 1;
            position3.row = position3.col = 2;
            set_winner(p[0][0]);
        }
    }

    // for loop to check orib

    //  ___|___|_*_
    //  ___|_*_|___
    //   * |   |
    else if (p[0][2] == p[1][1] && p[1][1] == p[2][0])
    {
        if (p[0][2] != '_')
        {
            isFinished = true;
            position1.row = 0;
            position1.col = 2;
            position2.row = 1;
            position2.col = 1;
            position3.row = 2;
            position3.col = 0;
            set_winner(p[0][2]);
        }
    }
    // if the games end and has no winner this will set winner to N
    else if (isMovesLeft(p) == false)
    {
        isFinished = true;
        set_winner('N');
    }
}

int Base::getPosition()
{
    string ask;
    int pos;

    // check if chosen number is empty and to prevent overwrite
    while (1)
    {
        cout << "Plese enter number where do you want to  :  ";
        cin >> ask;
        try
        {
            pos = stoi(ask); // try to convert string to integer

            if (pos < 1 || pos > 9)
            {
                throw out_of_range("Integer value out of range"); // throw out_of_range exception if num is out of range
            }
            if (isIndexFull(p, pos))
            {
                throw invalid_argument("It was choosen before ");
            }
        }
        catch (const exception &e)
        {
            cout << "invalid input ." << e.what() << endl;
            continue;
        }

        return pos;
    }
}
void Base::takeAction(Players playerType, int position)
{
    // assign chosen number and symbol to right index
    *translateBoard(p, position) = playerType.opponent;
    *translateBoard(num_p, position) = ' ';
}

void Base::playerExecution()
{
    // clear text
    system("clear");
    showUi(true);
    takeAction(symbol, getPosition());

    checkWinner();

    if (isFinished == false)
    {
        lead_road(symbol.Bot);
    }
}

void Base::bot_execute()
{
    system("clear");
    showUi();

    if (mode == "med")
    {
        if (med_switch == "hard")
        {
            mode = "hard";
            bestMove = findBestMove(p);
            p[bestMove.row][bestMove.col] = symbol.Bot;
            num_p[bestMove.row][bestMove.col] = ' ';
            mode = "med";
            med_switch = "easy";
        }
        else
        {
            mode = "easy";
            bestMove = findBestMove(p);
            p[bestMove.row][bestMove.col] = symbol.Bot;
            num_p[bestMove.row][bestMove.col] = ' ';
            mode = "med";
            med_switch = "hard";
        }
    }
    else
    {
        bestMove = findBestMove(p);
        p[bestMove.row][bestMove.col] = symbol.Bot;
        num_p[bestMove.row][bestMove.col] = ' ';
    }
    // check if games end or not
    checkWinner();

    if (isFinished == false)
    {
        lead_road(symbol.opponent);
    }
}

void Base::lead_road(char turn)
{
    if (turn == symbol.Bot)
    {
        bot_execute();
    }
    else
    {
        playerExecution();
    }
}

void Base::set_winner(char result)
{
    printf("\033[33m");

    if (result == symbol.Bot)
    {
        system("clear");
        cout << "\n        you lose !!!\n\n\t\tBot won the match\n\n";
        player_won[0] += 1;
        showWin();
        showUi();
        reset_game();
    }
    else if (result == symbol.opponent)
    {
        system("clear");
        cout << "\n        congratulations !!!\n\n\t\t you won the match\n\n";
        player_won[1] += 1;
        showWin();
        showUi();
        reset_game();
    }
    else if (result == 'N')
    {
        system("clear");
        cout << "\n        Draw !\n\n\t\tGame ends without a winner\n\n";
        showUi();
        reset_game();
    }
}

void Base::showWin()

{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (num_p[i][j] != ' ')
            {
                num_p[i][j] = ' ';
            }
        }
    }
    // set win positions
    num_p[position1.row][position1.col] = '*';
    num_p[position2.row][position2.col] = '*';
    num_p[position3.row][position3.col] = '*';
}

void Base::start_game()
{
    char ask = '_';
    printf("\033[31m");

    cout << "which would start first ?\n\t";
    cout << "enter b for Bot | any character for you to start the game :  ";
    cin >> ask;

    cout << "\n\nok and which mode ?\n\t";
    cout << "enter b for beginner | enter i for intermediate | p for professional :  ";
    cin >> mode;

    if (mode == "b")
    {
        mode = "easy";
    }
    else if (mode == "p")
    {
        mode = "hard";
    }
    else
    {
        mode = "med";
    }

    if (ask == 'b')
    {
        lead_road(symbol.Bot);
    }
    else
    {
        lead_road(symbol.opponent);
    }
}

void Base::reset_game()
{
    string ask_again = "default";
    bool play_aagain = false;
    int k = 1;

    while (1)
    {
        try
        {
            cout << "\n\n\tDo you want to have another chance to play (y/n) ? ";
            cin >> ask_again;

            if (ask_again == "yes" || ask_again == "y")
            {
                play_aagain = true;
            }
            else if (ask_again == "no" || ask_again == "n")
            {
                cout << "Good luck";
                exit(0);
            }
            else
            {
                throw invalid_argument("invalid entry !!!");
            }
        }
        catch (const exception &er)
        {
            cout << er.what();
            continue;
        }

        break;
    }

    // if yes reset list and array and call start_game() to start the game
    if (play_aagain)
    {
        system("clear");
        isFinished = false;

        for (auto &row : p)
        {
            for (auto &elem : row)
            {
                elem = '_';
            }
        }

        for (auto &row_p : num_p)
        {
            for (auto &elem_p : row_p)
            {
                elem_p = static_cast<char>(k + '0');
                k += 1;
            }
        }

        start_game();
    }
}
