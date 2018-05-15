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



/**
 A class representing a ride from a specific supplier.
 Contains relatively static info: driver, vehicle, passengers etc.
 */
@interface HereSDKDemandRide : NSObject

/** The unique ride ID */
@property (nonatomic, readonly) NSString *rideId;

/** The ride's route */
@property (nonatomic, readonly) HereSDKDemandRoute *route;

/** The requested pickup time, for a pre-booked ride */
@property (nonatomic, readonly) NSDate *prebookPickupTime;

/** Price at the time of booking */
@property (nonatomic, readonly) HereSDKDemandPriceEstimate *bookingEstimatedPrice;

/** Constraints at the time of booking */
@property (nonatomic, readonly) HereSDKDemandBookingConstraints *constraints;

/** Ride's current status, and status history */
@property (nonatomic, readonly) HereSDKDemandRideStatusLog *statusLog;

/** Supplier details */
@property (nonatomic, readonly) HereSDKDemandSupplier *supplier;

/** The (optional) passenger note at the time of ride creation */
@property (nonatomic, readonly) HereSDKDemandPassenger *passenger;

/** The passenger note at the time of ride creation */
@property (nonatomic, readonly) NSString *passengerNote;

/** Driver details. Empty until the ride status becomes "DRIVER_ASSIGNED". */
@property (nonatomic, readonly) HereSDKDemandDriver *driver;

/** The ride vehicle. Empty until the ride status becomes "DRIVER_ASSIGNED". */
@property (nonatomic, readonly) HereSDKDemandVehicle *vehicle;

/** Cancellation policy for the ride */
@property (nonatomic, readonly) HereSDKDemandCancellationPolicy cancellationPolicy;

/** When a cancellation occurs, contains info about the cancellation */
@property (nonatomic, readonly) HereSDKDemandCancellationInfo *cancellationInfo;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end
