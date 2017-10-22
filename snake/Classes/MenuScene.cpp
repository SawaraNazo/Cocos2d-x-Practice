#include "MenuScene.h"

MenuScene::MenuScene(){}

MenuScene::~MenuScene(){}

bool MenuScene::init()
{
	if (Scene::init())
	{
		auto menuLayer = MenuLayer::create();
		this->addChild(menuLayer);

		return true;
	}
	else
	{
		return false;
	}
}