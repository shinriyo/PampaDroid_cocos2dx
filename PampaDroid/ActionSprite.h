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

    //actions
    static cocos2d::CCScene* idleAction();
    static cocos2d::CCScene* attackAction();
    static cocos2d::CCScene* walkAction();
    static cocos2d::CCScene* hurtAction();
    static cocos2d::CCScene* knockedOutAction();

    //states
    _ActionState actionState;

    //attributes
    float walkSpeed;
    float hitPoints;
    float damage;

    //movement
    CGPoint velocity;
    CGPoint desiredPosition;

    // measurements
    float centerToSides;
    float centerToBottom;

    // action methods
    void idle();
    void attack();
    void hurtWithDamage(float damage);
    void knockout();
    void walkWithDirection(CGPoint direction);

    // scheduled methods
    void update(cocos2d::CCTime dt);
};

#endif
