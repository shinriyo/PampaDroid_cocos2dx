//
//  GameLayer.h
//  PampaDroid
//
//  Created by shinriyo on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#ifndef __GameLayer_H__
#define __GameLayer_H__ 

#include "cocos2d.h"
#include "Hero.h"
#include "SimpleDPad.h"

class GameLayer : public cocos2d::CCLayer
{
public:
    ~GameLayer();
    virtual bool init();  
    
    // touch detection
   	virtual bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	virtual void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
    
//   	static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    // LAYER_NODE_FUNC does not exist in version2.x
    // LAYER_NODE_FUNC(GameLayer);
	CREATE_FUNC(GameLayer);
private:
    void initTileMap();
    cocos2d::CCTMXTiledMap* _tileMap;
    cocos2d::CCSpriteBatchNode *_actors;
    Hero *_hero;
    void initHero();
   /*
    void simpleDPad(SimpleDPad* simpleDPad, CGPoint direction);
    void simpleDPadTouchEnded(SimpleDPad* simpleDPad);
    void simpleDPad(SimpleDPad* simpleDPad, CGPoint direction);
    */
};

#endif // __GameLayerH__