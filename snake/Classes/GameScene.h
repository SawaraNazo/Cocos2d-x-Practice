#pragma once

#include "cocos2d.h"
#include "GameLayer.h"

using namespace std;
using namespace cocos2d;

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	virtual bool init();

	CREATE_FUNC(GameScene);
};

