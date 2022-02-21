#include "console.h"
#include "grid.h"
#include "simpio.h"
#include <iostream>
using namespace std;

bool canPlaceNQueensHelper(Grid<bool> &board, int r);
bool canPlaceNQueens(Grid<bool> &initBoard);

int main() {
  int n = getInteger("N: ");
  Grid<bool> board(n, n);
  if (canPlaceNQueens(board)) {
    cout << "Solution Found!" << endl;
    for (int r = 0; r < board.height(); r++) {
      for (int c = 0; c < board.width(); c++) {
        cout << (board[r][c] ? '*' : '#');
      }
      cout << endl;
    }
  } else {
    cout << "NO solution!" << endl;
  }
  return 0;
}

bool canPlaceNQueens(Grid<bool> &initBoard) {
  return canPlaceNQueensHelper(initBoard, 0);
}

const int deltas[]{-1, 1};

bool isSafe(Grid<bool> &board, int r, int c) {
  // Check diagnoal
  for (auto dr : deltas)
    for (auto dc : deltas) {
      int nr = r, nc = c;
      while (board.inBounds(nr, nc)) {
        if (board[nr][nc])
          return false;
        nr += dr;
        nc += dc;
      }
    }
  // Check columns
  for (int i = 0; i < board.height(); i++)
    if (board[i][c])
      return false;
  // No need to check rows.
  return true;
}

bool canPlaceNQueensHelper(Grid<bool> &board, int r) {
  if (r == board.height())
    return true;
  for (int i = 0; i < board.width(); i++) {
    if (isSafe(board, r, i)) {
      board[r][i] = true;
      if (canPlaceNQueensHelper(board, r + 1))
        return true;
      board[r][i] = false;
    }
  }
  return false;
}
