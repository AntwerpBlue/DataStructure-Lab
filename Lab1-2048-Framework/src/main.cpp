#include <iostream>
#include "../include/Game.h"
#include "../include/GameRender.h"
#include "../include/InputHandler.h"

int main(){
    Game game;

    // Display welcome message
    TerminalRender::displayWelcomeMessage();

    // Wait for the start game command
    InputType command;
    while (true) {
        command = InputHandler::handleInput();
        if (command == InputType::START_GAME) {
            break;
        } else {
            std::cout << "Invalid input. Press 'E' to start the game.\n";
        }
    }

    // Initialize the game
    game.initGame();
    TerminalRender::render(game.getGameBoard(),game.getScore(),game.getMoveCount());

    // Game loop
    while (true) {
        // Handle user input
        InputType input = InputHandler::handleInput();
        // DONE

        if(input==InputType::UNDO){
            game.undoLastMove();
        }
        else if(input==InputType::QUIT_GAME){
            break;
        }
        else if(input==InputType::RESTART){
            game.initGame();
        }
        else{
            Direction direction;
            switch (input) {
                case InputType::UP:
                    direction = Direction::UP;
                    break;
                case InputType::DOWN:
                    direction = Direction::DOWN;
                    break;
                case InputType::LEFT:
                    direction = Direction::LEFT;
                    break;
                case InputType::RIGHT:
                    direction = Direction::RIGHT;
                    break;
                default:
                    std::cout<<"Invalid input. Use arrow keys to move, U to undo, or Q to quit.\n";
                    continue;
            }
            game.updateGame(direction);
        }
        TerminalRender::render(game.getGameBoard(),game.getScore(),game.getMoveCount());
        // Check for win or lose conditions
        // DONE
        if(game.hasWon()){
            TerminalRender::displayWinMessage();
        }
        else if(game.hasLost()){
            TerminalRender::displayLoseMessage();
        }
    }

    // Display elapsed time
    TerminalRender::displayElapsedTime(game.getElapsedTime());
    system("pause");
    // DONE

    return 0;
}
