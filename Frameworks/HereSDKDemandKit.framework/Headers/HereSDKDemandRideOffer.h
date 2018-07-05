/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKDemandKit/HereSDKDemandRoute.h>
#import <HereSDKDemandKit/HereSDKDemandPriceEstimate.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class representing a ride offer, returned in response to requestRide.
 */
@interface HereSDKDemandRideOffer : NSObject

/** The ride route */
@property (nonatomic, readonly) HereSDKDemandRoute *route;

/** Time estimate for pick up */
@property (nonatomic, readonly, nullable) NSDate *estimatedPickupTime;

/** Time estimate for drop off */
@property (nonatomic, readonly, nullable) NSDate *estimatedDropoffTime;

/** Price estimate for the ride */
@property (nonatomic, readonly, nullable) HereSDKDemandPriceEstimate *estimatedPrice;

/** The time the offer will expire */  // TODO : document
@property (nonatomic, readonly, nullable) NSNumber *duration;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
