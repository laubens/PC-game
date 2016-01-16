#include "MainMenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"
#include "GameScene.h"
#include "SettingsScene.h"
#include "LibraryScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    

	Size windowSize = Director::getInstance()->getVisibleSize(); //get the size of the screen
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//auto size = Director::getInstance()->getWinSize();

	auto background = Sprite::create("backgrounds.png"); //here the background.png is a "backgrounds" png.
	background->setPosition(windowSize.width / 2 + origin.x, windowSize.height / 2 + origin.y);
	//background->setPosition(Point(-size.width / 2, -size.height / 2));
	this->addChild(background);     // add a background sprite to watch more obviously

	//Creating the play button 
	auto playButton = MenuItemImage::create("playbutton2.png", "playbuttonclicked.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene,this));
	playButton->setPosition(Point(windowSize.width / 2 - 250, windowSize.height / 2 - 70));
	auto menu = Menu::create(playButton, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	//creating the settings button
	auto settingsButton = MenuItemImage::create("settingsbutton.png", "settingsbuttonclicked.png", CC_CALLBACK_1(MainMenuScene::GoToSettingsScene, this));
	settingsButton->setPosition(Point(windowSize.width / 2 + origin.x , windowSize.height / 2 - 250));
	auto menu2 = Menu::create(settingsButton, NULL);
	menu2->setPosition(Point::ZERO);
	this->addChild(menu2);
    return true;

	//creating the Library button
	auto libraryButton = MenuItemImage::create("Librarybutton.png", "Librarybuttonclicked.png", CC_CALLBACK_1(MainMenuScene::GoToLibraryScene, this));
	libraryButton->setPosition(Point(windowSize.width / 2 + origin.x, windowSize.height / 2 + origin.y));
	auto menu3 = Menu::create(libraryButton, NULL);
	menu3->setPosition(Point::ZERO);
	this->addChild(menu3);
	return true;

}


	void MainMenuScene::GoToGameScene(cocos2d::Ref *sender)
	{
		auto scene = GameScene::createScene();

		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

	}

	void MainMenuScene::GoToSettingsScene(cocos2d::Ref *sender)
	{
		auto scene = SettingsScene::createScene();

		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

	}

	void MainMenuScene::GoToLibraryScene(cocos2d::Ref *sender)
	{
		auto scene = LibraryScene::createScene();

		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

	}