#include "HUD.h"
#include "GameConstants.h"
#include "DebugUtil.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include "../Engine/GameConstants.h"

HUD::HUD() {
    if (!font.loadFromFile("../Resources/Fonts/runescape_chat_font.ttf")) {
        std::cerr << "Could not find font" << std::endl;
    }
}

void HUD::drawHUD(sf::RenderWindow* window) {
    drawPlayerHealth(window);
    drawPlayerNitro(window);
    drawPlayerScore(window);
    drawPlayerXP(window);
}

void HUD::drawPlayerHealth(sf::RenderWindow* window) {
    sf::CircleShape shape(12, 3);
    shape.setFillColor(sf::Color::Red);

    sf::RectangleShape outline(sf::Vector2f(24, 24));
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineColor(sf::Color::White);
    outline.setOutlineThickness(2);

    for (int i = 0; i < 3; i++) {
        outline.setPosition(12 + i * 30, 16);
        window->draw(outline);

        if (i < playerHealth) {
            shape.setPosition(12 + i * 30, 20);
            window->draw(shape);
        }
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

void HUD::drawPlayerXP(sf::RenderWindow* window) {
    sf::RectangleShape outline(sf::Vector2f(84, 12));
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineColor(sf::Color::White);
    outline.setOutlineThickness(2);
    outline.setPosition(12, 74);

    sf::RectangleShape fill(sf::Vector2f((76.0f / GameConstants::scoreRequiredPerLevel) * (playerScore % GameConstants::scoreRequiredPerLevel), 4));
    fill.setFillColor(sf::Color::Yellow);
    fill.setPosition(16, 78);

    window->draw(outline);
    window->draw(fill);
}

void HUD::drawPlayerScore(sf::RenderWindow* window) {
    sf::Text text(std::to_string(playerScore), font, 24);
    text.setPosition(16, 92);
    window->draw(text);
}

void HUD::drawGameOverText(sf::RenderWindow* window) {
    sf::Text gameOverText("Game Over", font, 72);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(GameConstants::screenWidth * 0.1f, GameConstants::screenHeight * 0.1f);
    window->draw(gameOverText);

    sf::Text scoreText("You scored " + std::to_string(playerScore) + " points!", font, 36);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setPosition(GameConstants::screenWidth * 0.1f, GameConstants::screenHeight * 0.1f + 72);
    window->draw(scoreText);

    sf::Text asteroidPtsText(std::to_string(asteroidPts) + " points from shooting asteroids", font, 28);
    asteroidPtsText.setFillColor(sf::Color::Red);
    asteroidPtsText.setPosition(GameConstants::screenWidth * 0.1f, GameConstants::screenHeight * 0.1f + 152);
    window->draw(asteroidPtsText);

    sf::Text smallStarPtsText(std::to_string(smallStarPts) + " points from collecting small stars", font, 28);
    smallStarPtsText.setFillColor(sf::Color::Red);
    smallStarPtsText.setPosition(GameConstants::screenWidth * 0.1f, GameConstants::screenHeight * 0.1f + 184);
    window->draw(smallStarPtsText);

    sf::Text bigStarPtsText(std::to_string(bigStarPts) + " points from collecting big stars", font, 28);
    bigStarPtsText.setFillColor(sf::Color::Red);
    bigStarPtsText.setPosition(GameConstants::screenWidth * 0.1f, GameConstants::screenHeight * 0.1f + 216);
    window->draw(bigStarPtsText);

//    sf::Text retryText("Retry? (Y/N)", font, 36);
//    retryText.setFillColor(sf::Color::Red);
//    retryText.setPosition(GameConstants::screenWidth / 2, GameConstants::screenHeight / 2 + 72);
//    window->draw(retryText);
}
