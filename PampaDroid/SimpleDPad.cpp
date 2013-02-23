//
//  SimpleDPad.cpp
//  PampaDroid
//
//  Created by shinriyo on 2/23/13.
//
//

#include "SimpleDPad.h"

//add inside the @implementation
SimpleDPad::dPadWithFile(cocos2d::CCString* fileName, float radius)
{
    return initWithFile->fileName(radius);
}

SimpleDPad::initWithFile(cocos2d::CCString* filename, float radius)
{
    if ( !CGLayer:init() )
	{
        _radius = radius;
        _direction = CGPointZero;
        _isHeld = NO;
        this->scheduleUpdate;
    }
    return self;
}

void　onEnterTransitionDidFinish
{
    CCDirector::sharedDirector->touchDispatcher(this, 1, true);
}

void onExit()
{
    CCDirector::sharedDirector->removeDelegate(this);
}

void update(ccTime dt)
{
    if (_isHeld) {
        _delegate->simpleDPad(this, _direction);
    }
}

bool ccTouchBegan(UITouch* touch, UIEvent* event)
{
    CGPoint location = CCDirector::sharedDirector->convertToGL(touch->locationInView(touch->view)));
    
    float distanceSQ = ccpDistanceSQ(location, position_);
    if (distanceSQ <= _radius * _radius) {
        //get angle 8 directions
        this->pdateDirectionForTouchLocation(location);
        _isHeld = true;
        return true;
    }
    return false;
}


void ccTouchMoved(UITouch* touch, UIEvent* event)
{
    CGPoint location = CCDirector::sharedDirector->convertToGL(touch->locationInView(touch->view)));
    this->updateDirectionForTouchLocation9location);
}

void ccTouchEnded(UITouch* touch, UIEvent* event)
{
    _direction = CGPointZero;
    _isHeld = false;
    _delegate->simpleDPadTouchEnded(this);
}

void updateDirectionForTouchLocation(CGPoint location)
{
    float radians = ccpToAngle(ccpSub(location, position_));
    float degrees = -1 * CC_RADIANS_TO_DEGREES(radians);
    
    if (degrees <= 22.5 && degrees >= -22.5) {
        //right
        _direction = ccp(1.0, 0.0);
    } else if (degrees > 22.5 && degrees < 67.5) {
        //bottomright
        _direction = ccp(1.0, -1.0);
    } else if (degrees >= 67.5 && degrees <= 112.5) {
        //bottom
        _direction = ccp(0.0, -1.0);
    } else if (degrees > 112.5 && degrees < 157.5) {
        //bottomleft
        _direction = ccp(-1.0, -1.0);
    } else if (degrees >= 157.5 || degrees <= -157.5) {
        //left
        _direction = ccp(-1.0, 0.0);
    } else if (degrees < -22.5 && degrees > -67.5) {
        //topright
        _direction = ccp(1.0, 1.0);
    } else if (degrees <= -67.5 && degrees >= -112.5) {
        //top
        _direction = ccp(0.0, 1.0);
    } else if (degrees < -112.5 && degrees > -157.5) {
        //topleft
        _direction = ccp(-1.0, 1.0);
    }
    _delegate->simpleDPad(this->didChangeDirectionTo(_direction));
}
