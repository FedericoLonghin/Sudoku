#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define DIM 9
char L;
int num;
int table[DIM][DIM];
bool tablemode[DIM][DIM];

char tempX[2], tempY[2], tempNum[2];
int fileReaded[1000];
int X, Y, Num;
int mode;
#include "printingThings.c"
#include "supporto.c"
#include "fileThings.c"
int main()
{
  while (1)
  {
    switch (mode)
    {
    case 0://initial situation
      printf(" Prova di Sudoku di Federico Longhin. Credo che, come tutto, abbandonerò il progetto stasera.\nPremi [ENTER] per iniziare, [N] per creare un nuovo gioco, qualsiasi altro per uscire: ");
      if (!openFile())
      {
       createFile();
      }
      scanf("%c", &L);
      if (L == 10)
      {
        mode = 1;
      }
      else if (L == 'N')
      {
       remove("/Partite/nuovaPartita.csv");
        mode = 1;
      }
      else
      {
        return 0;
      }


      break;
    case 1://while palying 

      system("clear");

      printTable();
      askCose();
      if (wehaveAWinner())
        printf("HAI VINTO!!!");
      break;
    }
  }
  return 0;
}
