#include "Universe.h"
#include "../Entities/Player.h"
#include "TimeUtil.h"
#include "../Entities/FallingObjects/Asteroids/Asteroid.h"
#include "GameConstants.h"
#include "../Entities/FallingObjects/Collectibles/Star.h"
#include "../Entities/FallingObjects/Particles/Particle.h"
#include "../Entities/FallingObjects/Collectibles/RechargeStar.h"

Universe::Universe() {
    window = new sf::RenderWindow(sf::VideoMode(GameConstants::screenWidth, GameConstants::screenHeight), "(S)FML");
    window->setFramerateLimit(GameConstants::targetFPS);

    inputController = new InputController(window);

    hud = new HUD();

    gameObjects.reserve(100);
    player = new Player(Vec2D(GameConstants::screenWidth * 0.5f, GameConstants::screenHeight * 0.9f));
    registerObject(player);
}

Universe& Universe::getInstance() {
    static Universe instance;
    return instance;
}

void Universe::registerObject(GameObject* object) {
    std::cout << "New object registered (index: " << gameObjects.size() << " | " << &gameObjects << ")" << std::endl;
    gameObjects.push_back(object);
}

bool Universe::exists() {
    return window->isOpen();
}

void Universe::update() {
    TimeUtil::getInstance().update();
    inputController->handleInput();

    _updateObjects();

    if (Universe::getInstance().currentState == Playing) {
        handleRechargeStarSpawning();
        handleEnemySpawning();
    }
    handleParticleSpawning();
}

void Universe::_updateObjects() {
    auto& gObjs = Universe::getInstance().gameObjects;
    for(int i = gObjs.size()-1; i >= 0; i--) {
        GameObject* gObj = gObjs[i];
        gObj->update();

        if (gObj->isDestroyConditionMet()) {
            gObjs.erase(gObjs.begin() + i);
            std::cout << gObj << std::endl;
            delete gObj;
        }
    }
}

void Universe::draw() {
    window->clear();

    _drawObjects();
    if (Universe::getInstance().currentState == Playing) {
        hud->drawHUD(window);
    } else if (Universe::getInstance().currentState == GameOver) {
        hud->drawGameOverText(window);
    }

    window->display();
}

void Universe::_drawObjects() {
    for(int i = 0; i < Universe::getInstance().gameObjects.size(); i++)
    {
        Universe::getInstance().gameObjects[i]->draw(window);
    }
}

void Universe::spawnObject(GameObject* object) {
    registerObject(object);
}

Player* Universe::getPlayer() {
    return player;
}

void Universe::handleRechargeStarSpawning() {
    if (TimeUtil::getInstance().hasTimePassed(2500)) {
//    if (TimeUtil::getInstance().hasTimePassed(std::max(2500 - playerScore * 5, 1000))) {
        float randomX = GameConstants::screenPadding + (rand() % (GameConstants::screenWidth - (GameConstants::screenPadding * 2)));
        Universe::getInstance().spawnObject(new RechargeStar(Vec2D(randomX, GameConstants::screenHeight * -0.1f - 24), GameConstants::enemyMovSpeed));
    }
}

void Universe::handleEnemySpawning() {
    static int spawnCounter;
    if (TimeUtil::getInstance().hasTimePassed(1000)) {
//    if (TimeUtil::getInstance().hasTimePassed(std::max(1000 - playerScore * 2, 400))) {
        spawnCounter++;
        if (spawnCounter < 8) {
            float randomX = GameConstants::screenPadding + (rand() % (GameConstants::screenWidth - (GameConstants::screenPadding * 2)));
            Universe::getInstance().spawnObject(new Asteroid(Vec2D(randomX, GameConstants::screenHeight * -0.1f), rand() % 3 == 0));
        } else {
            spawnAsteroidRain(16);
            spawnCounter = 0;
        }
    }
}

void Universe::handleParticleSpawning() {
    if (TimeUtil::getInstance().hasTimePassed(100)) {
        float randomX = rand() % GameConstants::screenWidth;
        Universe::getInstance().spawnObject(new Particle(Vec2D(randomX, GameConstants::screenHeight * -0.1f)));
    }
}

std::vector<GameObject*> Universe::getGameObjects() {
    return gameObjects;
}

void Universe::increasePlayerScore(int i) {
    playerScore += i;
    hud->playerScore = playerScore;
}

void Universe::spawnAsteroidRain(int amount) {
    int randomNr = rand() % amount;

    for (int i = 0; i < amount; i++) {
        if (i < randomNr - 1 || i > randomNr + 1) {
            float x = (GameConstants::screenWidth / amount) * i;
            Universe::getInstance().spawnObject(new Asteroid(Vec2D(x, GameConstants::screenHeight * -0.1f), false));
        }
    }
}

void Universe::spawnCollectible(Vec2D pos) {
    Universe::getInstance().spawnObject(new Star(pos, GameConstants::enemyMovSpeed));
}

void Universe::restartGame() {
    player = new Player(Vec2D(GameConstants::screenWidth * 0.5f, GameConstants::screenHeight * 0.9f));
    playerScore = 0;
    currentState = Playing;
}

Universe::~Universe() {
    delete window;
    delete inputController;
    delete player;

    std::for_each(begin(gameObjects), end(gameObjects), [&](GameObject* obj) {
        delete obj;
    });
}