/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Type definition for ride statuses

 - HereSDKDemandRideStatusLogRecordUnknown: Unknown
 - HereSDKDemandRideStatusLogRecordProcessing: The request is being processed, looking for a supplier.
 - HereSDKDemandRideStatusLogRecordRejected: None of the suppliers accepted the offer. No driver was assigned.
 - HereSDKDemandRideStatusLogRecordAccepted: A supplier accepted the ride, no driver was assigned yet.
 - HereSDKDemandRideStatusLogRecordDriverAssigned: A driver was assigned to the ride.
 - HereSDKDemandRideStatusLogRecordDriverEnRoute: The vehicle is on the way to the pickup point.
 - HereSDKDemandRideStatusLogRecordDriverAtPickup: The vehicle is waiting at the pickup point.
 - HereSDKDemandRideStatusLogRecordPassengerOnBoard: The vehicle is on the way to the drop-off point.
 - HereSDKDemandRideStatusLogRecordDriverAtDropoff: The vehicle arrived at the drop-off point.
 - HereSDKDemandRideStatusLogRecordDriverCompleted: The ride was completed.
 - HereSDKDemandRideStatusLogRecordDriverCancelled: The ride was cancelled (either by the driver or by the passenger).
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandRideStatusUpdateStatus)
{
    HereSDKDemandRideStatusLogRecordUnknown = 0,
    HereSDKDemandRideStatusLogRecordProcessing = 1,
    HereSDKDemandRideStatusLogRecordRejected = 2,
    HereSDKDemandRideStatusLogRecordAccepted = 3,
    HereSDKDemandRideStatusLogRecordDriverAssigned = 4,
    HereSDKDemandRideStatusLogRecordDriverEnRoute = 5,
    HereSDKDemandRideStatusLogRecordDriverAtPickup = 6,
    HereSDKDemandRideStatusLogRecordPassengerOnBoard = 7,
    HereSDKDemandRideStatusLogRecordDriverAtDropoff = 8,
    HereSDKDemandRideStatusLogRecordCompleted = 9,
    HereSDKDemandRideStatusLogRecordCancelled = 10,
};

NS_ASSUME_NONNULL_BEGIN

/**
 A ride status log record, containing a status value and a timestamp
 */
@interface HereSDKDemandRideStatusUpdate : NSObject

/** The current status of the ride */
@property(nonatomic, readonly) HereSDKDemandRideStatusUpdateStatus status;

/** The time the ride status was updated */
@property(nonatomic, readonly, copy) NSDate *timestamp;

/**
 Returns a text description of the ride status

 @param status The status of the ride

 @return The text description of the status
 */
+ (NSString*)recordStatusToString:(HereSDKDemandRideStatusUpdateStatus)status;

@end

NS_ASSUME_NONNULL_END
