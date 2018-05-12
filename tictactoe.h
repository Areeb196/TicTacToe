#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void clearBoard(char board[3][3]);
bool gameOver(const char board[3][3]);
bool draw(const char board[3][3]);
void switchMark(char & mark);
void makeMove(const char board[3][3], int & row, int & col);
void showBoard(const char board[3][3]);
char winner(const char board[3][3]);
char otherMark(char mark);
int minimax(char board[3][3], const char mark, const int turns, const bool max);
void computer(char board[3][3], const char mark);

#endif