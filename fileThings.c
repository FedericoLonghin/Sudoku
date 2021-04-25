bool openFile()
{
    int h;
    char car = 'a';
    FILE *fp;

    fp = fopen("Partite/nuovaPartita.csv", "r+");

    if (fp != NULL)
    {
        while (car != EOF)
        {
            car = getc(fp);
            if (car != EOF)
            {
                if (car > 58 || car < 47)
                    return false;
                fileReaded[h] = car - 48;
            }
            h++;
        }

        for (int i = 0; i < DIM * DIM; i++)
        {
            table[i % 9][i / 9] = fileReaded[i];
                        tablemode[i % 9][i / 9] = fileReaded[i+(DIM*DIM)];

        }
    }
    else
    {
            fclose(fp);

        return false;
    }

    fclose(fp);
    return true;
}

void updateFile()
{
    FILE *fp;

    fp = fopen("Partite/nuovaPartita.csv", "w");
    for (int i = 0; i < DIM * DIM; i++)
    {

        fprintf(fp, "%d", table[i % 9][i / 9]);
    }
    for (int i = 0; i < DIM * DIM; i++)
    {

        fprintf(fp, "%d", tablemode[i % 9][i / 9]);
    }
    fclose(fp);
}
void createFile()
{
    FILE *fp;
    fp = fopen("Partite/nuovaPartita.csv", "w");
    fclose(fp);
}