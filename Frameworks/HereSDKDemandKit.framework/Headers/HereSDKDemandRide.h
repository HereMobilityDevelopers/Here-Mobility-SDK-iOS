/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKDemandKit/HereSDKDemandRoute.h>
#import <HereSDKDemandKit/HereSDKDemandDriver.h>
#import <HereSDKDemandKit/HereSDKDemandVehicle.h>
#import <HereSDKDemandKit/HereSDKDemandPriceEstimate.h>
#import <HereSDKDemandKit/HereSDKDemandBookingConstraints.h>
#import <HereSDKDemandKit/HereSDKDemandRideStatusLog.h>
#import <HereSDKDemandKit/HereSDKDemandSupplier.h>
#import <HereSDKDemandKit/HereSDKDemandPassenger.h>
#import <HereSDKDemandKit/HereSDKDemandCancellationInfo.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class representing a ride from a specific supplier.
 Contains relatively static info: driver, vehicle, passengers etc.
 */
@interface HereSDKDemandRide : NSObject

/** user ID of the user who ordered the ride */
@property (nonatomic, readonly) NSString *userId;

/** The unique ride ID */
@property (nonatomic, readonly) NSString *rideId;

/** The ride's route */
@property (nonatomic, readonly) HereSDKDemandRoute *route;

/** The prebook pickup time. nil of no time was given in the offers request */
@property (nonatomic, readonly, nullable) NSDate *prebookPickupTime;

/** Price at the time of booking (if applicable) */
@property (nonatomic, readonly, nullable) HereSDKDemandPriceEstimate *bookingEstimatedPrice;

/** Constraints at the time of booking */
@property (nonatomic, readonly) HereSDKDemandBookingConstraints *constraints;

/** Ride's current status, and status history */
@property (nonatomic, readonly) HereSDKDemandRideStatusLog *statusLog;

/** Supplier details, nil if no supplier was assigned */
@property (nonatomic, readonly, nullable) HereSDKDemandSupplier *supplier;

/** The (optional) passenger note at the time of ride creation */
@property (nonatomic, readonly) HereSDKDemandPassenger *passenger;

/** The passenger note at the time of ride creation */
@property (nonatomic, readonly, nullable) NSString *passengerNote;

/** Driver details. Empty until the ride status becomes "DRIVER_ASSIGNED". */
@property (nonatomic, readonly, nullable) HereSDKDemandDriver *driver;

/** The ride vehicle. Empty until the ride status becomes "DRIVER_ASSIGNED". */
@property (nonatomic, readonly, nullable) HereSDKDemandVehicle *vehicle;

/** Cancellation policy for the ride */
@property (nonatomic, readonly) HereSDKDemandCancellationPolicy cancellationPolicy;

/** When a cancellation occurs, contains info about the cancellation */
@property (nonatomic, readonly, nullable) HereSDKDemandCancellationInfo *cancellationInfo;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

