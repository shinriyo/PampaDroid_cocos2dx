//
//  HudLayer.h
//  PampaDroid
//
//  Created by shinriyo on 12/12/22.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.

#ifndef __HudLayer_H__
#define __HudLayer_H__ 

#include "cocos2d.h"

class HudLayer : public cocos2d::CCLayer
{
public:
    ~HudLayer();
    virtual bool init();  
    
    // implement the "static node()" method manually
    // LAYER_NODE_FUNC does not exist in version2.x
    // LAYER_NODE_FUNC(HudLayer);
	CREATE_FUNC(HudLayer);
};

#endif // __HudLayerH__