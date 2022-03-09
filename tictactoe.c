#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void dispBoard(char board[3][3])
{
    int i, j;
    printf("\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
           printf(" %c ", board[i][j]);
           if(j != 2)
            printf("|"); 
        }
        if(i != 2)
            printf("\n-----------\n");
    }
    return;
}

int check(char board[3][3], char ch, int row, int column)
{

    if(board[row][0]==ch && board[row][1]==ch && board[row][2]==ch)
        return 1;

    if(board[0][column]==ch && board[1][column]==ch && board[2][column]==ch)
        return 1;
    
    if(row==column)
    {
        if(board[0][0]==ch && board[1][1]==ch && board[2][2]==ch)
            return 1;
    }
    
    else if((row==2 && column==0)||(row==1 && column==1)||(row==0 && column==2))
    {
        if(board[2][0]==ch && board[1][1]==ch && board[0][2]==ch)
            return 1;
    }

    return 0;

}

void main()
{
    char board[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
           board[i][j]=' '; 
        }       
    }

    int turn = 0, r = 0, c = 0, result = 0;
    printf("\nPlayer 1 - X\nPlayer 2 - O\n");
    while(1)
    {
        dispBoard(board);
        if(turn == 0)
        {
            printf("\nPlayer 1's turn, at which index would you like to enter 'X'[row, column]: ");
            scanf("%d%d", &r, &c);
            if(board[r-1][c-1]!=' ')
            {
                printf("\nSpace already filled!");
                continue;
            }
            else
            {
                board[r-1][c-1]='X';
                result=check(board,'X',r-1, c-1);
                if(result==1)
                {
                    dispBoard(board);
                    printf("\nPlayer 1 wins!\n");
                    break;
                }
            }
            turn = 1;
            
        }
        else if(turn == 1)
        {
            printf("\nPlayer 2's turn, at which index would you like to enter 'O'[row, column]: ");
            scanf("%d %d", &r, &c);
            if(board[r-1][c-1]!=' ')
            {
                printf("\nSpace already filled!");
                continue;
            }
            else
            {
                board[r-1][c-1]='O';
                result=check(board,'O',r-1, c-1);
                if(result==1)
                {
                    dispBoard(board);
                    printf("\nPlayer 2 wins!\n");
                    break;
                }
            }
            turn = 0;
        }
    }
    printf("\nGame Ended!\n");
    system("PAUSE");
}