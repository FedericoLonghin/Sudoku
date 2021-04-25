void printTable()
{
    printf("\n\n");

    for (int i = 0; i < DIM; i++)
    {
        if (!(i % 3))
        {
            printf("\t\033[37m --------------------\n");
        }

        printf("\t");

        for (int j = 0; j < DIM; j++)
        {
                printf(tablemode[j][i]?"\033[34m":"\033[37m");
            if (!(j % 3))
                printf("\033[37m|");

            if (!table[j][i])
                printf("  ");
            else printf(" %d",table[j][i]);
        }
        printf("\033[37m|\n");
    }
    printf("\t\033[37m --------------------\n\n");
}