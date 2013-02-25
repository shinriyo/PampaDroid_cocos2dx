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
#include "HudLayer.h"

class GameLayer : public cocos2d::CCLayer, public SimpleDPadDelegate
{
public:
    GameLayer(void);
    ~GameLayer(void);
    bool init();  
    void initTileMap();
    cocos2d::CCTMXTiledMap* _tileMap;
    
    // touch detection
   	virtual bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	virtual void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);

    cocos2d::CCSpriteBatchNode *_actors;
    Hero *_hero;
    void initHero();
//   	static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    // LAYER_NODE_FUNC does not exist in version2.x
    // LAYER_NODE_FUNC(GameLayer);
	CREATE_FUNC(GameLayer);
   
    // And add the following statement:
    virtual void didChangeDirectionTo(SimpleDPad *simpleDPad, cocos2d::CCPoint direction);
    virtual void isHoldingDirection(SimpleDPad *simpleDPad, cocos2d::CCPoint direction);
    virtual void simpleDPadTouchEnded(SimpleDPad *simpleDPad);
    
    CC_SYNTHESIZE(HudLayer*, _hud, Hud);

};

#endif // __GameLayerH__