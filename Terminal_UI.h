void Base::show_Ui()
{
    // convert positions to a varble to call them easier
    char a = p[0][0];
    char b = p[0][1];
    char c = p[0][2];
    char d = p[1][0];
    char e = p[1][1];
    char f = p[1][2];
    char g = p[2][0];
    char h = p[2][1];
    char i = p[2][2];

    // convert available choices to a varble to call them easier
    char j = num_p[0][0];
    char k = num_p[0][1];
    char l = num_p[0][2];
    char m = num_p[1][0];
    char n = num_p[1][1];
    char o = num_p[1][2];
    char p = num_p[2][0];
    char q = num_p[2][1];
    char r = num_p[2][2];

    // show them via using format string in c++
    cout << endl;
    if (is_finished == true)
    {
        printf("          Final match               Winner moves       \n\n");
    }
    else
        printf("          Game match             Available chioces       \n\n");
    printf("            |     |                   |     |             \n");
    printf("         %c  |  %c  |  %c             %c  |  %c  |  %c       \n", a, b, c, j, k, l);
    printf("        ____|_____|_____          ____|_____|_____        \n");
    printf("            |     |                   |     |             \n");
    printf("         %c  |  %c  |  %c     ==>     %c  |  %c  |  %c       \n", d, e, f, m, n, o);
    printf("        ____|_____|_____          ____|_____|_____        \n");
    printf("            |     |                   |     |             \n");
    printf("         %c  |  %c  |  %c             %c  |  %c  |  %c       \n", g, h, i, p, q, r);
    printf("            |     |                   |     |             \n\n\n");

    if (is_finished == true)
    {
        printf("\033[0m Final resault: ");
        printf("     \033[33;44m Bot :%i \033[0m    vs    \033[33;44m You :%i ", player_won[0], player_won[1]);
        printf("\033[0m");
        // printf("\033[33m");
    }
}