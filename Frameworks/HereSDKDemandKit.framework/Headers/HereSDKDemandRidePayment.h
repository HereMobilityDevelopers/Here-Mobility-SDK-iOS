/***************************************************************
 * Copyright © 2019 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

#import <HereSDKDemandKit/HereSDKDemandPaymentMethod.h>
#import <HereSDKDemandKit/HereSDKDemandCreditCard.h>
#import <HereSDKDemandKit/HereSDKDemandPrice.h>
#import <HereSDKDemandKit/HereSDKDemandFare.h>

/**
 Type definition for the payment status.
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandRidePaymentStatus) {
    /** the payment status is unknown */
    HereSDKDemandRidePaymentStatusUnknown = 0,

    /** before completion */
    HereSDKDemandRidePaymentStatusPending,

    /** when the payment is complete */
    HereSDKDemandRidePaymentStatusCompleted,

    /** when the ride, or payment, is cancelled */
    HereSDKDemandRidePaymentStatusCancelled,

    /** failure */
    HereSDKDemandRidePaymentStatusFailure,

};

NS_ASSUME_NONNULL_BEGIN

/**
 A class containing information about the status of a ride payment
 */
@interface HereSDKDemandRidePayment : NSObject

/** The status of the payment */
@property (nonatomic, readonly) HereSDKDemandRidePaymentStatus paymentStatus;

/** The payment method used for the ride payment */
@property (nullable, nonatomic, readonly) HereSDKDemandPaymentMethod *paymentMethod;

/** The final price of the ride */
@property (nullable, nonatomic, readonly) HereSDKDemandPrice *finalPrice;

/** Detailed fare information for the ride */
@property (nullable, nonatomic, readonly) HereSDKDemandFare *fare;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
