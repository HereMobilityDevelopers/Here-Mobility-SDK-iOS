/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import "HereSDKDemandPassenger.h"

@class HereSDKDemandRidePreferences;

NS_ASSUME_NONNULL_BEGIN

/**
 A request to book a ride by ride offer ID
 */
@interface HereSDKDemandRideRequest : NSObject

/**
 The ride offer ID received from requestRide
 */
@property(nonatomic, readonly) NSString *offerId;

/**
 Details about the passenger booking the ride (name, phone number, photo URL)
 */
@property(nonatomic, readonly) HereSDKDemandPassenger *passengerDetails;

/**
 The preferences of a ride.
 */
@property(nonatomic, readonly) HereSDKDemandRidePreferences *ridePreferences;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a ride request
 
 @param offerId The ride offer ID received from requestRide
 @param passengerDetails Details about the passenger booking the ride
 */
+ (instancetype)rideRequestWithOfferId:(NSString *)offerId passengerDetails:(HereSDKDemandPassenger *)passengerDetails;

/**
 Creates a ride request
 
 @param offerId The ride offer ID received from requestRide
 @param passengerDetails Details about the passenger booking the ride
 @param ridePreferences The preferences of a ride.
 */
+ (instancetype)rideRequestWithOfferId:(NSString *)offerId passengerDetails:(HereSDKDemandPassenger *)passengerDetails ridePreferences:(HereSDKDemandRidePreferences *) ridePreferences;

@end

NS_ASSUME_NONNULL_END
