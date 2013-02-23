//
//  HudLayer.cpp
//  PampaDroid
//
//  Created by shinriyo on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#import "HudLayer.h"
#include "SimpleAudioEngine.h"

using namespace std;
using namespace CocosDenshion;

USING_NS_CC;

bool HudLayer::init()
{
    if ( !CCLayer::init() )
	{
		return false;
	}

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    return true;
}

HudLayer::~HudLayer()
{
}