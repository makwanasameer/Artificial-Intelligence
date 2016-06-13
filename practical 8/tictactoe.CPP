#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max random(3)+1
char matrix[3][3];

void board(void);
int minimax();

int main()
{
clrscr();
int m,n;
char ch='Y';
char x='X';
char o='O';
char again;
while(ch=='Y'||ch=='y')
{
	for (m=0;m<3;m++)
	{
		for (n=0;n<3;n++)
		{
		matrix[m][n]= '\0';
		}
	}
int i,j,sum=0;
while ( sum < 10)
{
if (sum == 0) board();
printf("Player 1 is 'X': choose the row and column");
printf("\nRow : ");
scanf("%d",&i);
printf("Column : ");
scanf("%d",&j);
for (; i>3 || i<1 || j>3 || j<1 ||('X'==matrix[i-1][j-1]||'O'==matrix[i-1][j-1]);)
{
    printf("Sorry, but you should choose another place.\n");
    printf("row : ");
    scanf("%d",&i);
    printf("column : ");
    scanf("%d",&j);

}
matrix[i-1][j-1]='X';
sum++;
board();

//check if wins
if (matrix[0][0]=='X' && matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2]) {printf("Player 1 wins");break;}
if (matrix[2][0]=='X' && matrix[2][0]==matrix[1][1] && matrix[1][1]==matrix[0][2]) {printf("Player 1 wins");break;}
if (matrix[0][0]=='X' && matrix[0][0]==matrix[1][0] && matrix[1][0]==matrix[2][0]) {printf("Player 1 wins");break;}
if (matrix[0][1]=='X' && matrix[0][1]==matrix[1][1] && matrix[1][1]==matrix[2][1]) {printf("Player 1 wins");break;}
if (matrix[0][2]=='X' && matrix[0][2]==matrix[1][2] && matrix[1][2]==matrix[2][2]) {printf("Player 1 wins");break;}
if (matrix[0][0]=='X' && matrix[0][0]==matrix[0][1] && matrix[0][1]==matrix[0][2]) {printf("Player 1 wins");break;}
if (matrix[1][0]=='X' && matrix[1][0]==matrix[1][1] && matrix[1][1]==matrix[1][2]) {printf("Player 1 wins");break;}
if (matrix[2][0]=='X' && matrix[2][0]==matrix[2][1] && matrix[2][1]==matrix[2][2]) {printf("Player 1 wins");break;}

if (sum == 9){printf("The game is over and no one wins"); break;} //sum=9 because there are only 9 boxes in the game
//player 2's turn

printf("Player 2 is 'O': choosing the row and column\n");
i=minimax();
j=minimax();

for (;i>3 || i<1 || j>3 || j<1 || ('X'==matrix[i-1][j-1]||'O'==matrix[i-1][j-1]);)
{
//again for invalid entry.
i=minimax();
j=minimax();
}
matrix[i-1][j-1]=o;
sum++;
//the play box
board();
//check if wins
if (matrix[0][0]=='O' && matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2]) {printf("Player 2 wins");break;}
if (matrix[2][0]=='O' && matrix[2][0]==matrix[1][1] && matrix[1][1]==matrix[0][2]) {printf("Player 2 wins");break;}
if (matrix[0][0]=='O' && matrix[0][0]==matrix[1][0] && matrix[1][0]==matrix[2][0]) {printf("Player 2 wins");break;}
if (matrix[0][1]=='O' && matrix[0][1]==matrix[1][1] && matrix[1][1]==matrix[2][1]) {printf("Player 2 wins");break;}
if (matrix[0][2]=='O' && matrix[0][2]==matrix[1][2] && matrix[1][2]==matrix[2][2]) {printf("Player 2 wins");break;}
if (matrix[0][0]=='O' && matrix[0][0]==matrix[0][1] && matrix[0][1]==matrix[0][2]) {printf("Player 2 wins");break;}
if (matrix[1][0]=='O' && matrix[1][0]==matrix[1][1] && matrix[1][1]==matrix[1][2]) {printf("Player 2 wins");break;}
if (matrix[2][0]=='O' && matrix[2][0]==matrix[2][1] && matrix[2][1]==matrix[2][2]) {printf("Player 2 wins");break;}

}
printf("\nWould you like to play again??? (Y - N)\n");
fflush(stdin);
scanf("%c",&ch);
printf("\n");
}
      getch();
}
void board(void)
{
//the play box
printf("\n\t\t                1   2   3\n");
printf("\t\t             1  %c | %c | %c\n", matrix[0][0],matrix[0][1],matrix[0][2]);
printf("\t\t               ---|---|---\n");
printf("\t\t             2  %c | %c | %c\n", matrix[1][0],matrix[1][1],matrix[1][2]);
printf("\t\t               ---|---|---\n");
printf("\t\t             3  %c | %c | %c\n", matrix[2][0],matrix[2][1],matrix[2][2]);
}

int minimax()
{
    int i, res, j;
    int player=0;
    int posmax,posmin;
    int board[10];

    for (i = 0; i < 3; i++)
    {
	for( j = 0; j < 3; j++)
	{
	   if(player == 1)
	    {
		matrix[i][j] = 'O';
		res = minimax();

		matrix[i][j] = 'X';
		if(res < j)
		{
		    j = res;
		    if (res == 0)
			posmin = i;
		}
	    }
	    else
	    {
		board[i] = 'X';
		return max;
		board[i] = '_';
		if (res > j)
		{
		    j = res;
		}
	    }
	}
  }
}

