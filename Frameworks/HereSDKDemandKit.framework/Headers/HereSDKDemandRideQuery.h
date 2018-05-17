/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Type definition for ride statuses
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandRideQueryStatusFilter) {
    /** Ride status filter: Unknown */
    HereSDKDemandRideQueryStatusUnknown = 0,
    /** Ride status filter: Past rides (COMPLETED, REJECTED or CANCELLED) */
    HereSDKDemandRideQueryStatusPast    = 1,
    /** Ride status filter: Rides that were prebooked */
    HereSDKDemandRideQueryStatusFuture  = 2,
    /** Ride status filter: Ongoing rides */
    HereSDKDemandRideQueryStatusOngoing = 3,
    /** Ride status filter: All rides */
    HereSDKDemandRideQueryStatusAll     = 4,
};

/**
 Sorting ride results by update or created time
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandRideQuerySortType) {
    /** Ride sorting type: Unknown */
    HereSDKDemandRideQuerySortTypeUnknown = 0,
    /** Ride sorting type: by update time (ascending) */
    HereSDKDemandRideQuerySortTypeUpdateTimeAsc = 1,
    /** Ride sorting type: by update time (descending) */
    HereSDKDemandRideQuerySortTypeUpdateTimeDesc = 2,
    /** Ride sorting type: by created time (ascending) */
    HereSDKDemandRideQuerySortTypeCreateTimeAsc = 3,
    /** Ride sorting type: by created time (descending) */
    HereSDKDemandRideQuerySortTypeCreateTimeDesc = 4,
};

NS_ASSUME_NONNULL_BEGIN

/**
 A class passed for getRides request
 */
@interface HereSDKDemandRideQuery : NSObject

/** Return only rides updated AFTER this time */
@property (nonatomic, readonly, nullable) NSDate *fromUpdateTime;

/** The maximum number of rides to return (default is 200)*/
@property (nonatomic, readonly) uint32_t limit;

/** A filter on the ride status. When not set, defaults to "all rides" */
@property (nonatomic, readonly) HereSDKDemandRideQueryStatusFilter statusFilter;

/** Sorting ride results algorithm */
@property (nonatomic, readonly) HereSDKDemandRideQuerySortType sortBy;


/**
 Creates a 'HereSDKDemandRideQuery' instance.

 @param updateTime The time from which rides were updated
 @param limit The Number of rides returned
 @param statusFilter The filter on the ride status
 @param sortBy Sorting ride results algorithm

 @return a new 'HereSDKDemandRideQuery' instance
 */
+ (instancetype)rideQueryWithUpdateTime:(NSDate *_Nullable)updateTime limit:(uint32_t)limit statusFilter:(HereSDKDemandRideQueryStatusFilter)statusFilter sortBy:(HereSDKDemandRideQuerySortType)sortBy;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
