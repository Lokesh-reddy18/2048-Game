//KOLLI LOKESH REDDY - 2212043
//  2048 GAME

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cmath>
using namespace std;

class Game2048 {
  private: int board[4][4];

  void initBoard() {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        board[i][j] = 0;
      }
    }

    int i1 = rand() % 4;
    int j1 = rand() % 4;
    int i2, j2;
    do {
      i2 = rand() % 4;
      j2 = rand() % 4;
    } while (i2 == i1 && j2 == j1);

    board[i1][j1] = 2;
    board[i2][j2] = 4;
  }

  void moveUp() {
    int i, j, li, ri;
    for (j = 0; j < 4; j++) {
      li = 0, ri = j;
      for (i = 1; i < 4; i++) {
        if (board[i][j] != 0) {
          if (board[i - 1][j] == 0 || board[i - 1][j] == board[i][j]) {
            if (board[li][ri] == board[i][j]) {
              board[li][ri] *= 2;
              board[i][j] = 0;
            } else {
              if (board[li][ri] == 0) {
                board[li][ri] = board[i][j];
                board[i][j] = 0;
              } else {
                board[++li][ri] = board[i][j];
                board[i][j] = 0;
              }
            }
          } else li++;
        }
      }
    }
  }

  void moveDown() {
    int i, j, li, ri;
    for (j = 0; j < 4; j++) {
      li = 3, ri = j;
      for (i = 2; i >= 0; i--) {
        if (board[i][j] != 0) {
          if (board[i + 1][j] == 0 || board[i + 1][j] == board[i][j]) {
            if (board[li][ri] == board[i][j]) {
              board[li][ri] *= 2;
              board[i][j] = 0;
            } else {
              if (board[li][ri] == 0) {
                board[li][ri] = board[i][j];
                board[i][j] = 0;
              } else {
                board[--li][ri] = board[i][j];
                board[i][j] = 0;
              }
            }
          } else li--;
        }
      }
    }
  }

  void moveLeft() {
    int i, j, li, ri;
    for (i = 0; i < 4; i++) {
      li = i, ri = 0;
      for (j = 1; j < 4; j++) {
        if (board[i][j] != 0) {
          if (board[i][j - 1] == 0 || board[i][j - 1] == board[i][j]) {
            if (board[li][ri] == board[i][j]) {
              board[li][ri] *= 2;
              board[i][j] = 0;
            } else {
              if (board[li][ri] == 0) {
                board[li][ri] = board[i][j];
                board[i][j] = 0;
              } else {
                board[li][++ri] = board[i][j];
                board[i][j] = 0;
              }
            }
          } else ri++;
        }
      }
    }
  }

  void moveRight() {
    int i, j, li, ri;
    for (i = 0; i < 4; i++) {
      li = i, ri = 3;
      for (j = 2; j >= 0; j--) {
        if (board[i][j] != 0) {
          if (board[i][j + 1] == 0 || board[i][j + 1] == board[i][j]) {
            if (board[li][ri] == board[i][j]) {
              board[li][ri] *= 2;
              board[i][j] = 0;
            } else {
              if (board[li][ri] == 0) {
                board[li][ri] = board[i][j];
                board[i][j] = 0;
              } else {
                board[li][--ri] = board[i][j];
                board[i][j] = 0;
              }
            }
          } else ri--;
        }
      }
    }
  }

  void addBlock() {
    int li, ri;
    bool found = false;
    while (!found) {
      li = rand() % 4;
      ri = rand() % 4;
      if (board[li][ri] == 0) {
        board[li][ri] = (rand() % 2 == 0) ? 2 : 4; // Assign 2 or 4 randomly
        found = true;
      }
    }
  }

  void displayBoard() {
    cout << "\n\t\tPress Esc anytime to quit the game";
    cout << "\n\n\n\n";
    int i, j;
    for (i = 0; i < 4; i++) {
      cout << "\t\t\t\t-----------------\n\t\t\t\t";
      for (j = 0; j < 4; j++) {
        if (board[i][j] == 0) cout << "|   ";
        else
          cout << "| " << board[i][j] << " ";
      }
      cout << "|" << endl;
    }
    cout << "\t\t\t\t-----------------\n";
  }

  bool boardsEqual(int tmp[4][4]) {
    int fl = 1, i, j;
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
        if (tmp[i][j] != board[i][j]) {
          fl = 0;
          break;
        }
    return fl;
  }

bool gameOver() {
    bool fl = true, gl = false, won = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 2048) {
                won = true;
            } else if (board[i][j] == 0) {
                fl = false;
            } else if ((i > 0 && board[i][j] == board[i - 1][j]) || (i < 3 && board[i][j] == board[i + 1][j]) ||
                       (j > 0 && board[i][j] == board[i][j - 1]) || (j < 3 && board[i][j] == board[i][j + 1])) {
                gl = true;
            }
        }
    }

    if (won) {
        cout << "\n\n\t\t\tCongratulations! You made 2048!\n\n\n";
        cin.get();
    }

    return fl && !gl;
}

  public: Game2048() {
    srand(static_cast < unsigned int > (time(NULL)));
    initBoard();
  }

  void play() {
    cout << "\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
    cin.get();
    system("cls");

    displayBoard();

    int tmp[4][4];
    char ch;
    while (true) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          tmp[i][j] = board[i][j];
        }
      }

      ch = getch();
      system("cls");

      switch (ch) {
      case 72: // Up arrow
        moveUp();
        break;
      case 80: // Down arrow
        moveDown();
        break;
      case 75: // Left arrow
        moveLeft();
        break;
      case 77: // Right arrow
        moveRight();
        break;
      case 27: // Escape key
        return;
      }

      if (!boardsEqual(tmp)) {
        addBlock();
      }

      displayBoard();

      if (gameOver()) {
        cout << "\n\n\t\t\tGAME OVER!!\n\n\n";
        cin.get();
        break;
      }
    }
  }
};

int main() {
  Game2048 game;
  game.play();
  return 0;
}

