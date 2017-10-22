#pragma once

#include "cocos2d.h"
#include "GameScene.h"

using namespace std;
using namespace cocos2d;

typedef enum _direction
{
	Up,
	Right,
	Down,
	Left
}Direction;

class GameLayer : public Layer
{
private:
	vector<Label*> snakeBody;
	vector<Point> snakePoints;

	Label* food;
	Point foodPoint;

	Direction nextDirect;
	bool isDie;
public:
	GameLayer();
	~GameLayer();

	virtual bool init();
	CREATE_FUNC(GameLayer);

	void createFood();
	void createSnake();
	
	void snakeGoForward();
	void eatFood();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void keyboardCallBack();

	void gameover();

	void update(float dt);
};

