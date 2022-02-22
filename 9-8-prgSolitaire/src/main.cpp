#include "board.h"
#include "console.h"
#include <iostream>
using namespace std;

const int START_X = 1, START_Y = 3;
const Direction ALL_DIRECTIONS[]{NORTH, WEST, EAST, SOUTH};

bool solveBoardHelper(Board &board, string &ans);
void solveBoard(Board &board, string &ans);

int main() {
  Board board;
  string ans;
  board.display();
  cout << endl;
  if (!solveBoardHelper(board, ans))
    throw "Fuck!";
  cout << ans << endl;
  board.display();
  return 0;
}

bool solveBoardHelper(Board &board, string &answer) {
  if (board.getPegCount() == 1) {
    // Base case!
    answer = "Finished!";
    return board.get(Board::CENTER);
  }
  for (int i = 0; i < Board::BOARD_SIZE; i++) {
    for (int j = 0; j < Board::BOARD_SIZE; j++) {
      for (auto d : ALL_DIRECTIONS) {
        if (board.canPegJump(i, j, d)) {
          board.jumpPeg(i, j, d);
          if (solveBoardHelper(board, answer)) {
            answer = "Jump " + integerToString(i) + "," + integerToString(j) +
                     " " + directionToString(d) + "\n" + answer;
            return true;
          }
          board.unjumpPeg(i, j, d);
        }
      }
    }
  }
  return false;
}
