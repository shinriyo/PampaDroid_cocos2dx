//
//  ActionSprite.cpp
//  PampaDroid
//
//  Created by shinriyo on 2/23/13.
//
//

#include "ActionSprite.h"
using namespace cocos2d;

ActionSprite::ActionSprite(void)
{
    _idleAction = NULL;
    _attackAction = NULL;
    _walkAction = NULL;
    _hurtAction = NULL;
    _knockedOutAction = NULL;
}

ActionSprite::~ActionSprite(void)
{
}

void ActionSprite::idle()
{
   if (getActionState() != kActionStateIdle)
   {
       this->stopAllActions();
       this->runAction(_idleAction);
       setActionState(kActionStateIdle);
       setVelocity(CCPointZero);
   }
}

void ActionSprite::attack()
{
   if (getActionState() == kActionStateIdle || getActionState() == kActionStateAttack || getActionState() == kActionStateWalk )
   {
       this->stopAllActions();
       this->runAction(_attackAction);
       setActionState(kActionStateAttack);
   }
}

void ActionSprite::walkWithDirection(cocos2d::CCPoint direction)
{
    if (getActionState() == kActionStateIdle)
    {
        this->stopAllActions();
        this->runAction(_walkAction);
        setActionState(kActionStateWalk);
    }
    if (getActionState() == kActionStateWalk)
    {
        setVelocity(ccp(direction.x * _walkSpeed, direction.y * _walkSpeed));
        if (getVelocity().x >= 0)
        {
            this->setScaleX(1.0);
        }
        else
        {
            this->setScaleX(-1.0);
        }
    }
}
/*
void ActionSprite::update(CCTime dt)
{
    if (_actionState == kActionStateWalk)
    {
        _desiredPosition = ccpAdd(this->getPosition(), ccpMult(_velocity, dt));
    }
}
*/