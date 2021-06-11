#include "InputController.h"
#include "../Universe.h"

InputController::InputController(sf::RenderWindow* window) : window(window) {
    inputActionMap[sf::Keyboard::Escape] = 1;
    inputActionMap[sf::Keyboard::Left] = 2;
    inputActionMap[sf::Keyboard::A] = 2;
    inputActionMap[sf::Keyboard::Right] = 3;
    inputActionMap[sf::Keyboard::D] = 3;
    inputActionMap[sf::Keyboard::Space] = 4;
    inputActionMap[sf::Keyboard::LShift] = 5;
//    inputActionMap[sf::Keyboard::Y] = 6;
//    inputActionMap[sf::Keyboard::N] = 7;
}

void InputController::handleInput() {
    sf::Event event;
    while (window->pollEvent(event)) {
        handleKeyInput(event);
    }
}

void InputController::handleKeyInput(sf::Event event) {
    auto it = inputActionMap.begin();

    while (it != inputActionMap.end())
    {
        sf::Keyboard::Key keyCode = it->first;
        int actionCode = it->second;

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == keyCode) {
                onKeyDown(actionCode);
            }
        }
        else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == keyCode) {
                onKeyUp(actionCode);
            }
        }

        it++;
    }
}

void InputController::onKeyDown(int action) {
    if (Universe::getInstance().currentState == Universe::State::GameOver) {
        return;
    }
    
    switch (action) {
        case MoveLeft:
            Universe::getInstance().getPlayer()->handleMovementInput(-1);
            break;
        case MoveRight:
            Universe::getInstance().getPlayer()->handleMovementInput(1);
            break;
        case Shoot:
            Universe::getInstance().getPlayer()->setShooting(true);
            break;
        case NitroBoost:
            Universe::getInstance().getPlayer()->setNitroThrustersActive(true);
            break;
        default:
            break;
    }
}

void InputController::onKeyUp(int action) {
    if (action == ExitGame) {
        window->close();
    }
    if (Universe::getInstance().currentState == Universe::State::GameOver) {
//        std::cout << "istnswintis" << std::endl;
//        if (action == RestartGame) {
//            Universe::getInstance().restartGame();
//        } else if (action == QuitGameAfterGameOver) {
//            window->close();
//        }
        return;
    }

    switch (action) {
        case MoveLeft:
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                Universe::getInstance().getPlayer()->handleMovementInput(0);
            }
            break;
        case MoveRight:
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                Universe::getInstance().getPlayer()->handleMovementInput(0);
            }
            break;
        case Shoot:
            Universe::getInstance().getPlayer()->setShooting(false);
            break;
        case NitroBoost:
            Universe::getInstance().getPlayer()->setNitroThrustersActive(false);
            break;
        default:
            break;
    }
}

//InputController::~InputController() {
//    delete window;
//}