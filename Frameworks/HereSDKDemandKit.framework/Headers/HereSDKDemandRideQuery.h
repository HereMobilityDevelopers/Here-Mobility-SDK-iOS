//
 /***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Type definition for ride statuses

 - HereSDKDemandRideQueryStatusUnknown: status Unknown
 - HereSDKDemandRideQueryStatusPast:    status Past rides (COMPLETED, REJECTED or CANCELLED)
 - HereSDKDemandRideQueryStatusFuture:  status Rides that were prebooked
 - HereSDKDemandRideQueryStatusOngoing: status Ongoing rides
 - HereSDKDemandRideQueryStatusAll:     status All rides
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandRideQueryStatusFilter) {
    HereSDKDemandRideQueryStatusUnknown = 0,
    HereSDKDemandRideQueryStatusPast    = 1,
    HereSDKDemandRideQueryStatusFuture  = 2,
    HereSDKDemandRideQueryStatusOngoing = 3,
    HereSDKDemandRideQueryStatusAll     = 4,
};

/**
 Sorting ride results by update or created time

 - HereSDKDemandRideQuerySortTypeUnknown: sorting type Unknown
 - HereSDKDemandRideQuerySortTypeUpdateTimeAsc: sorting type by update (ascending)
 - HereSDKDemandRideQuerySortTypeUpdateTimeDesc: sorting type by update (descending)
 - HereSDKDemandRideQuerySortTypeCreateTimeAsc: sorting type by created (ascending)
 - HereSDKDemandRideQuerySortTypeCreateTimeDesc: sorting type by created (descending)
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandRideQuerySortType) {
    HereSDKDemandRideQuerySortTypeUnknown = 0,
    HereSDKDemandRideQuerySortTypeUpdateTimeAsc = 1,
    HereSDKDemandRideQuerySortTypeUpdateTimeDesc = 2,
    HereSDKDemandRideQuerySortTypeCreateTimeAsc = 3,
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
