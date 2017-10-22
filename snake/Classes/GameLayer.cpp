#include "GameLayer.h"

GameLayer::GameLayer(){}

GameLayer::~GameLayer(){}

bool GameLayer::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	
	//At beginning the length is 3
	snakePoints.push_back(Point(visibleSize.width / 2, visibleSize.height / 2));
	snakePoints.push_back(Point(visibleSize.width / 2 + 10, visibleSize.height / 2));
	snakePoints.push_back(Point(visibleSize.width / 2 + 20, visibleSize.height / 2));
	
	//the Direction is Left
	nextDirect = Direction::Left;

	isDie = false;

	//make the food of the snake
	food = Label::createWithSystemFont("O", "arial", 20);
	this->createFood();
	this->addChild(food);

	//make the snake
	this->createSnake();

	//start to LOOOOOOOOOP!!
	this->schedule(schedule_selector(GameLayer::update), 0.1);

	//listen the keyboard Event
	this->keyboardCallBack();

	return true;
}

void GameLayer::createSnake()
{
	for (auto p : snakeBody)
	{
		this->removeChild(p, true);
	}

	for (auto p : snakePoints)
	{
		auto snakePart = Label::createWithSystemFont("O", "airal", 20);
		snakePart->setPosition(p);
		snakePart->setTextColor(Color4B::GREEN);
		snakeBody.push_back(snakePart);

		this->addChild(snakePart);
	}
}

void GameLayer::createFood()
{
	bool success = false;

	while (!success)
	{
		foodPoint = Point(random(0, 64) * 10, random(0, 48) * 10);
		success = true;

		for (auto p : snakePoints)
		{
			if (p.x == foodPoint.x && p.y == foodPoint.y)
			{
				success = false;
				break;
			}
		}
	}

	food->setPosition(foodPoint);
	food->setTextColor(Color4B::ORANGE);
}

void GameLayer::snakeGoForward()
{
	Point nextP;

	if (nextDirect == Direction::Up)
	{
		for (int i = 0; i < snakePoints.size(); i++)
		{
			if (i == 0)
			{
				nextP = snakePoints[i];
				snakePoints[i] += Point(0, 10);
			}
			else
			{
				Point temp = snakePoints[i];
				snakePoints[i] = nextP;
				nextP = temp;
			}
		}
	}
	else if (nextDirect == Direction::Right)
	{
		for (int i = 0; i < snakePoints.size(); i++)
		{
			if (i == 0)
			{
				nextP = snakePoints[i];
				snakePoints[i] += Point(10, 0);
			}
			else
			{
				Point temp = snakePoints[i];
				snakePoints[i] = nextP;
				nextP = temp;
			}
		}
	}
	else if (nextDirect == Direction::Down)
	{
		for (int i = 0; i < snakePoints.size(); i++)
		{
			if (i == 0)
			{
				nextP = snakePoints[i];
				snakePoints[i] += Point(0, -10);
			}
			else
			{
				Point temp = snakePoints[i];
				snakePoints[i] = nextP;
				nextP = temp;
			}
		}
	}
	else if (nextDirect == Direction::Left)
	{
		for (int i = 0; i < snakePoints.size(); i++)
		{
			if (i == 0)
			{
				nextP = snakePoints[i];
				snakePoints[i] += Point(-10, 0);
			}
			else
			{
				Point temp = snakePoints[i];
				snakePoints[i] = nextP;
				nextP = temp;
			}
		}
	}
}

void GameLayer::eatFood()
{
	if (snakePoints[0] == foodPoint)
	{
		snakePoints.push_back(Point(0, 0));
		createFood();
	}
}

void GameLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		if (!(nextDirect == Direction::Right))
		{
			nextDirect = Direction::Left;
		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		if (!(nextDirect == Direction::Down))
		{
			nextDirect = Direction::Up;
		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		if (!(nextDirect == Direction::Left))
		{
			nextDirect = Direction::Right;
		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		if (!(nextDirect == Direction::Up))
		{
			nextDirect = Direction::Down;
		}
	}

	if ((isDie == true) && (keyCode == EventKeyboard::KeyCode::KEY_X))
	{
		Director::getInstance()->popScene();
	}
}

void GameLayer::keyboardCallBack()
{
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(GameLayer::onKeyPressed, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
}

void GameLayer::gameover()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	for (int i = 1; i < snakePoints.size(); i++)
	{
		if (snakePoints[0] == snakePoints[i])
		{
			auto dieLabel = Label::createWithSystemFont("You Died", "arial", 100);
			dieLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
			this->addChild(dieLabel);

			auto exitLabel = Label::createWithSystemFont("Press X to exit", "arial", 30);
			exitLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 1 / 5));
			this->addChild(exitLabel);
			
			Director::getInstance()->pause();
			isDie = true;

			break;
		}
	}
}

void GameLayer::update(float dt)
{
	snakeGoForward();
	createSnake();
	eatFood();
	gameover();
}