/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import "HereSDKDemandPassenger.h"

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

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a ride request

 @param offerId The ride offer ID received from requestRide
 @param passengerDetails Details about the passenger booking the ride
 */
+(instancetype)rideRequestWithOfferId:(NSString *)offerId passengerDetails:(HereSDKDemandPassenger *)passengerDetails;

@end

NS_ASSUME_NONNULL_END
