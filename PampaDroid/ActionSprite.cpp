//
//  ActionSprite.cpp
//  PampaDroid
//
//  Created by shinriyo on 2/23/13.
//
//

#include "ActionSprite.h"

ActionSprite::ActionSprite(void)
{
    _idleAction = NULL;
    _attackAction = NULL;
    _walkAction = NULL;
    _hurtAction = NULL;
    _knockedOutAction = NULL;
}

void ActionSprite::idle()
{
   if (_actionState != kActionStateIdle) {
       this->stopAllActions();
       this->runAction(_idleAction);
       _actionState = kActionStateIdle;
       _velocity = CGPointZero;
   }
}
void ActionSprite::attack()
{
   if (_actionState == kActionStateIdle || _actionState == kActionStateAttack || _actionState == kActionStateWalk ) {
       this->stopAllActions();
       this->runAction(_attackAction);
       _actionState = kActionStateAttack;
   }
}