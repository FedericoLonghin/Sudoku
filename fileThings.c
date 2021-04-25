bool openFile()
{
    int h;
    char car = 'a';
    FILE *fp;

    fp = fopen("Partite/nuovaPartita.csv", "r");

    if (fp != NULL)
    {
        while (car != EOF)
        {
            car = getc(fp);
            if (car != EOF)
            {
                //  putc(car, stdout);
                  if(car>58||car<47)return false;
                fileReaded[h] =car-48;
            }
            h++;
        }

        for (int i = 0; i < DIM * DIM; i++)
        {            table[i % 9][i / 9] = fileReaded[i];
        }
    }
    else{

        printf("non cato il file");
    return false;
    }

    fclose(fp);
    return true;
}

void updateFile(int _x, int _y, int _num)
{
    FILE *fp;

    fp = fopen("Partite/nuovaPartita.csv", "w");
    for (int i = 0; i < DIM * DIM; i++)
    {

        fprintf(fp,"%d",table[i % 9][i / 9]);
    }
    fclose(fp);
}