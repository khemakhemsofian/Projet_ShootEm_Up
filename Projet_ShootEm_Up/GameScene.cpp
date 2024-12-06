#include "GameScene.h"



GameScene::GameScene(Game& game, RenderWindow& win) : _game(game), window(win) {}

void GameScene::run() {

    _game.run();
}

