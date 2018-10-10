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
    /** Cancellation status: Rejected. This means that whether or not the ride takes place, the user will be charged. */
    HereSDKDemandCancellationStatusRejected,
};

/**
  The cancel reason category. Some reasons are relevant only to passenger cancellations,
  and some are relevant only to supplier cancellations.
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandCancellationReasonCategory)
{
    /** Passenger cancellation, driver didn't arrive. */
    HereSDKDemandCancellationReasonCategoryDriverNoShow,
    /** Passenger cancellation, price changed. */
    HereSDKDemandCancellationReasonCategoryPriceChanged,
    /** Passenger cancellation, ETA changed. */
    HereSDKDemandCancellationReasonCategoryEtaChanged,
    /** Passenger cancellation, vehicle unsuitable for passenger's needs. */
    HereSDKDemandCancellationReasonCategoryUnsuitableVehicle,
    /** Passenger cancellation, driver behaved inappropriately. */
    HereSDKDemandCancellationReasonCategoryDriverBehavedInappropriately,
    /** Passenger cancellation, passenger plans changed. */
    HereSDKDemandCancellationReasonCategoryChangedMyPlans,
    /** Supplier cancellation. No drivers available. */
    HereSDKDemandCancellationReasonCategoryDriversUnavailable,
    /** Supplier cancellation. Passenger didn't arrive. */
    HereSDKDemandCancellationReasonCategoryPassengerNoShow,
    /** Supplier cancellation. Passenger called the driver and asked to cancel the ride. */
    HereSDKDemandCancellationReasonCategoryPassengerRequestedToCancel,
    /** Supplier cancellation. Vehicle malfunction. */
    HereSDKDemandCancellationReasonCategoryVehicleMalfunction,
    /** Supplier cancellation. Driver couldn't arrive due to heavy traffic. */
    HereSDKDemandCancellationReasonCategoryHeavyTraffic,
    /** Other cancellation reason. */
    HereSDKDemandCancellationReasonCategoryOther,
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

/** The cancellation reason category. */
@property(nonatomic, readonly) HereSDKDemandCancellationReasonCategory cancellationReasonCategory;

@end

NS_ASSUME_NONNULL_END
