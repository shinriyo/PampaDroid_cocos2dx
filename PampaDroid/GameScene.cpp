//
//  GameScene.cpp
//  PampaDroid
//
//  Created by sugita on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#import "GameScene.h"
#include "SimpleAudioEngine.h"

using namespace std;
using namespace CocosDenshion;

USING_NS_CC;

CCScene* GameScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
    
	// 'layer' is an autorelease object
    // deprecated in v2.0
	// GameScene *layer = GameScene::node();
	GameScene *layer = GameScene::create();
    
	// add layer as a child to scene
	scene->addChild(layer);
    
	// return the scene
	return scene;
}

bool GameScene::init()
{
    if ( !CCLayer::init() )
	{
		return false;
	}

    _gameLayer = GameLayer::create();
    addChild(_gameLayer, 0);
    _hudLayer = HudLayer::create();
    addChild(_hudLayer, 1);
    
    return true;
}
bool GameScene::ccTouchBegan(CCTouch *touch, CCEvent *event)
{
	return true;
}

void GameScene::ccTouchEnded(CCTouch *touch, CCEvent *event)
{
}

GameScene::~GameScene()
{
}