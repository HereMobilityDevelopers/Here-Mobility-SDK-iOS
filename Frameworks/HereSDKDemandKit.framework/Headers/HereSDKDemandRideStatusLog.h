/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import "HereSDKDemandRideStatusUpdate.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Ride status log
 */
@interface HereSDKDemandRideStatusLog : NSObject

/** Last time this object was updated. Used for tracking updates */
@property (nonatomic, readonly) NSDate *lastUpdateTime;

/** The time the booking was created */
@property (nonatomic, readonly) NSDate *createTime;

/** The time the ride was closed */
@property (nonatomic, readonly, nullable) NSDate *closedTime;

/** If TRUE, there are updates on the RideLocation entity */
@property (nonatomic, readonly) BOOL isRideLocationAvailable;

/** The ride's current status */
@property (nonatomic, readonly) HereSDKDemandRideStatusUpdateStatus currentStatus;

/** The reason for the ride's current status */
@property (nonatomic, readonly) HereSDKDemandRideStatusUpdateStatusReason currentStatusReason;

/** Previous ride statuses, in descending their timestamp */
@property (nonatomic, readonly) NSArray<HereSDKDemandRideStatusUpdate*> *prevStatusesArray;

/** Number of statuses in prevStatusesArray */
@property (nonatomic, readonly) NSUInteger prevStatusesArrayCount DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use `-prevStatusesArray.count` instead.");

@end

NS_ASSUME_NONNULL_END
