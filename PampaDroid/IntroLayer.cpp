//
//  IntroLayer.cpp
//  PampaDroid
//
//  Created by shinriyo on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#import "IntroLayer.h"
#include "SimpleAudioEngine.h"

using namespace std;
using namespace CocosDenshion;

USING_NS_CC;

CCScene* IntroLayer::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
    
	// 'layer' is an autorelease object
    // deprecated in v2.0
	// IntroLayer *layer = IntroLayer::node();
	IntroLayer *layer = IntroLayer::create();
    
	// add layer as a child to scene
	scene->addChild(layer);
    
	// return the scene
	return scene;
}

bool IntroLayer::init()
{
    if ( !CCLayer::init() )
	{
		return false;
	}

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    return true;
}

void IntroLayer::onEnter()
{
    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *background;
	background = CCSprite::create("Default.png");
	background->setRotation(90);
    this->scheduleOnce(schedule_selector(IntroLayer::makeTransition), 1.0F);
}

void IntroLayer::makeTransition(CCTime dt)
{
//    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0, GameScene::scene(), ccWHITE));
}

IntroLayer::~IntroLayer()
{
}