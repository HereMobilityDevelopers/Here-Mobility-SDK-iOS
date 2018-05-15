/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKDemandKit/HereSDKDemandLocation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A ride route
 */
@interface HereSDKDemandRoute : NSObject

/** The route's start point */
@property (nonatomic) HereSDKDemandLocation *pickup;

/** The route's end point */
@property (nonatomic) HereSDKDemandLocation *destination;

- (instancetype)initWithPickupLocation:(HereSDKDemandLocation *)pickup
                   destinationLocation:(HereSDKDemandLocation *)destination;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
