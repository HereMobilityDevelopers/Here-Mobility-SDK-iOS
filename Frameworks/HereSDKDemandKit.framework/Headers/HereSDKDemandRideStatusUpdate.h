/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Type definition for ride statuses
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandRideStatusUpdateStatus)
{
    /** Unknown */
    HereSDKDemandRideStatusLogRecordUnknown = 0,
    /** The request is being processed, looking for a supplier. */
    HereSDKDemandRideStatusLogRecordProcessing = 1,
    /** None of the suppliers accepted the offer. No driver was assigned. */
    HereSDKDemandRideStatusLogRecordRejected = 2,
    /** A supplier accepted the ride, no driver was assigned yet. */
    HereSDKDemandRideStatusLogRecordAccepted = 3,
    /** A driver was assigned to the ride. */
    HereSDKDemandRideStatusLogRecordDriverAssigned = 4,
    /** The vehicle is on the way to the pickup point. */
    HereSDKDemandRideStatusLogRecordDriverEnRoute = 5,
    /** The vehicle is waiting at the pickup point. */
    HereSDKDemandRideStatusLogRecordDriverAtPickup = 6,
    /** The vehicle is on the way to the drop-off point. */
    HereSDKDemandRideStatusLogRecordPassengerOnBoard = 7,
    /** The vehicle arrived at the drop-off point. */
    HereSDKDemandRideStatusLogRecordDriverAtDropoff = 8,
    /** The ride was completed. */
    HereSDKDemandRideStatusLogRecordCompleted = 9,
    /** The ride was cancelled (either by the driver or by the passenger). */
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
