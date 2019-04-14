/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

#import <HereSDKDemandKit/HereSDKDemandRideOffer.h>
#import <HereSDKDemandKit/HereSDKDemandSupplier.h>
#import <HereSDKDemandKit/HereSDKDemandCancellationInfo.h>
#import <HereSDKDemandKit/HereSDKDemandRideOfferProtocol.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class representing a taxi ride offer, returned in response to requestRide.
 */
@interface HereSDKDemandTaxiRideOffer : HereSDKDemandRideOffer <HereSDKDemandRideOfferProtocol>

/** The requested route. May be different from the ride route. */
@property (nonatomic, readonly) HereSDKDemandRoute *requestedRoute;

/** The offer identifier */
@property (nonatomic, readonly) NSString *offerId;

/** Information about the supplier of that offer */
@property (nonatomic, readonly) HereSDKDemandSupplier *supplier;

/** The offer will expire at that time */
@property (nonatomic, readonly) NSDate *offerExpirationTime;

/** The cancellation policy of that offer. (allowed/not allowed) */
@property (nonatomic, readonly) HereSDKDemandCancellationPolicy cancellationPolicy;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
