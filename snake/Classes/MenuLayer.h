#pragma once

#include "cocos2d.h"
#include "GameScene.h"

using namespace std;
using namespace cocos2d;

class MenuLayer : public Layer
{
public:
	MenuLayer();
	~MenuLayer();

	virtual bool init();
	CREATE_FUNC(MenuLayer);

	void startGameCallBack(Ref* pSender);
	void exitGameCalllBack(Ref* pSender);
};

