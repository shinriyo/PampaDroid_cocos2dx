//
//  GameLayer.cpp
//  PampaDroid
//
//  Created by shinriyo on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#import "GameLayer.h"

using namespace std;

USING_NS_CC;

GameLayer::GameLayer(void)
{
    _hero = NULL;
}

GameLayer::~GameLayer(void)
{
    // TODO:
    //    this->unscheduleUpdate();
}


bool GameLayer::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!CCLayer::init());
        this->isTouchEnabled();
        this->initTileMap();
        this->initHero();
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("pd_sprites.plist");
        _actors = CCSpriteBatchNode::create("pd_sprites.pvr.ccz");
        _actors->getTexture()->setAliasTexParameters();
        this->addChild(_actors, -5);
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void GameLayer::initTileMap()
{
    _tileMap = CCTMXTiledMap::create("pd_tilemap.tmx");
    CCObject* pObject;
    CCARRAY_FOREACH(_tileMap->getChildren(), pObject)
    {
        // is this map child a tile layer?
        CCTMXLayer *child = (CCTMXLayer*)pObject;
        child->getTexture()->setAliasTexParameters();
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

void GameLayer::didChangeDirectionTo(SimpleDPad *simpleDPad, CCPoint direction)
{
    _hero->walkWithDirection(direction);
}

void GameLayer::isHoldingDirection(SimpleDPad *simpleDPad, CCPoint direction)
{
    _hero->walkWithDirection(direction);
}

void GameLayer::simpleDPadTouchEnded(SimpleDPad *simpleDPad)
{
    if (_hero->getActionState() == kActionStateWalk)
    {
        _hero->idle();
    }
}
// part2
/*
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
 
void update(ccTime dt)
{
    _hero->update(dt);
    this->updatePositions();
}
 
void updatePositions()
{
    float posX = MIN(_tileMap.mapSize.width * _tileMap.tileSize.width - _hero.centerToSides, MAX(_hero.centerToSides, _hero.desiredPosition.x));
    float posY = MIN(3 * _tileMap.tileSize.height + _hero.centerToBottom, MAX(_hero.centerToBottom, _hero.desiredPosition.y));
    _hero.position = ccp(posX, posY);
}
*/