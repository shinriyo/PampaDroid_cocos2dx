//
//  GameLayer.cpp
//  PampaDroid
//
//  Created by sugita on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#import "GameLayer.h"
#include "SimpleAudioEngine.h"

using namespace std;
using namespace CocosDenshion;

USING_NS_CC;

bool GameLayer::init()
{
    if ( !CCLayer::init() )
	{
        initTileMap();
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("pd_sprites.plist");
        //_actors = CCSpriteBatchNode::spriteSheetWithFile("pd_sprites.pvr.ccz");
        _actors = CCSpriteBatchNode::batchNodeWithFile("pd_sprites.pvr.ccz");
        _actors->getTexture()->setAliasTexParameters();
        this->addChild(_actors, -5);
	}

    return true;
}

void GameLayer::initTileMap()
{
    _tileMap = CCTMXTiledMap::create("pd_tilemap.tmx");
    CCObject* object;
    CCARRAY_FOREACH(_tileMap->getChildren(), object)
    {
        // is this map child a tile layer?
        CCTMXLayer* layer = dynamic_cast<CCTMXLayer*>(object);
        layer->getTexture()->setAliasTexParameters();
    }
    
    this->addChild(_tileMap, -6);
}

bool GameLayer::ccTouchBegan(CCTouch *touch, CCEvent *event)
{
	return true;
}

void GameLayer::ccTouchEnded(CCTouch *touch, CCEvent *event)
{
}

GameLayer::~GameLayer()
{
}