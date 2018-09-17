//
/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKDemandKit/HereSDKDemandRideOfferProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface HereSDKDemandVerticalsCoverageResponse : NSObject

@property (nonatomic, readonly) HereSDKDemandTransitType transitTypeMask;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
