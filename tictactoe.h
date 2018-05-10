#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void clearBoard(char board[3][3]);
bool gameOver(char board[3][3]);
bool draw(char board[3][3]);
void switchMark(char & mark);
void makeMove(char board[3][3], int & row, int & col);
void showBoard(char board[3][3]);
char winner(char board[3][3]);
char otherMark(char mark);
int minimax(char board[3][3], char mark, int turns, bool max);
void computer(char board[3][3], char mark);

#endif