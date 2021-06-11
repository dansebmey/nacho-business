#include "HUD.h"
#include "GameConstants.h"
#include "DebugUtil.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>

HUD::HUD() {
    if (!font.loadFromFile("../Resources/Fonts/runescape_chat_font.ttf")) {
        std::cerr << "Could not find font" << std::endl;
    }
}

void HUD::drawHUD(sf::RenderWindow* window) {
    drawPlayerHealth(window);
    drawPlayerNitro(window);
    drawPlayerScore(window);
}

void HUD::drawPlayerHealth(sf::RenderWindow* window) {
    sf::CircleShape shape(15, 3);
    shape.setFillColor(sf::Color::Red);
    for (int i = 0; i < playerHealth; i++) {
        shape.setPosition(12 + i * 28, 16);
        window->draw(shape);
    }
}

void HUD::drawPlayerNitro(sf::RenderWindow* window) {
    sf::RectangleShape outline(sf::Vector2f(84, 24));
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineColor(sf::Color::White);
    outline.setOutlineThickness(2);
    outline.setPosition(12, 48);

    sf::RectangleShape fill(sf::Vector2f(playerEnergy * 76, 16));
    fill.setFillColor(sf::Color::Red);
    fill.setPosition(16, 52);

    window->draw(outline);
    window->draw(fill);
}

void HUD::drawPlayerScore(sf::RenderWindow* window) {
    sf::Text text(std::to_string(playerScore), font, 24);
    text.setPosition(16, 76);
    window->draw(text);
}

void HUD::drawGameOverText(sf::RenderWindow* window) {
    sf::Text gameOverText("Game Over", font, 72);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(GameConstants::screenWidth / 2, GameConstants::screenHeight / 2);
    window->draw(gameOverText);

    sf::Text retryText("Retry? (Y/N)", font, 36);
    retryText.setFillColor(sf::Color::Red);
    retryText.setPosition(GameConstants::screenWidth / 2, GameConstants::screenHeight / 2 + 72);
    window->draw(retryText);
}
