#include "Splashscene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

	//Get the window size
	auto size = Director::getInstance()->getWinSize();

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
	//Get the window size
	auto size = Director::getInstance()->getWinSize();

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	this->scheduleOnce(schedule_selector(SplashScene::GoToMainMenuScene), DISPLAY_TIME_SPLASH_SCENE);

	auto backgroundSprite = Sprite::create("splashbackground.png");
	backgroundSprite->setPosition(size.width / 2, size.height / 2);

	this->addChild(backgroundSprite);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("slowmo_out.wav");

    return true;
}


void SplashScene::GoToMainMenuScene(float dt)
{
	auto scene = MainMenuScene::createScene( );

	Director::getInstance( )->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
