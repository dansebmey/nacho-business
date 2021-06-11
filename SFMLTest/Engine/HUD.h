#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

class HUD {
    public:
        HUD();

        int playerHealth = 3;
        float playerEnergy = 1;
        int playerScore;

        void drawHUD(sf::RenderWindow* window);

        void drawGameOverText(sf::RenderWindow *window);

    private:
        sf::Font font;

        void drawPlayerHealth(sf::RenderWindow* window);
        void drawPlayerNitro(sf::RenderWindow* window);
        void drawPlayerScore(sf::RenderWindow* window);
};