void Base::reset_game()
{
    string ask_again = "default";
    bool can_exit = false;
    bool play_aagain = false;
    int k = 0;
    char numss[] = "789456123";

    while (1)
    {
        try
        {
            cout << "\n\n\tDo you want to have another chance to play (y/n) ?  ";
            cin >> ask_again;

            if (ask_again == "yes" || ask_again == "y")
            {
                can_exit = true;
                play_aagain = true;
            }
            else if (ask_again == "no" || ask_again == "n")
            {
                can_exit = true;
            }
            else
            {
                throw "eror";
            }
        }
        catch (...)
        {
            cout << "invalid entry !!!";
        }

        if (can_exit == true)
        {
            break;
        }
    }
    // if yes reset list and array and call start_game() to start the game

    if (play_aagain)
    {
        printf("\033[33m");
        system("clear");
        able_to_exit = false;
        isFinished = false;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                p[i][j] = '_';

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                num_p[i][j] = numss[k];
                k += 1;
            }

        start_game();
    }
}