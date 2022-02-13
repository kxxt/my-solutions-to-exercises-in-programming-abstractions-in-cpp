#include "console.h"
#include "grid.h"
#include <bitset>
#include <iostream>
using namespace std;

bool checkSudokuSolution(Grid<int> const &puzzle);

int main() {
  Grid<int> puzzle{{3, 9, 2, 4, 6, 5, 8, 1, 7}, {7, 4, 1, 8, 9, 3, 6, 2, 5},
                   {6, 8, 5, 2, 7, 1, 4, 3, 9}, {2, 5, 4, 1, 3, 8, 7, 9, 6},
                   {8, 3, 9, 6, 2, 7, 1, 5, 4}, {1, 7, 6, 9, 5, 4, 2, 8, 3},
                   {9, 6, 7, 5, 8, 2, 3, 4, 1}, {4, 2, 3, 7, 1, 9, 5, 6, 8},
                   {5, 1, 8, 3, 4, 6, 9, 7, 2}};
  cout << checkSudokuSolution(puzzle) << endl;

  Grid<int> puzzle1{{3, 9, 2, 4, 6, 3, 8, 1, 7}, {7, 4, 1, 8, 9, 3, 6, 2, 5},
                    {6, 8, 5, 2, 7, 1, 4, 3, 9}, {2, 5, 4, 1, 3, 8, 7, 9, 6},
                    {8, 3, 9, 6, 2, 7, 1, 5, 4}, {1, 7, 6, 9, 5, 4, 2, 8, 3},
                    {9, 6, 7, 5, 8, 2, 3, 4, 1}, {4, 2, 3, 7, 1, 9, 5, 6, 8},
                    {5, 1, 8, 3, 4, 6, 9, 7, 2}};
  cout << checkSudokuSolution(puzzle1) << endl;
  return 0;
}

bool checkSudokuSolution(Grid<int> const &puzzle) {
  if (puzzle.width() != 9 || puzzle.height() != 9)
    error("Not a sudoku.");
  bitset<10> row, col;
  for (int i = 0; i < 9; i++) {
    row.reset();
    col.reset();
    for (int j = 0; j < 9; j++) {
      // Test rows
      if (row.test(puzzle[i][j]))
        return false;
      else
        row.set(puzzle[i][j]);
      // Test cols
      if (col.test(puzzle[j][i]))
        return false;
      else
        col.set(puzzle[j][i]);
    }
  }
  bitset<10> another;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      another.reset();
      int r = 3 * i;
      int c = 3 * j;
      for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++) {
          if (another.test(puzzle[r + x][c + y]))
            return false;
          else
            another.set(puzzle[r + x][c + y]);
        }
    }
  return true;
}
