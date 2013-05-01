//
//  cubeAccelerationActions.h
//  ShakeBreaker
//
//  Created by Jan Brond on 6/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "cubeAction.h"

//State of the acceleration detection
typedef enum { accelStateIdle, accelStateThrow, accelStateHit, accelStateShake, accelStateWait} accelerationState;

//defined as 0=undefined 1 2 3 4 5 6 means you can just cast the enum to int
//then you have the correct number
typedef enum { unDefined, landscapeSteepRight, portraitStable, faceUp, faceDown, portraitBalance,landscapeSteepLeft  } instantOrientation;

@interface cubeAccelerationEngine : NSObject {
    
    //holds the buffer of 5 previous data points
    double buffer[5];
    double vm; //Current vector magnitude
    UIAcceleration * currentAcceleration;
    //on set of edge detection
    BOOL onSetDetection;
    long onsetTime;
    Boolean edgeDetected;
    long previousOffsetTime;
    long airTime;
    long duration;
    int shakes;
    accelerationState accelState;
    int waitTime;
}

-(cubeAccelerationEngine*) init;
-(eCubeAction) process: (UIAcceleration *)acceleration;
-(void) setDeviceOrientationChanged: (int)orientation;
-(long) getCubeActionTime;
-(int) getShakes;
-(long) getDuration;
-(long) getAirTime;
-(instantOrientation) getInstantOrientation;
@end
