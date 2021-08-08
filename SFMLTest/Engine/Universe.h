#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "Input/InputController.h"
#include "../Entities/GameObject.h"
#include "../Entities/Player.h"
#include "HUD.h"

class Universe {

    public:
        enum State { Playing, GameOver };
        State currentState = Playing;

        static Universe& getInstance();
        HUD* hud;

        bool exists();
        void update();
        void draw();

        void spawnObject(GameObject* gameObject);
        void registerObject(GameObject* gameObject);
        void spawnCollectible(Vec2D pos);
        void spawnAsteroidRain(int amount);

        Player* getPlayer();
        std::vector<GameObject*> getGameObjects();

        int consecutiveBigStarPickups;
        void increasePlayerScore(int score);
        void increaseAsteroidPoints(int points);
        void increaseSmallStarPoints(int points);
        void increaseBigStarPoints(int points);

        void restartGame();

        ~Universe();

    private:
        Universe();

        sf::RenderWindow* window;
        InputController* inputController;

        Player* player;
        std::vector<GameObject*> gameObjects;

        void _updateObjects();
        void _drawObjects();

        void handleRechargeStarSpawning();
        void handleEnemySpawning();
        void handleParticleSpawning();

        int playerScore;
};


