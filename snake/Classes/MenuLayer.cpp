#include "MenuLayer.h"

MenuLayer::MenuLayer(){}

MenuLayer::~MenuLayer(){}


bool MenuLayer::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	//��ȡXML�ļ�
	auto *chnstring = Dictionary::createWithContentsOfFile("xml/CHN_Strings.xml");

	//���⡰̰���ߡ�
	const char *title = ((String*)chnstring->objectForKey("title"))->getCString();
	auto *titleLabel = Label::createWithSystemFont(title, "����", 100);
	titleLabel->setTextColor(Color4B(0, 255, 127, 255));
	titleLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 3 / 4));
	this->addChild(titleLabel);

	//��ʼ��Ϸ
	const char *startGame = ((String*)chnstring->objectForKey("startGame"))->getCString();
	auto *startGameLabel = Label::createWithSystemFont(startGame, "����", 35);
	MenuItem *startGameButton = MenuItemLabel::create(startGameLabel,CC_CALLBACK_1(MenuLayer::startGameCallBack,this));
	startGameButton->setColor(Color3B::YELLOW);
	startGameButton->setPosition(Vec2(0, -visibleSize.height / 5));

	//������Ϸ
	const char *exitGame = ((String*)chnstring->objectForKey("exitGame"))->getCString();
	auto *exitGameLabel = Label::createWithSystemFont(exitGame, "����", 35);
	MenuItem *exitGameButton = MenuItemLabel::create(exitGameLabel, CC_CALLBACK_1(MenuLayer::exitGameCalllBack, this));
	exitGameButton->setColor(Color3B::YELLOW);
	exitGameButton->setPosition(Vec2(0, -visibleSize.height / 3));

	//�˵�
	Menu *menu = Menu::create(startGameButton, exitGameButton, NULL);
	this->addChild(menu);

	return true;
}

void MenuLayer::startGameCallBack(Ref* pSender)
{
	auto scene = GameScene::create();
	TransitionScene *transition = TransitionFade::create(1, scene);
	Director::getInstance()->replaceScene(transition);
}

void MenuLayer::exitGameCalllBack(Ref* pSender)
{
	Director::getInstance()->popScene();
}