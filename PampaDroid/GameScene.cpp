//
//  GameScene.cpp
//  PampaDroid
//
//  Created by shinriyo on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#import "GameScene.h"
using namespace cocos2d;

GameScene::GameScene(void)
{
    _gameLayer = NULL;
    _hudLayer = NULL;
}

GameScene::~GameScene(void)
{
}

bool GameScene::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!CCScene::init());
        
        _gameLayer = GameLayer::create();
        this->addChild(_gameLayer, 0);
        _hudLayer = HudLayer::create();
        this->addChild(_hudLayer, 1);
        // add
        _hudLayer->getDPad()->setDelegate(_gameLayer);
        _gameLayer->setHud(_hudLayer);
        
        bRet = true;
    } while (0);
    
    return bRet;
}
