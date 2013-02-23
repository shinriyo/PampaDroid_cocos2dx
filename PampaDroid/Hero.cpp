//
//  File.cpp
//  PampaDroid
//
//  Created by sugita on 13/02/10.
//
//

#include "Hero.h"
using namespace std;

USING_NS_CC;

bool Hero::init()
{
    if (ActionSprite::initWithSpriteFrameName("hero_idle_00.png")) {
        int i;
        
        //idle animation
        //CCArray *idleFrames = CCArray::arrayWithCapacity(6);
        CCArray *idleFrames = CCArray::createWithCapacity(6);
        for (i = 0; i < 6; i++) {
            CCString *str = CCString::createWithFormat("hero_idle_%02d.png", i);
            CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName((char*)str);
            idleFrames->addObject(frame);
        }
        
        CCAnimation *idleAnimation = CCAnimation::createWithSpriteFrames(idleFrames->create(), 1.0/12.0);
        //this->idleAction = CCRepeatForever::actionWithAction(CCAnimate::actionWithAnimation->idleAnimation));
        this->idleAction()->runAction(CCRepeatForever::create(CCAnimate::create(idleAnimation)));
        
        this->centerToBottom = 39.0;
        this->centerToSides = 29.0;
        this->hitPoints = 100.0;
        this->damage = 20.0;
        this->walkSpeed = 80;
    }
    return this;
}
