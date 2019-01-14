/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class containing information about the vehicle's progress. Updated every ~10 seconds.
 */
@interface HereSDKDemandRideLocation : NSObject

/** A unique ride id */
@property (nonatomic, readonly) NSString *rideId;

/** The current location of the vehicle. null if not available */
@property (nonatomic, readonly, nullable) CLLocation *vehicleLocation;

/** The estimated time of pickup. Constantly updated until the vehicle is at the pickup location. */
@property (nonatomic, readonly, nullable) NSDate *estimatedPickupTime DEPRECATED_MSG_ATTRIBUTE("This property is deprecated, please use estimatedPickupTimeSeconds instead to avoid timezone differences issues.");

/** The estimated time of dropoff. Constantly updated until the vehicle is at the dropoff location. */
@property (nonatomic, readonly, nullable) NSDate *estimatedDropoffTime DEPRECATED_MSG_ATTRIBUTE("This property is deprecated, please use estimatedDropOffTimeSeconds instead to avoid timezone differences issues.");

/** Last time this object was updated. Used for tracking updates. */
@property (nonatomic, readonly) NSDate *lastUpdateTime;

/**
 Estimated pickup time, if available, in seconds, relative to now.
 Received from supplier or calculated according to vehicle GPS location(consider traffic and optimal route). Null if can't calculate.
 If the passenger was already picked up, will return 0.
 */
@property (nonatomic, readonly, nullable) NSNumber *estimatedPickupTimeSeconds;

/**
 Estimated drop-off time, if available, in seconds, relative to now.
 If the vehicle already arrived, will return 0.
 */
@property (nonatomic, readonly, nullable) NSNumber *estimatedDropOffTimeSeconds;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

