/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

@class HereSDKDemandRidePreferences, HereSDKDemandPassenger, HereSDKDemandTaxiRideOffer, HereSDKDemandPaymentMethod;

NS_ASSUME_NONNULL_BEGIN

/**
 A request to book a ride by ride offer ID
 */
@interface HereSDKDemandRideRequest : NSObject

/**
 The ride offer ID received from requestRide
 */
@property (nonatomic, readonly) NSString *offerId;

/**
 Details about the passenger booking the ride (name, phone number, photo URL)
 */
@property (nonatomic) HereSDKDemandPassenger *passengerDetails;

/**
 The preferences of a ride.
 */
@property (nonatomic, null_resettable) HereSDKDemandRidePreferences *ridePreferences;

/**
 The payment method of the ride. Must be provided for online payment rides.
 */
@property (nonatomic, nullable) HereSDKDemandPaymentMethod *paymentMethod;

/**
 Creates a ride request

 @param offer The ride offer received from requestRide
 @param passengerDetails Details about the passenger booking the ride
 */
+ (instancetype)rideRequestWithOffer:(HereSDKDemandTaxiRideOffer *)offer
                    passengerDetails:(HereSDKDemandPassenger *)passengerDetails;

/**
 Creates a ride request

 @param offerId The ride offer ID received from requestRide
 @param passengerDetails Details about the passenger booking the ride
 */
+ (instancetype)rideRequestWithOfferId:(NSString *)offerId
                      passengerDetails:(HereSDKDemandPassenger *)passengerDetails  DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use `+rideRequestWithOffer:passengerDetails:` instead.");

/**
 Creates a ride request

 @param offerId The ride offer ID received from requestRide
 @param passengerDetails Details about the passenger booking the ride
 @param ridePreferences The preferences of a ride. If not specified, will be determined by the settings in the developer portal
 */
+ (instancetype)rideRequestWithOfferId:(NSString *)offerId
                      passengerDetails:(HereSDKDemandPassenger *)passengerDetails
                       ridePreferences:(HereSDKDemandRidePreferences *_Nullable) ridePreferences  DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use `+rideOffersRequestWithRoute:` instead.");

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
