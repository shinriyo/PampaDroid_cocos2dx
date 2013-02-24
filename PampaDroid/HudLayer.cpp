//
//  HudLayer.cpp
//  PampaDroid
//
//  Created by shinriyo on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#import "HudLayer.h"

USING_NS_CC;

HudLayer::HudLayer(void)
{
    _dPad = NULL;
}

bool HudLayer::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!CCLayer::init());
        
        _dPad = SimpleDPad::dPadWithFile(CCString::create("pd_dpad.png"), 64);
        _dPad->setPosition(ccp(64.0, 64.0));
        _dPad->setOpacity(100);
        this->addChild(_dPad);
        
        bRet = true;
    } while (0);
    
    return bRet;
}

HudLayer::~HudLayer()
{
}