#include <stdio.h> 
#include <stdlib.h>
#include <time.h>


// functions

int playagain()
{
    int a;
    printf("\nplay again? yes = 1, no = 0\n");
    scanf("%d", &a);
    return a;
}

int ChooseDifficulty()
{
    int d, limit;
printf("Choose difficulty: easy(4 tries) = 1, normal(2 tries) = 2, hard(1 try) = 3\n");
  scanf ("%d", &d);
  if (d == 1)
  {
   limit = 4;
  }
  else if (d == 2)
  {
    limit = 2;
  }

  else if (d == 3)
  {
    limit = 1;
  }
  return limit;
}

int getcompmove()
{
    int comp;
    comp = rand() % 3 + 1;
    return comp;
}

int PlayerMove()
{
    int player;
    printf ("\nrock = 1, paper = 2, scissor = 3\n");
scanf("%d", &player);
return player;
}


void ShowCompMove(int comp)
{
    if (comp == 1)
        printf("\ncomputer chose rock!\n");
    else if (comp == 2)
        printf("\ncomputer chose paper!\n");
    else if (comp == 3)
        printf("\ncomputer chose scissor!\n");
}



int GetResult(int player, int comp)
{
    if (player == comp)
        return 0;

    if ((player == 1 && comp == 3) ||
        (player == 2 && comp == 1) ||
        (player == 3 && comp == 2))
        return 1;

    return -1;
}

void ShowResult(int result)
{
    if (result == 1)
        printf("You won!\n");
    else if (result == -1)
        printf("You lost!\n");
    else
        printf("It's a draw!\n");
}



//main code


int main ()
{
    srand(time(NULL));

int player, comp, a, tries, limit, result;
a = 1;

while (a == 1)
{
 tries = 0;

  limit = ChooseDifficulty();



  while (tries < limit)
{
    player = PlayerMove();
    comp = getcompmove();

    ShowCompMove(comp);

    result = GetResult(player, comp);
    ShowResult(result);

    tries = tries + 1;
    printf("\nNumber of tries: %d\n", tries);
    
}
     a =  playagain ();
  }
  return 0;
}