#include "../include/Game.h"
#include <tuple>

Game::Game() = default;

void Game::initGame() {
    gameBoard.reset();
    score = 0;
    moveCount = 0;
    historyScores=std::stack<int>();
    historyGameBoards = std::stack<GameBoard>();
    startTime = std::chrono::system_clock::now();
    historyGameBoards.push(gameBoard);  // Save initial state
}

void Game::updateGame(Direction direction) {
    // DONE
    int moveScore;
    bool hasChanged;
    std::tie(moveScore,hasChanged)=gameBoard.move(direction);
    if(hasChanged){
        historyGameBoards.push(gameBoard);
        historyScores.push(moveScore);
        moveCount++;
        score+=moveScore;
    }
}

void Game::undoLastMove() {
    // DONE
    if(historyGameBoards.size()>1){
        historyGameBoards.pop();
        gameBoard = historyGameBoards.top();
        score-=historyScores.top();
        historyScores.pop();
        moveCount--;
    }
    else{
        gameBoard.reset();
    }
}

bool Game::hasWon() const {
    return gameBoard.hasWinningTile();
}

bool Game::hasLost() const {
    return gameBoard.isGameOver();
}

double Game::getElapsedTime() const {
    auto endTime = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = endTime - startTime;
    return elapsedSeconds.count();
}

int Game::getScore() const {
    return score;
}

int Game::getMoveCount() const {
    return moveCount;
}

const GameBoard& Game::getGameBoard() const {
    return gameBoard;
}