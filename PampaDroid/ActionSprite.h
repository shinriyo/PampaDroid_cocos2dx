//
//  ActionSprite.h
//  PampaDroid
//
//  Created by sugita on 13/02/09.
//
//

#ifndef PampaDroid_ActionSprite_h
#define PampaDroid_ActionSprite_h
#import <QuartzCore/QuartzCore.h>
#include "cocos2d.h"
#include "Defines.h"

class ActionSprite : public cocos2d::CCSprite
{
public:

    // actions
    static cocos2d::CCAction* idleAction;
    static cocos2d::CCAction* attackAction;
    static cocos2d::CCAction* walkAction;
    static cocos2d::CCAction* hurtAction;
    static cocos2d::CCAction* knockedOutAction;

    // states
    _ActionState _actionState;

    //attributes
    float walkSpeed;
    float hitPoints;
    float damage;
    

    // measurements
    float centerToSides;
    float centerToBottom;
    
    // action methods
    void idle();
    void attack();
    void hurtWithDamage(float damage);
    void knockout();
    void walkWithDirection(CGPoint direction);

private:
    
    // movement
    CGPoint _velocity;
    CGPoint _desiredPosition;


    // scheduled methods
    void update(cocos2d::CCTime dt);
};

#endif
