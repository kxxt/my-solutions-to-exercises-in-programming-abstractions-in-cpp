#include "console.h"
#include "grid.h"
#include <iomanip>
#include <iostream>

using namespace std;

const int N = 8;
const int N_MOVES = 8;

bool knightTourHelper(Grid<int> &board, int r, int c, int &nVisited);
void knightTour(Grid<int> &board, int r, int c);
void printBoard(Grid<int> &board);

int main() {
  Grid<int> board(8, 8);
  knightTour(board, 0, 0);
  printBoard(board);
  return 0;
}

void printBoard(Grid<int> &board) {
  for (int i = 0; i < board.height(); i++) {
    for (int j = 0; j < board.width(); j++)
      cout << setw(2) << board[i][j] << ' ';
    cout << endl;
  }
}

void knightTour(Grid<int> &board, int r, int c) {
  int nVisited = 0;
  knightTourHelper(board, r, c, nVisited);
}

const int dr[N_MOVES]{-2, -2, -1, -1, 1, 1, 2, 2};
const int dc[N_MOVES]{1, -1, 2, -2, 2, -2, 1, -1};

inline void visit(Grid<int> &board, int r, int c, int &nVisited) {
  board[r][c] = ++nVisited;
}

inline void unvisit(Grid<int> &board, int r, int c, int &nVisited) {
  board[r][c] = 0;
  nVisited--;
}

bool knightTourHelper(Grid<int> &board, int r, int c, int &nVisited) {
  if (nVisited == N * N)
    return true;
  if (!board.inBounds(r, c) || board[r][c] != 0)
    return false;
  visit(board, r, c, nVisited);
  for (int i = 0; i < 8; i++) {
    if (knightTourHelper(board, r + dr[i], c + dc[i], nVisited))
      return true;
  }
  unvisit(board, r, c, nVisited);
  return false;
}
