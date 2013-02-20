//
//  File.h
//  PampaDroid
//
//  Created by sugita on 13/02/10.
//
//

#ifndef __PampaDroid__File__
#define __PampaDroid__File__

#include <iostream>
#import "ActionSprite.h"
#include "cocos2d.h"

class Hero : public ActionSprite
{
public:
    virtual bool init();
    CREATE_FUNC(CCSprite);
};

#endif /* defined(__PampaDroid__File__) */
