//
//  File.h
//  PampaDroid
//
//  Created by shinriyo 13/02/10.
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
    Hero(void);
    ~Hero(void);

    CREATE_FUNC(Hero);
    bool init();
};

#endif /* defined(__PampaDroid__File__) */
