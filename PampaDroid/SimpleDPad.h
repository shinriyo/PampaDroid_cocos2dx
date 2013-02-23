//
//  SimpleDPad.h
//  PampaDroid
//
//  Created by shinriyo on 2/23/13.
//
//

#ifndef __PampaDroid__SimpleDPad__
#define __PampaDroid__SimpleDPad__

#include <iostream>
#include "cocos2d.h"
#include "Defines.h"
// http://article.ityran.com/archives/2847

class SimpleDPad : public cocos2d::CCObject
{
public:
    
    //add right after the @interface SimpleDPad : CCSprite and before the opening curly bracket
//    <CCTargetedTouchDelegate>
    
    
    //add after closing curly bracket but before the @end
    //id <SimpleDPadDelegate> delegate;
    
    int dPadWithFile(cocos2d::CCString* filename, float radius);
private:
    CGPoint _direction;
    //add inside the @interface within the curly brackets
    float _radius;
    bool _isHeld;
    int initWithFile(cocos2d::CCString* filename, float radius);
};

class SimpleDPadDelegate : public cocos2d::CCTouchDelegate
{
public:
    SimpleDPadDelegate() {};
    ~SimpleDPadDelegate() {};
    void simpleDPad(SimpleDPad *simpleDPad, CGPoint direction);
//    void simpleDPad(SimpleDPad *simpleDPad, CGPoint direction);
    void simpleDPadTouchEnded(SimpleDPad *simpleDPad);
};
#endif /* defined(__PampaDroid__SimpleDPad__) */
