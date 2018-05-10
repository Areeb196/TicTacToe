#include "tictactoe.h"

int main()
{
  char board[3][3];
  char playAgain;
  int rowChoice;
  int colChoice;
  int playerNum;
  char marker;
  int gameNum = 1;

  do
  {
    clearBoard(board);

    if (gameNum % 2 == 0)
      marker = 'X';
    else
      marker = 'O';

    do
    {
      cout << "1 Player or 2 Player (enter 1 or 2): ";
      cin >> playerNum;
      if (playerNum != 1 && playerNum != 2)
        cout << "Enter 1 or 2!" << endl;
    } while (playerNum != 1 && playerNum != 2);

    showBoard(board);
    cout << endl;

    while (!gameOver(board) && !draw(board))
    {
      if (playerNum == 2)
      {
        cout << "Player " << marker << "\'s turn:" << endl;
        makeMove(board, rowChoice, colChoice);
        board[rowChoice][colChoice] = marker;
        showBoard(board);
        switchMark(marker);
        cout << endl;
      }
      else if (playerNum == 1)
      {
        if (marker == 'O')
        {
          cout << "Computer's turn" << endl;
          computer(board, marker);
        }
        else
        {
          cout << "Player's turn" << endl;
          makeMove(board, rowChoice, colChoice);
          board[rowChoice][colChoice] = marker;
        }
        showBoard(board);
        switchMark(marker);
        cout << endl;
      }
    }

    if (!draw(board))
    {
      switchMark(marker);
      if (playerNum == 2)
        cout << "Player " << marker << " wins!" << endl;
      else if (playerNum == 1)
      {
        if (marker == 'O')
          cout << "Computer Wins!" << endl;
        else
          cout << "Player Wins!" << endl;
      }
    }
    else
      cout << "Draw!" << endl;
    cout << "Play Again? (y/n): ";
    cin >> playAgain;
    gameNum++;
  } while (playAgain == 'y');

  return 0;
}