/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import "HereSDKDemandRide.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A response to a query for rides by status and update time.
 */
@interface HereSDKDemandQueryRidesResponse : NSObject

/**
 The list of rides.
 */
@property(nonatomic, readonly) NSArray<HereSDKDemandRide *> *ridesArray;

/**
 The earliest update time in the result set.
 */
@property(nonatomic, readonly) NSDate *fromUpdateTime;

/**
 The latest update time in the result set.
 */
@property(nonatomic, readonly) NSDate *toUpdateTime;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
