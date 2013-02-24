//
//  GameLayer.cpp
//  PampaDroid
//
//  Created by sugita on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#import "GameLayer.h"

using namespace std;

USING_NS_CC;

bool GameLayer::init()
{
    if ( !CCLayer::init() )
	{
        this->isTouchEnabled();
        initTileMap();
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("pd_sprites.plist");
        _actors = CCSpriteBatchNode::batchNodeWithFile("pd_sprites.pvr.ccz");
        //_actors = CCSpriteBatchNode::spriteSheetWithFile("pd_sprites.pvr.ccz");
        _actors->getTexture()->setAliasTexParameters();
        this->addChild(_actors, -5);
	}

    return true;
}

void GameLayer::initTileMap()
{
    _tileMap = CCTMXTiledMap::create("pd_tilemap.tmx");
    CCObject* pObject;
    CCARRAY_FOREACH(_tileMap->getChildren(), pObject)
    {
        // is this map child a tile layer?
        CCTMXLayer* layer = dynamic_cast<CCTMXLayer*>(pObject);
        layer->getTexture()->setAliasTexParameters();
    }
    
    this->addChild(_tileMap, -6);
}

bool GameLayer::ccTouchBegan(CCTouch *touch, CCEvent *event)
{
    _hero->attack();
	return true;
}

void GameLayer::ccTouchEnded(CCTouch *touch, CCEvent *event)
{
}

void GameLayer::initHero()
{
    _hero = (Hero*)Hero::create();
    _actors->addChild(_hero);
    _hero->setPosition(ccp(_hero->getCenterToSides(), 80));
    _hero->idle();
}

GameLayer::~GameLayer()
{
}

// part2
void GameLayer::simpleDPad(SimpleDPad* simpleDPad, CGPoint direction)
{
    _hero->walkWithDirection(direction);
}

void GameLayer::simpleDPadTouchEnded(SimpleDPad* simpleDPad)
{
    if (_hero->getActionState() == kActionStateWalk) {
        _hero->idle();
    }
}

void simpleDPad(SimpleDPad* simpleDPad, CGPoint direction)
{
    _hero->walkWithDirection(direction);
}
