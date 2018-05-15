/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

#import <HereSDKDemandKit/HereSDKDemandRide.h>
#import <HereSDKDemandKit/HereSDKDemandRideLocation.h>

/**
 Class for receiving ride status updates.
 The ride status is stored in ride.statusLog.currentStatus.
 */
@protocol HereSDKDemandRidesUpdatesDelegate <NSObject>

/**
 Called when a ride status is updated.

 @param statusLog The status log of the ride (including the current status)
 @param ride The ride updated
 */
- (void)didReceiveUpdate:(HereSDKDemandRideStatusLog *)statusLog forRide:(HereSDKDemandRide *)ride;

/**
 Called when the ride location is updated.

 @param location The current location of the ride
 @param ride The ride updated
 */
- (void)didReceiveLocation:(HereSDKDemandRideLocation *)location forRide:(HereSDKDemandRide *)ride;

@optional
/**
 Called when a ride update request failed.

 @param error The error that occurred
 */
- (void)didReceiveUpdateError:(NSError *)error;

@end


