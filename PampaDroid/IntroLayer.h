//
//  IntroLayer.h
//  PampaDroid
//
//  Created by shinriyo on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#ifndef __IntroLayer_H__
#define __IntroLayer_H__ 
#define CC_IS_IPAD() (CCDirector::sharedDirector()->getWinSize().width==1024||CCDirector::sharedDirector()->getWinSize().height==1024)
#define CC_IS_IPAD3() (CC_IS_IPAD() && CC_CONTENT_SCALE_FACTOR()>1.0f)

#include "cocos2d.h"
#include "GameScene.h"

class IntroLayer : public cocos2d::CCLayer
{
public:
    ~IntroLayer();
    virtual bool init();  
    virtual void onEnter();  
//    virtual void onExit();  
    
   	static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    // LAYER_NODE_FUNC does not exist in version2.x
    // LAYER_NODE_FUNC(IntroLayer);
	CREATE_FUNC(IntroLayer);
    void makeTransition(cocos2d::CCTime dt);  
};

#endif // __IntroLayerH__