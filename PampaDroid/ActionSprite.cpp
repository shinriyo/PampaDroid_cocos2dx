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
   if (_actionState != kActionStateIdle)
   {
       this->stopAllActions();
       this->runAction(_idleAction);
       _actionState = kActionStateIdle;
       setVelocity(CCPointZero);
   }
}

void ActionSprite::attack()
{
   if (_actionState == kActionStateIdle || _actionState == kActionStateAttack || _actionState == kActionStateWalk )
   {
       this->stopAllActions();
       this->runAction(_attackAction);
       _actionState = kActionStateAttack;
   }
}

void ActionSprite::walkWithDirection(cocos2d::CCPoint direction)
{
    if (_actionState == kActionStateIdle)
    {
        this->stopAllActions();
        this->runAction(_walkAction);
        _actionState = kActionStateWalk;
    }
    if (_actionState == kActionStateWalk)
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

void ActionSprite::update(float dt)
{
    if (_actionState == kActionStateWalk)
    {
        _desiredPosition = ccpAdd(this->getPosition(), ccpMult(_velocity, dt));
    }
}
