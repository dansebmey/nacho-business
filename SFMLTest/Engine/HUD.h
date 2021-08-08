#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

class HUD {
    public:
        HUD();

        int playerHealth = 3;
        float playerEnergy = 1;
        int playerScore;

        int asteroidPts = 0;
        int smallStarPts = 0;
        int bigStarPts = 0;

        void drawHUD(sf::RenderWindow* window);

        void drawGameOverText(sf::RenderWindow *window);

    private:
        sf::Font font;

        void drawPlayerHealth(sf::RenderWindow* window);
        void drawPlayerNitro(sf::RenderWindow* window);
        void drawPlayerScore(sf::RenderWindow* window);
        void drawPlayerXP(sf::RenderWindow* window);
};