#pragma once

#include <iostream>
#include <map>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class InputController {

    public:
        InputController(sf::RenderWindow* window);

        void handleInput();

        ~InputController();
    private:
        enum Button {
            ExitGame = 1,
            MoveLeft = 2,
            MoveRight = 3,
            Shoot = 4,
            NitroBoost = 5,
//            RestartGame = 6,
//            QuitGameAfterGameOver = 7,
        };

        sf::RenderWindow* window;
        std::map<sf::Keyboard::Key, int> inputActionMap;
        void handleKeyInput(sf::Event event);

        void onKeyDown(int action);
        void onKeyHeld(int action);
        void onKeyUp(int action);
};