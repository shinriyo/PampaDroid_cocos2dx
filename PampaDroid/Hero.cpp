//
//  File.cpp
//  PampaDroid
//
//  Created by sugita on 13/02/10.
//
//

#include "Hero.h"


bool Hero::init()
{
    if ((this = __super.initWithSpriteFrameName:@"hero_idle_00.png"])) {
        int i;
        
        //idle animation
        CCArray *idleFrames = CCArray::arrayWithCapacity(6);
        for (i = 0; i < 6; i++) {
            CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache
            (spriteFrameByName:NSString::stringWithFormat("hero_idle_%02d.png", i));
            idleFrames->addObject(frame);
        }
        CCAnimation *idleAnimation = CCAnimation::animationWithSpriteFrames(idleFrames->getNSArray(1.0/12.0);
        this.idleAction = CCRepeatForever::actionWithAction(CCAnimate::actionWithAnimation->idleAnimation]);
        
        this.centerToBottom = 39.0;
        this.centerToSides = 29.0;
        this.hitPoints = 100.0;
        this.damage = 20.0;
        this.walkSpeed = 80;
    }
    return self;
}
