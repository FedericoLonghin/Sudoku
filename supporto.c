bool checkNumber(int _x, int _y, int _n);
void updateFile();
void askCose()
{
    do
    {
        printf("inserisci la X:");
        scanf("%s", tempX);

    } while (tempX[1] != 0 || tempX[0] > 58 || tempX[0] < 49);
    do
    {
        printf("inserisci la Y:");
        scanf(" %s", tempY);

    } while (tempY[1] != 0 || tempY[0] > 58 || tempY[0] < 49);

    do
    {
        printf("inserisci il numero:");
        scanf("%s", tempNum);

    } while (tempNum[1] != 0 || tempNum[0] > 58 || tempNum[0] < 48);
    X = tempX[0] - 48;
    Y = tempY[0] - 48;
    num = tempNum[0] - 48;

    if (checkNumber(X - 1, Y - 1, num))
    {

        table[X - 1][Y - 1] = num;
        if(mode==2)tablemode[X-1][Y-1]=1;
        updateFile();
    }
    
}

bool checkNumber(int _x, int _y, int _n)
{
    if(mode!=2 && tablemode[_x][_y]==1)return 0;
    if (!_n)
        return 1;
    for (int i = 0; i < DIM; i++)
    {
        if (table[_x][i] == _n)
            return 0;
    }

    for (int i = 0; i < DIM; i++)
    {
        if (table[i][_y] == _n)
            return 0;
    }

    for (int i = 0; i < DIM; i++)
    {
        if (table[(i / 3) + (_x / 3) * 3][(i % 3) + (_y / 3) * 3] == _n)
        {

            return 0;
        }
    }

    return 1;
}

bool wehaveAWinner()
{
    for (int i = 0; i < DIM * DIM; i++)
    {
        if (!table[i / 9][i % 9])
            return false;
    }
    return true;
}

char *concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}