/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 A class for defining ride request constraints
 */
@interface HereSDKDemandBookingConstraints : NSObject

/** Passenger count (must be 1 or more) */
@property (nonatomic) unsigned int numberOfPassengers;

/** Suitcase count (0 or more) */
@property (nonatomic) unsigned int numberOfSuitcases;

@end
