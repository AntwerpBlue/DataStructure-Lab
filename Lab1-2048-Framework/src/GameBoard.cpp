#include "../include/GameBoard.h"
#include <algorithm>
#include <random>
#include <chrono>

bool operator!=(GameBoard &before,GameBoard &after){
    auto beforeBoard = before.getBoard();
    auto afterBoard = after.getBoard();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(beforeBoard[i][j]!=afterBoard[i][j]){
                return true;
            }
        }
    }
    return false;
}


GameBoard::GameBoard() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator = std::mt19937(seed);
    reset();
}

//int GameBoard::getMaxTile(){
//    // Return the max tile value in the board, which is used to add a new tile
//    // As we suppose that the new tile should be no larger than max_num/2.
//    int max_num=0;
//    for(int i=0;i<4;i++){
//        max_num=std::max(max_num,*std::max_element(board[i].begin(),board[i].end()));
//    }
//    return max_num;
//}
//

std::vector<int> GameBoard::checkEmpty() const{
    // Check if there is any empty tile in the board
    auto isEmpty = std::vector<int>();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==0){
                isEmpty.push_back(i*4+j);
            }
        }
    }
    return isEmpty;
}

void GameBoard::addTile(){
    auto isEmpty = checkEmpty();
    if(isEmpty.empty()){
        return;
    }
    std::uniform_int_distribution<int> distribution(0, isEmpty.size()-1);
    int index = distribution(generator);
    int col = isEmpty[index]%4;
    int row = isEmpty[index]/4;
    //int max_num=getMaxTile();
    std::uniform_real_distribution<double> distribution_num(0, 1);
    double radnum = distribution_num(generator);
    if(radnum>0.3){
        board[row][col]=1;
    }
    else{
        board[row][col]=2;
    }
}

void GameBoard::reset() {
    // Initialize the board to be 4x4 with all values set to 0
    // DONE
    board = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));

    // Add two initial tiles
    // DONE
    std::uniform_int_distribution<int> distribution(0, 3);
    int row = distribution(generator);
    int col = distribution(generator);
    board[row][col] = 1;
    //The number stored in the board is the exp of 2
    //e.g. board[row][col] = 1 means 2^1 = 2
    addTile();
}

std::pair<int, bool> GameBoard::move(Direction direction) {
    // DONE
    int moveScore=0;
    auto copyBoard = board;
    switch (direction) {
        case Direction::DOWN:
            for(int col=0;col<4;col++){
                auto nums=std::vector<int>();
                for(int row=0;row<4;row++){
                    if(board[row][col]!=0){
                        nums.push_back(board[row][col]);
                    }
                }
                moveScore+=merge(nums);
                for(int row=0;row<4;row++){
                    if(row<nums.size()){
                        board[row][col]=nums[row];
                    }
                    else{
                        board[row][col]=0;
                    }
                }
            }
            break;
        case Direction::UP:
            for(int col=0;col<4;col++){
                auto nums=std::vector<int>();
                for(int row=3;row>=0;row--){
                    if(board[row][col]!=0){
                        nums.push_back(board[row][col]);
                    }
                }
                moveScore+=merge(nums);
                for(int row=3;row>=0;row--){
                    if(row<4-nums.size()){
                        board[row][col]=0;
                    }            
                    else{
                        board[row][col]=nums[3-row];
                    }
                }
            }
            break;
        case Direction::LEFT:
            for(int row=0;row<4;row++){
                auto nums=std::vector<int>();
                for(int col=0;col<4;col++){
                    if(board[row][col]!=0){
                        nums.push_back(board[row][col]);
                    }
                }
                moveScore+=merge(nums);
                for(int col=0;col<4;col++){
                    if(col>=nums.size()){
                        board[row][col]=0;
                    }
                    else{
                        board[row][col]=nums[col];
                    }
                }
            }
            break;
        case Direction::RIGHT:
            for(int row=0;row<4;row++){
                auto nums=std::vector<int>();
                for(int col=3;col>=0;col--){
                    if(board[row][col]!=0){
                        nums.push_back(board[row][col]);
                    }
                }
                moveScore+=merge(nums);
                for(int col=3;col>=0;col--){
                    if(col<4-nums.size()){
                        board[row][col]=0;
                    }
                    else{
                        board[row][col]=nums[3-col];
                    }
                }
            }
            break;
    }
    if(copyBoard!=board){
        addTile();
    }
    return std::make_pair(moveScore, board!=copyBoard);
}

////////////////////////////////////////////
int GameBoard::merge(std::vector<int> &nums) {
    int moveScore = 0;
    int size=nums.size();
    for(int i=0;i<size-1;i++){
        if(nums[i]==nums[i+1]){
            nums[i]++;
            moveScore+=(1<<nums[1]);
            for(int j=i+1;j<size-1;j++){
                nums[j]=nums[j+1];
            }
            size--;
        }
    }
    nums.erase(nums.begin()+size,nums.end());
    return moveScore;
}

bool GameBoard::isGameOver() const {
    // Check if there are any empty tiles
    auto isEmpty=checkEmpty();
    if(!isEmpty.empty()){
        return false;
    }
    else{////////  FIX ME!!!!  ///////
        for(int row=0;row<4;row++){
            for(int col=0;col<4;col++){
                if(row<3){
                    if(board[row][col]==board[row+1][col]){
                        return false;
                    }
                }
                if(col<3){
                    if(board[row][col]==board[row][col+1]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
    // DONE
}

bool GameBoard::hasWinningTile() const {
    // DONE
    for(int row=0;row<4;row++){
        for(int col=0;col<4;col++){
            if(board[row][col]==2048){
                return true;
            }
        }
    }
    return false;
}

const Board &GameBoard::getBoard() const {
    return board;
}