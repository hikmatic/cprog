#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



char board[10] ={'0','1','2','3','4','5','6','7','8','9'};
int moves =0;

void drawBoard()
{
system("cls");    

printf("\t     Tic Tac Toe\n\n");
printf("Player 1 (X) \t- \t Player 2 (O)");
printf("\n\n");

printf("\n\t   |   |   ");
printf("\n\t %c | %c | %c ", board[1], board[2], board[3]);
printf("\n\t___|___|___");
printf("\n\t   |   |   ");
printf("\n\t %c | %c | %c ", board[4], board[5], board[6]);
printf("\n\t___|___|___");
printf("\n\t   |   |   ");
printf("\n\t %c | %c | %c ", board[7], board[8], board[9]);
printf("\n\t   |   |   ");
printf("\n\n");


}

int makeMove(int player, int choice)
{
  char mark;
  if ((board[choice] == 'X') || (board[choice] == 'O'))
      {
        printf("\nSorry that tile1 has already been taken\n");
        moves--;
        return -1;
      }  
  
   else
     {
        if ((player % 2) == 0)
                mark = 'O';
        else mark = 'X';
        //printf("%c",mark);
        board[choice] = mark;
        return 0;
     }

}


int checkWin()
{
    if (board[1]== 'X' && board[2]== 'X' && board[3]== 'X')
            return 1;
    if (board[4] == 'X' && board[5] == 'X' && board[6]== 'X')
            return 1;
    if (board[7]== 'X' && board[8]== 'X' &&board[9]== 'X')
            return 1;
    if (board[1]== 'X' && board[5]== 'X' &&board[9]== 'X')
            return 1;
    if (board[3]== 'X' && board[5]== 'X' && board[7]== 'X')
            return 1;
    if (board[1]== 'X' && board[4]== 'X' && board[7]== 'X')
            return 1;
    if (board[2]== 'X' && board[5]== 'X' && board[8]== 'X')
            return 1;
    if (board[3]== 'X' && board[6]== 'X' && board[9]== 'X')
            return 1;

    if (board[1]== 'O' && board[2]== 'O' && board[3]== 'O')
            return 2;
    else if (board[4]== 'O' && board[5]== 'O' && board[6]== 'O')
            return 2;
    else if (board[7]== 'O' && board[8]== 'O' && board[9]== 'O')
            return 2;
    else if (board[1]== 'O' && board[5]== 'O' && board[9]== 'O')
            return 2;
    else if (board[3]== 'O' && board[5]== 'O' && board[7]== 'O')
            return 2;
    else if (board[1]== 'O' && board[4]== 'O' && board[7]== 'O')
            return 2;
    else if (board[2]== 'O' && board[5]== 'O' && board[8]== 'O')
            return 2;
    else if (board[3]== 'O' && board[6]== 'O' && board[9]== 'O')
            return 2;



  return 0;  
}

int main()
{

int choice, player=1, turn=0, move_result=0,savePos= 0, win = 0;

while(moves < 9)
    {
        turn = player % 2;
        
        if (turn == 0)
         {
            turn = 2;
           
         }
        else 
         {
            turn = 1;
           
         }
        drawBoard();
        if (move_result == -1)
           {
            player--;
            printf("\nSorry that tile0 has already been taken\n");
            moves--;
            turn = player % 2;
        
            if (turn == 0)
                turn = 2;
            else 
                turn = 1;
            


            
           }


        printf("Player %d: Where would you like put your mark?:  ", turn);
        scanf("%d", &choice);
        move_result =  makeMove(player,choice);
        player++;

        win =  checkWin();
        if (win == 1)
        {
            drawBoard();
            printf("\n******** Player 1 Wins *******\n");
            break;
        }
    
        if (win == 2)
        {
            drawBoard();
            printf("\n******   Player 2 Wins ******** \n");
            break;
        }

        moves++;
       
    
    }
    if (moves == 9)
    {
        drawBoard();
        printf("Game Ended in a Draw");
    }









    return 0;
}