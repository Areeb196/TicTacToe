#include "tictactoe.h"

bool gameOver(const char board[3][3])
{
  if((board[0][0] == board[0][1] && board[0][1] == board[0][2] && (board[0][0] == 'X' || board[0][0] == 'O')) ||
    (board[1][0] == board[1][1] && board[1][1] == board[1][2] && (board[1][0] == 'X' || board[1][0] == 'O')) ||
    (board[2][0] == board[2][1] && board[2][1] == board[2][2] && (board[2][0] == 'X' || board[2][0] == 'O')) ||
    (board[0][0] == board[1][0] && board[1][0] == board[2][0] && (board[0][0] == 'X' || board[0][0] == 'O')) ||
    (board[0][1] == board[1][1] && board[1][1] == board[2][1] && (board[0][1] == 'X' || board[0][1] == 'O')) ||
    (board[0][2] == board[1][2] && board[1][2] == board[2][2] && (board[0][2] == 'X' || board[0][2] == 'O')) ||
    (board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[0][0] == 'X' || board[0][0] == 'O')) ||
    (board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[0][2] == 'X' || board[0][2] == 'O')))
    return true;
  return false;
}

bool draw(const char board[3][3])
{
  int num = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] != ' ')
        num++;
    }
  }
  if (num == 9 && !gameOver(board))
    return true;
  return false;
}

void switchMark(char & mark)
{
  if (mark == 'O')
    mark = 'X';
  else
    mark = 'O';
  return;
}

void makeMove(const char board[3][3], int & row, int & col)
{
  cout << "Enter a position (rows then cols)" << endl;
  do
  {
    cin >> row;
    cin >> col;
    if (row < 0 || row > 2 || col > 2 || row < 0 || board[row][col] != ' ')
      cout << "Out of Bounds" << endl;
  } while (row < 0 || row > 2 || col > 2 || row < 0 || board[row][col] != ' ');
  return;
}

void showBoard(const char board[3][3])
{
  cout << " | 0 | 1 | 2 |" << endl;
  cout << "--------------" << endl;
  cout << "0| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
  cout << "--------------" << endl;
  cout << "1| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
  cout << "--------------" << endl;
  cout << "2| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
  cout << "--------------" << endl;
  return;
}

void clearBoard(char board[3][3])
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      board[i][j] = ' ';
  return;
}

char winner(const char board[3][3])
{
  char win;
  if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && (board[0][0] == 'X' || board[0][0] == 'O'))
    win = board[0][0];
  else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && (board[1][0] == 'X' || board[1][0] == 'O'))
    win = board[1][0];
  else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && (board[2][0] == 'X' || board[2][0] == 'O'))
    win = board[2][0];
  else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && (board[0][0] == 'X' || board[0][0] == 'O'))
    win = board[0][0];
  else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && (board[0][1] == 'X' || board[0][1] == 'O'))
    win = board[0][1];
  else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && (board[0][2] == 'X' || board[0][2] == 'O'))
    win = board[0][2];
  else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[0][0] == 'X' || board[0][0] == 'O'))
    win = board[0][0];
  else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[0][2] == 'X' || board[0][2] == 'O'))
    win = board[0][2];
  return win;
}

char otherMark(char mark)
{
  if (mark == 'X')
    return 'O';
  return 'X';
}

int minimax(char board[3][3], const char mark, const int turns, const bool max)
{
  int score;
  int temp;

  if (gameOver(board))
  {
    if (winner(board) == mark)
      return 10 - turns;
    else
      return -10 - turns;
  }
  else if (draw(board))
    return 0;

  if (max)
  {
    score = -100;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (board[i][j] == ' ')
        {
          board[i][j] = mark;
          temp = minimax(board, mark, turns + 1, false);
          board[i][j] = ' ';
          if (temp > score)
            score = temp;
        }
      }
    }
  }
  else
  {
    score = 100;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (board[i][j] == ' ')
        {
          board[i][j] = otherMark(mark);
          temp = minimax(board, mark, turns + 1, true);
          board[i][j] = ' ';
          if (temp < score)
            score = temp;
        }
      }
    }
  }
  return score;
}

void computer(char board[3][3], const char mark)
{
  int temp;
  int maxScore = -100;
  int bestRow;
  int bestCol;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == ' ')
      {
        board[i][j] = mark;
        temp = minimax(board, mark, 0, false);
        board[i][j] = ' ';
        if (temp > maxScore)
        {
          maxScore = temp;
          bestRow = i;
          bestCol = j;
        }
      }
    }
  }
  board[bestRow][bestCol] = mark;
  return;
}