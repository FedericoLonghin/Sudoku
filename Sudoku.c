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
int fileReaded[200];
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
    case 0: //initial situation
      if (!openFile())
      {
        createFile();
      }
      printf("Prova di Sudoku di Federico Longhin. Credo che, come tutto, abbandonerò il progetto stasera.\nPremi [ENTER] per iniziare, [N] per creare un nuovo gioco, [P] per pulire il campo da gico, qualsiasi altro per uscire: ");
      scanf("%c", &L);
      if (L == 'P')
      {
        printf("Allora, questo è il punto... non mi funziona sta parte, quindi per ora, se proprio vuoi pulie il campo da gioco, vai /Partite/nuovaPartita.csv e elimina il contenuto del file. teopricamente potresti semplicemente eliminare il file, ma non mi ricordo se funziona o meno... detto questo, grazie per aver letto fino a que, e scusami ancora se questa parte non funziona. anzi, se sai come fixxarla vai su github e fammi una pull request\n");
        return 0;
      }
      else if (L == 'N')
      {
        mode = 2;
      }
      else if (L == 10)
      {
        mode = 1;
      }
      else
      {
        return 0;
      }

      break;
    case 1: //while palying
      system("clear");
      printf("SUPER SUDOKU\nPremi [Ctrl + C] Per uscire");
      printTable();
      askCose();
      if (wehaveAWinner())
        printf("HAI VINTO!!!");
      break;
    case 2: //for creating a new game
      system("clear");
      printf("CREA IL TUO SUDOKU\nPotrai trovare il tuo file condivisibile in /Partite/nuovaPartita.csv Premi [Ctrl + C] Per uscire");
      printTable();
      askCose();
      break;
    }
  }

  return 0;
}
