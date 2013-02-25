//
//  Defines.h
//  PampaDroid
//
//  Created by shinriyo on 13/02/09.
//
//
#pragma once
#ifndef PampaDroid_Defines_h
#define PampaDroid_Defines_h

#import <QuartzCore/QuartzCore.h>
// 1 - convenience measurements
#define SCREEN [[CCDirector sharedDirector] winSize]
#define CENTER ccp(SCREEN.width/2, SCREEN.height/2)
#define CURTIME do {                                                        \
    timeval time;                                                           \
    gettimeofday(&time, NULL);                                              \
    unsigned long millisecs = (time.tv_sec * 1000) + (time.tv_usec / 1000); \
    return (float)millisecs;                                                \
} while (0)

// 2 - convenience functions
#define random_range(low, high) (rand() % (high - low + 1)) + low
#define frandom (float)rand() / UINT64_C(0x100000000)
#define frandom_range(low, high) ((high - low) * frandom) + low

// 3 - enumerations
typedef enum _ActionState {
    kActionStateNone = 0,
    kActionStateIdle,
    kActionStateAttack,
    kActionStateWalk,
    kActionStateHurt,
    kActionStateKnockedOut
} ActionState;

// 4 - structures
typedef struct _BoundingBox {
    CGRect actual;
    CGRect original;
} BoundingBox;

#endif
