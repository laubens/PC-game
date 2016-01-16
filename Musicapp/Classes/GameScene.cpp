#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	Size windowSize = Director::getInstance()->getVisibleSize(); //get the size of the screen
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//auto size = Director::getInstance()->getWinSize();

	auto background = Sprite::create("wip.png"); //here the background.png is a "backgrounds" png.
	background->setPosition(windowSize.width / 2 + origin.x, windowSize.height / 2 + origin.y);
	//background->setPosition(Point(-size.width / 2, -size.height / 2));
	this->addChild(background);     // add a background sprite to watch more obviously

    return true;
}
