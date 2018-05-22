/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Cancellation policy types
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandCancellationPolicy) {
    /** Cancellation allowed */
    HereSDKDemandTripCancellationPolicyAllowed = 0,
    /** Cancellation not allowed */
    HereSDKDemandTripCancellationPolicyNotAllowed = 1,
};

/**
 The party responsible for the cancellation action.
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandCancellationInfoParty)
{
    /** Cancellation Party: Unknown */
    HereSDKDemandCancellationInfoPartyUnknown  = 0,
    /** Cancellation Party: Demander */
    HereSDKDemandCancellationInfoPartyDemander = 1,
    /** Cancellation Party: Supplier */
    HereSDKDemandCancellationInfoPartySupplier = 2,
};

/**
 The cancellation status.
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandCancellationStatus)
{
    /** Cancellation status: Unknown */
    HereSDKDemandCancellationStatusUnknown  = 0,
    /** Cancellation status: Processing */
    HereSDKDemandCancellationStatusProcessing,
    /** Cancellation status: Accepted */
    HereSDKDemandCancellationStatusAccepted,
    /** Cancellation status: Rejected */
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

/** The time the cancellation request arrived at the demand handler */
@property(nonatomic, readonly) NSDate * requestTime;

/** Status of cancellation */
@property(nonatomic, readonly) HereSDKDemandCancellationStatus cancellationStatus;

@end

NS_ASSUME_NONNULL_END
