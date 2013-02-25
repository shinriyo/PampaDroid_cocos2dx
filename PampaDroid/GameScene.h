//
//  GameScene.h
//  PampaDroid
//
//  Created by shinriyo on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#ifndef __GameScene_H__
#define __GameScene_H__ 

#include "cocos2d.h"
#include "GameLayer.h"
#include "HudLayer.h"

class GameScene : public cocos2d::CCScene
{
public:
    GameScene(void);
    ~GameScene(void);
    
    virtual bool init();
	CREATE_FUNC(GameScene);
   
    CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);
    CC_SYNTHESIZE(HudLayer*, _hudLayer, HudLayer);
};

#endif // __GameSceneH__