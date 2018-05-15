/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKDemandKit/HereSDKDemandPrice.h>
#import <HereSDKDemandKit/HereSDKDemandPriceRange.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class containing a price estimate for a ride.
 The estimate can be either a single fixed price or a price range.
 */
@interface HereSDKDemandPriceEstimate : NSObject

/** A fixed price estimate */
@property (nonatomic, readonly, nullable) HereSDKDemandPrice *fixed;

/**  A price range estimate */
@property (nonatomic, readonly, nullable) HereSDKDemandPriceRange *range;

@end

NS_ASSUME_NONNULL_END
