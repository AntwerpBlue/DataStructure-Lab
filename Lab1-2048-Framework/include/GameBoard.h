#ifndef INC_2048_GAMEBOARD_H
#define INC_2048_GAMEBOARD_H

#include <vector>
#include <random>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

using Board = std::vector<std::vector<int>>;

class GameBoard {
public:
    GameBoard();
    void reset();
    std::pair<int,bool> move(Direction direction);
    bool isGameOver() const;
    bool hasWinningTile() const;
    const Board& getBoard() const;

private:
    Board board;
    std::vector<int> checkEmpty() const;
    std::mt19937 generator;
    int merge(std::vector<int>& row);
    void addTile();
    //int getMaxTile();
};

#endif //INC_2048_GAMEBOARD_H
