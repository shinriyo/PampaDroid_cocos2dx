//
//  ActionSprite.cpp
//  PampaDroid
//
//  Created by shinriyo on 2/23/13.
//
//

#include "ActionSprite.h"

void ActionSprite::idle()
{
   if (_actionState != kActionStateIdle) {
       this->stopAllActions();
       this->runAction(idleAction);
       _actionState = kActionStateIdle;
       _velocity = CGPointZero;
   }
}
void ActionSprite::attack()
{
   if (_actionState == kActionStateIdle || _actionState == kActionStateAttack || _actionState == kActionStateWalk ) {
       this->stopAllActions();
       this->runAction(attackAction);
       _actionState = kActionStateAttack;
   }
}