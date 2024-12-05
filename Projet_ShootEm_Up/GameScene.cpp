#include "GameScene.h"




GameScene::GameScene(Game& game) : _game(game) {}

void GameScene::run() {
	
    _game.run();
}

