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

@class HereSDKDemandPrice;

NS_ASSUME_NONNULL_BEGIN

/**
 A class representing a ride from a specific supplier.
 Contains relatively static info: driver, vehicle, passengers etc.
 */
@interface HereSDKDemandRide : NSObject

/** The ID of the user who ordered the ride */
@property (nonatomic, readonly) NSString *userId;

/** The unique ride ID */
@property (nonatomic, readonly) NSString *rideId;

/** The ride's route */
@property (nonatomic, readonly) HereSDKDemandRoute *route;

/** The pre-booked pickup time. Nil if no time was given in the request (meaning that the request is for an immediate ride) */
@property (nonatomic, readonly, nullable) NSDate *prebookPickupTime;

/** Price at the time of booking (if applicable) */
@property (nonatomic, readonly, nullable) HereSDKDemandPriceEstimate *bookingEstimatedPrice;

/** Constraints at the time of booking */
@property (nonatomic, readonly) HereSDKDemandBookingConstraints *constraints;

/** Ride's current status, and status history */
@property (nonatomic, readonly) HereSDKDemandRideStatusLog *statusLog;

/** Supplier details */
@property (nonatomic, readonly) HereSDKDemandSupplier *supplier;

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

/**
 The price of the ride updated by the supplier.
 This may be updated around the time of the ride's end, when the ride's duration and final price can be known.
 */
@property (nonatomic, readonly, nullable) HereSDKDemandPrice *price;

/**
 This is the actual point where the driver will arrive to pick up the passenger.
 This may be adjusted slightly in relation to the address that the passenger entered, 
 to ensure that the vehicle can access this location.
 Display this location rather than the user-defined address, 
 because the confirmed pickup point is where the driver will arrive.
 */
@property (nonatomic, readonly) CLLocation *confirmedPickupPoint;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

