#pragma once

#include "cocos2d.h"
#include "MenuLayer.h"

using namespace std;
using namespace cocos2d;

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	virtual bool init();
	CREATE_FUNC(MenuScene);
};

