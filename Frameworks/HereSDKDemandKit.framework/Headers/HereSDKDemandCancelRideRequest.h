/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Passenger cancel reasons.
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandPassengerCancelReason) {
    /** Driver did not show up. */
    HereSDKDemandPassengerCancelReasonDriverNoShow,
    /** Ride price changed. */
    HereSDKDemandPassengerCancelReasonPriceChanged,
    /** Ride ETA changed. */
    HereSDKDemandPassengerCancelReasonEtaChanged,
    /** Ride vehicle is not suitable. */
    HereSDKDemandPassengerCancelReasonUnsuitableVehicle,
    /** Driver behaved inappropriately. */
    HereSDKDemandPassengerCancelReasonDriverBehavedInappropriately,
    /** Passenger changed plans. */
    HereSDKDemandPassengerCancelReasonChangedMyPlans,
    /**
     Other passenger cancel reason.
     Suggestion when the passenger selected other use free text reason property.
     */
    HereSDKDemandPassengerCancelReasonOther,
};

NS_ASSUME_NONNULL_BEGIN

/**
 A Class for cancelling a ride request.
 */
@interface HereSDKDemandCancelRideRequest : NSObject

/**
 The ID of the ride to be cancelled.
 */
@property (nonatomic, readonly) NSString *rideId;

/** Passenger cancel reason. */
@property (nonatomic, readonly) HereSDKDemandPassengerCancelReason passengerCancelReason;

/**
 The cancellation reason.
 */
@property (nonatomic, readonly, nullable) NSString *cancelReason;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a ride cancellation request

 @param rideId The ID of the ride to be cancelled
 @param cancelReason The cancellation reason
 */
+ (instancetype)cancelRideWithRideId:(NSString *)rideId cancelReason:(NSString *_Nullable)cancelReason;

/**
 Creates a ride cancellation request

 @param rideId The ID of the ride to be cancelled
 @param passengerCancelReason The passenger cancellation reason
 @param cancelReason The cancellation reason
 */
+ (instancetype)cancelRideWithRideId:(NSString *)rideId
              passengerCancelReason:(HereSDKDemandPassengerCancelReason)passengerCancelReason
                       cancelReason:(NSString *_Nullable)cancelReason;

@end

NS_ASSUME_NONNULL_END
