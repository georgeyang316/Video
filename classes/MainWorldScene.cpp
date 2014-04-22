#include "MainWorldScene.h"
#include "SimpleAudioEngine.h"
#include "WrapperClass.h"
#include "Config.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* MainWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainWorld *layer = MainWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainWorld::init()
{
    Config *c = Config::getConfig();
    if ( !CCLayer::init() )
    {
        return false;
    }
    
//    CCMenuItemFont *vidFont = CCMenuItemFont::create("Click to play Video", this, menu_selector(MainWorld::menuCallback));
    
    CCSprite* bg = CCSprite::create("bg.png");
    bg->setPosition( ccp(c->screenWidth * 0.5, c->screenHeight * 0.5) );
    bg->setRotation(90);
    bg->setScale(5);
    this->addChild(bg);
    
    CCMenuItemSprite* matty = CCMenuItemSprite::create(CCSprite::create("matty.jpg"), CCSprite::create("matty.jpg"),this, menu_selector(MainWorld::menuMatty));
    CCMenuItemSprite* george = CCMenuItemSprite::create(CCSprite::create("george.jpg"), CCSprite::create("george.jpg"),this, menu_selector(MainWorld::menuGeorge));
    
    CCMenu* pMenu = CCMenu::create(matty,george, NULL);
    pMenu->alignItemsHorizontally();
    //pMenu->setPosition( ccp(c->screenWidth * 0.5, c->screenHeight * 0.5) );
    this->addChild(pMenu, 1);
    
    return true;
}

void MainWorld::menuCallback(CCObject* pSender)
{
    WrapperClass::getShared()->playVideo("IMG_0066");
}

void MainWorld::menuGeorge(CCObject* pSender)
{
    WrapperClass::getShared()->playVideo("george-cooper");
}
void MainWorld::menuMatty(CCObject* pSender)
{
    WrapperClass::getShared()->playVideo("matty-cooper");
}