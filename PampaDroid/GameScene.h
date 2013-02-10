//
//  GameScene.h
//  PampaDroid
//
//  Created by sugita on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#ifndef __GameScene_H__
#define __GameScene_H__ 

#include "cocos2d.h"
#include "GameLayer.h"
#include "HudLayer.h"

class GameScene : public cocos2d::CCLayer
{
public:
    ~GameScene();
    virtual bool init();  
    
    // touch detection
   	virtual bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	virtual void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
    
   	static cocos2d::CCScene* scene();
    // implement the "static node()" method manually
    // LAYER_NODE_FUNC does not exist in version2.x
    // LAYER_NODE_FUNC(GameScene);
	CREATE_FUNC(GameScene);
private:
    GameLayer *_gameLayer;
    HudLayer *_hudLayer;
};

#endif // __GameSceneH__