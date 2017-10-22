#include "GameScene.h"

GameScene::GameScene(){}

GameScene::~GameScene(){}

bool GameScene::init()
{
	if (Scene::create())
	{
		auto gameLayer = GameLayer::create();
		this->addChild(gameLayer);

		return true;
	}

	return false;
}