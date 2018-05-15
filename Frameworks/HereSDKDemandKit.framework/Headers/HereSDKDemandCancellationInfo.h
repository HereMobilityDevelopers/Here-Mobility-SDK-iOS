/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Cancellation policy types:
 - HereSDKDemandTripCancellationPolicyUnknown:    type policy unknown
 - HereSDKDemandTripCancellationPolicyAllowed:    type cancellation allowed
 - HereSDKDemandTripCancellationPolicyNotAllowed: type cancellation not allowed
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandCancellationPolicy) {
    HereSDKDemandTripCancellationPolicyAllowed = 0,
    HereSDKDemandTripCancellationPolicyNotAllowed = 1,
};

/**
 The party responsible for the cancellation action.
 - HereSDKDemandCancellationInfoPartUnknown:  type unknown
 - HereSDKDemandCancellationInfoPartDemander: type demander
 - HereSDKDemandCancellationInfoPartSupplier: type supplier
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandCancellationInfoParty)
{
    HereSDKDemandCancellationInfoPartUnknown  = 0,
    HereSDKDemandCancellationInfoPartDemander = 1,
    HereSDKDemandCancellationInfoPartSupplier = 2,
};

/**
 The cancellation status.
 - HereSDKDemandCancellationStatusUnknown:  type unknown
 - HereSDKDemandCancellationStatusProcessing: type processing
 - HereSDKDemandCancellationStatusAccepted: type accepted
 - HereSDKDemandCancellationStatusRejected: type rejected
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandCancellationStatus)
{
    HereSDKDemandCancellationStatusUnknown  = 0,
    HereSDKDemandCancellationStatusProcessing,
    HereSDKDemandCancellationStatusAccepted,
    HereSDKDemandCancellationStatusRejected,
};

NS_ASSUME_NONNULL_BEGIN

/**
 A class representing information about a ride cancellation.
 */
@interface HereSDKDemandCancellationInfo : NSObject

/** Who cancelled the ride (demander / supplier) */
@property(nonatomic, readonly) HereSDKDemandCancellationInfoParty cancellingParty;

/** The reason for the cancellation (textual description) */
@property(nonatomic, readonly) NSString *cancelReason;

/** Request time at demand handler */
@property(nonatomic, readonly) NSDate * requestTime;

/** status of cancellation */
@property(nonatomic, readonly) HereSDKDemandCancellationStatus cancellationStatus;

@end

NS_ASSUME_NONNULL_END
