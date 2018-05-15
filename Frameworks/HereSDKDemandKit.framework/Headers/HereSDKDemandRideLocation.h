//
 /***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 A class containing information about the vehicle's progress. Updated every ~10 seconds.
 */
@interface HereSDKDemandRideLocation : NSObject

/** A unique ride id */
@property (nonatomic, readonly) NSString *rideId;

/** The current location of the vehicle */
@property (nonatomic, readonly) CLLocation *vehicleLocation;

/** The estimated time of pickup. Constantly updated until the vehicle is at the pickup location. */
@property (nonatomic, readonly) NSDate *estimatedPickupTime;

/** The estimated time of dropoff. Constantly updated until the vehicle is at the dropoff location. */
@property (nonatomic, readonly) NSDate *estimatedDropoffTime;

/** Last time this object was updated. Used for tracking updates. */
@property (nonatomic, readonly) NSDate *lastUpdateTime;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end
