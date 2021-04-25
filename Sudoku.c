#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define DIM 9
char L = 'S';
int num;
int table[DIM][DIM];
char tempX[2], tempY[2], tempNum[2];
int fileReaded[1000];
int X, Y, Num;
#include "printingThings.c"
#include "supporto.c"
#include "fileThings.c"
int main()
{
  printf("Prova di Sudoku di Federico Longhin. credo che, come tutto, abbandonerò il progetto stasera.\n premi [S] per iniziare, qualsiasi altro per uscire: ");
  if (!openFile()){

    printf("\nerrore durante l'apertura del programma\n");
  return 0;
  }

  //scanf("%c", &L);
  if (L != 'S')
    return 0;

  while (1)
  {
    system("clear");

    printTable();
    askCose();
    if (wehaveAWinner())
      printf("HAI VINTO!!!");
  }
  return 0;
}
