void printTable()
{
    printf("\n\n");

    for (int i = 0; i < DIM; i++)
    {
        if (!(i % 3))
        {
            printf("\t --------------------\n");
        }

        printf("\t");

        for (int j = 0; j < DIM; j++)
        {
            if (!(j % 3))
                printf("|");

            if (!table[j][i])
                printf("  ");
            else printf(" %d",table[j][i]);
        }
        printf("|\n");
    }
    printf("\t --------------------\n\n");
}